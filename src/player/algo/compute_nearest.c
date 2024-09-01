/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_nearest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:30:56 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/01 16:42:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern t_pos	POS;

t_vec	compute_nearest_player(t_tile *board, int mode)
{
	t_vec vec;

	vec.dir.x = 0;
	vec.dir.y = 0;
	vec.pos = get_nearest_player(board, mode);
	if (vec.pos.x == -1 && vec.pos.y == -1)
		return (vec);
	vec.dir.x = vec.pos.x - POS.x;
	vec.dir.y = vec.pos.y - POS.y;
	return (vec);
}

t_vec	compute_nearest_ally(t_tile *board)
{
	return (compute_nearest_player(board, 0));
}

t_vec	compute_nearest_enemy(t_tile *board)
{
	return (compute_nearest_player(board, 1));
}