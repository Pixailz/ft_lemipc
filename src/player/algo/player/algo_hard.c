/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_hard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:30:56 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/02 00:23:36 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern t_pos	POS;

typedef enum e_player_status
{
	STATUS_UNKNOWN = -1,
	STATUS_LEADER = 1,
	STATUS_FOLLOWER = 2,
}	t_player_status;

t_player_status	PLAYER_STATUS = -1;

t_vec	handler_move_hard(t_tile *board)
{
	t_vec		ally;
	t_vec		enemy;
	t_vec		dir;
	t_msq_atk	*msg;

	if (PLAYER_STATUS == STATUS_UNKNOWN)
	{
		msg = msq_get_nearest_attack();
		if (msg == FT_NULL)
		{
			PLAYER_STATUS = STATUS_LEADER;
			enemy = compute_nearest_enemy(board);
		}
		else
			PLAYER_STATUS = STATUS_FOLLOWER;
	}

	if (PLAYER_STATUS == STATUS_LEADER)
	{
		msq_remove_last_pos();
		enemy = compute_nearest_enemy(board);
		ally = compute_nearest_ally(board);
		dir = compute_choose_enemy_ally(enemy, ally);
		if (enemy.pos.x == -1 && enemy.pos.y == -1)
			PLAYER_STATUS = STATUS_FOLLOWER;
		else
			msq_send_attack(enemy.pos);
		return (dir);
	}
	else
	{
		if (msg->target.x == -1 && msg->target.y == -1)
		{
			ally.pos = msg->attacker;
			ally.dir.x = ally.pos.x - POS.x;
			ally.dir.y = ally.pos.y - POS.y;
			return (ally);
		}
		else
		{
			enemy.pos = msg->target;
			enemy.dir.x = enemy.pos.x - POS.x;
			enemy.dir.y = enemy.pos.y - POS.y;
			return (enemy);
		}
	}
}

void	loop_hard(void)
{
	computed_move(handler_move_hard(get_board()));
}
