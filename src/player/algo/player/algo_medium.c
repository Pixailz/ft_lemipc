/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:30:56 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/01 19:33:44 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern t_pos	POS;

t_vec	handler_move_medium(t_tile *board)
{
	t_vec	enemy;
	t_vec	ally;

	enemy = handler_move_easy(board);
	ally = compute_nearest_ally(board);
	if (ally.pos.x == -1 && ally.pos.y == -1)
	{
		ft_pdeb("NO ALLY FOUND\n", POS.x, POS.y);
		return (ally);
	}
	ft_pdeb("(%02d,%02d) ALLY FOUND\n", ally.pos.x, ally.pos.y);
	return (compute_choose_enemy_ally(enemy, ally));
}

void	loop_medium(void)
{
	computed_move(handler_move_medium(get_board()));
}
