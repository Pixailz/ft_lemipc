/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:30:56 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/01 19:34:07 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern t_pos	POS;

void	computed_move(t_vec next_move)
{
	t_pos	tmp;

	if (next_move.dir.x == 0 && next_move.dir.y == 0)
	{
		random_move();
		return ;
	}
	tmp.x = ft_get_abs(next_move.dir.x);
	tmp.y = ft_get_abs(next_move.dir.y);
	if (tmp.x > tmp.y)
	{
		if (next_move.dir.x > 0)
			ensure_player_move(RIGHT);
		else if (next_move.dir.x < 0)
			ensure_player_move(LEFT);
	}
	else
	{
		if (next_move.dir.y > 0)
			ensure_player_move(DOWN);
		else if (next_move.dir.y < 0)
			ensure_player_move(UP);
	}
}