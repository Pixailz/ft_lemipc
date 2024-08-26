/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:29:30 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/25 07:02:22 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern void				*MLX;
extern t_pos			LEM_IPC_SCREEN;
extern t_mlx_texture	SCENE_BOARD;

void	fill_board(t_tile *board)
{
	t_pos			pos;

	pos.y = 0;
	while (pos.y < LEM_IPC_BOARD_LEN_Y)
	{
		pos.x = 0;
		while (pos.x < LEM_IPC_BOARD_LEN_X)
		{
			put_cell(
				pos,
				board[pos.x + pos.y * LEM_IPC_BOARD_LEN_X].team_id,
				&SCENE_BOARD
			);
			pos.x++;
		}
		pos.y++;
	}
}
