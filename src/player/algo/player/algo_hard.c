/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_hard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:30:56 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/03 10:20:46 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern t_pos	POS;


t_player_status	PLAYER_STATUS = -1;
t_lem_player_id	LEADER_ID = -1;

t_vec	handler_move_hard(t_tile *board)
{
	t_vec		ally;
	t_vec		enemy;
	t_msq_atk	*msg;
	t_msq_hdr	*msg_hdr;

	msg = FT_NULL;
	if (PLAYER_STATUS == STATUS_UNKNOWN)
	{
		msg = msq_get_nearest_attack();
		if (msg == FT_NULL)
			PLAYER_STATUS = STATUS_LEADER;
		else
		{
			msg_hdr = msq_get_header();
			LEADER_ID = msg_hdr->player_id;
			PLAYER_STATUS = STATUS_FOLLOWER;
		}
	}
	if (PLAYER_STATUS == STATUS_LEADER)
	{
		msq_remove_all(MSQ_TYPE_ATK);
		// msq_remove_last(MSQ_TYPE_ATK);
		enemy = compute_nearest_enemy(board);
		ally = compute_nearest_ally(board);
		if (enemy.pos.x == -1 && enemy.pos.y == -1)
		{
			// PLAYER_STATUS = STATUS_UNKNOWN;
		}
		else
			msq_send_attack(enemy.pos);

		return (enemy);
	}
	else
	{
		if (msg == FT_NULL)
			msg = msq_get_attack_by_id(LEADER_ID);
			// msg = msq_get_nearest_attack();
		if (msg == FT_NULL)
		{
			PLAYER_STATUS = STATUS_UNKNOWN;
			LEADER_ID = -1;
			return ((t_vec){{0, 0}, {0, 0}});
		}
		else if (msg->target.x == -1 && msg->target.y == -1)
		{
			ally.pos = msg->leader;
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
