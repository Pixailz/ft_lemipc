/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:20:46 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/31 17:52:40 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

void	put_cell(t_pos pos, t_lem_team_id team_id, t_mlx_texture *scene)
{
	t_pos	ppos;
	t_int4	color;

	ppos.y = (pos.y * CELL_SIZE) + 1;
	color = mlx_get_team_color(team_id);
	while (ppos.y < (pos.y + 1) * CELL_SIZE)
	{
		ppos.x = (pos.x * CELL_SIZE) + 1;
		while (ppos.x < (pos.x + 1) * CELL_SIZE)
		{
			ft_put_pixel(ppos, scene, color);
			ppos.x++;
		}
		ppos.y++;
	}
}