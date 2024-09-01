/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_easy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:30:56 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/01 19:25:53 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern t_pos	POS;

t_vec	handler_move_easy(t_tile *board)
{
	t_vec enemy;

	enemy = compute_nearest_enemy(board);
	if (enemy.pos.x == -1 && enemy.pos.y == -1)
	{
		ft_pdeb("(%02d,%02d) NO ENEMY FOUND\n", POS.x, POS.y);
		return (enemy);
	}
	ft_pdeb("(%02d,%02d) ENEMY FOUND\n", enemy.pos.x, enemy.pos.y);
	return (enemy);
}

void	loop_easy(void)
{
	computed_move(handler_move_easy(get_board()));
}
