/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 08:06:04 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/01 15:42:27 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern	void*	MLX;
extern	void*	WIN;

extern	t_pos	ORIGIN_LOG;
extern	t_pos	LEM_IPC_LOG_WIDTH;

void	update_index_new_line(t_pos *pos)
{

	if (
		MLX_FONT_SPACING_X + (
			MLX_FONT_UNIT_X * (pos->x + LEM_IPC_LEN_TOTAL + 1)
		) > LEM_IPC_LOG_WIDTH.x
	)
	{
		pos->x = 0;
		pos->y++;
	}
}

void	mlxput_text_at(char *msg, int color, t_pos pos, t_bool inv_y)
{
	pos.x *= MLX_FONT_UNIT_X;
	pos.x += ORIGIN_LOG.x + MLX_FONT_SPACING_X + 1;
	pos.y *= MLX_FONT_UNIT_Y;
	pos.y += MLX_FONT_SPACING_Y + 1;
	if (inv_y)
		pos.y = (ORIGIN_LOG.y + LEM_IPC_LOG_WIDTH.y) - pos.y;
	else
		pos.y += ORIGIN_LOG.y;
	mlx_string_put(MLX, WIN, pos.x, pos.y, color, msg);
}