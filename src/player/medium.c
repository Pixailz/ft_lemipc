/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:30:56 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/30 13:11:49 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern t_pos			POS;
extern t_lem_team_id	TEAM_ID;

static int	get_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static t_vec	compute_move(t_tile *board)
{
	t_vec	nearest_enemy;
	t_vec	nearest_ally;
	t_vec	dir;

	nearest_enemy.dir = (t_pos){0, 0};
	nearest_enemy.pos = get_nearest_player(board, 1);
	if (nearest_enemy.pos.x == -1 && nearest_enemy.pos.y == -1)
	{
		ft_printf("(%02d,%02d) NO ENEMY FOUND\n", POS.x, POS.y);
		return (nearest_enemy);
	}
	nearest_enemy.dir.x = nearest_enemy.pos.x - POS.x;
	nearest_enemy.dir.y = nearest_enemy.pos.y - POS.y;
	ft_printf("(%02d,%02d) ENEMY FOUND\n", nearest_enemy.pos.x, nearest_enemy.pos.y);

	nearest_ally.dir = (t_pos){0, 0};
	nearest_ally.pos = get_nearest_player(board, 0);
	if (nearest_ally.pos.x == -1 && nearest_ally.pos.y == -1)
	{
		ft_printf("(%02d,%02d) NO ALLY FOUND\n", POS.x, POS.y);
		return (nearest_enemy);
	}
	nearest_ally.dir.x = nearest_ally.pos.x - POS.x;
	nearest_ally.dir.y = nearest_ally.pos.y - POS.y;
	ft_printf("(%02d,%02d) ALLY FOUND\n", nearest_ally.pos.x, nearest_ally.pos.y);
	dir.pos.x = get_abs(nearest_ally.dir.x) + get_abs(nearest_ally.dir.y);
	dir.pos.y = get_abs(nearest_enemy.dir.x) + get_abs(nearest_enemy.dir.y);
	dir.dir.x = dir.pos.x - dir.pos.y;
	if (dir.pos.x > 3)
		return (nearest_ally);
	return (nearest_enemy);
}

static void	computed_move(t_vec next_move)
{
	t_pos	tmp;

	if (next_move.dir.x == 0 && next_move.dir.y == 0)
	{
		random_move();
		return ;
	}
	tmp.x = get_abs(next_move.dir.x);
	tmp.y = get_abs(next_move.dir.y);
	if (tmp.x > tmp.y)
	{
		if (next_move.dir.x > 0)
			move_player(RIGHT);
		else if (next_move.dir.x < 0)
			move_player(LEFT);
	}
	else
	{
		if (next_move.dir.y > 0)
			move_player(DOWN);
		else if (next_move.dir.y < 0)
			move_player(UP);
	}
}

void	loop_medium(void)
{
	computed_move(compute_move(get_board()));
}
