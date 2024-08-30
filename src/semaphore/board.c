/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:35:16 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/29 00:53:26 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern	t_lem_ipc_mem	*LEM_IPC_MEM;
extern	t_lem_ipc_sem	LEM_IPC_SEM;

t_tile	*get_board(void)
{
	t_tile	*board;

	sem_wait(LEM_IPC_SEM.board);
	board = LEM_IPC_MEM->board;
	sem_post(LEM_IPC_SEM.board);
	return (board);
}

void	set_board(t_pos pos, t_tile tile)
{
	sem_wait(LEM_IPC_SEM.board);
	LEM_IPC_MEM->board[pos.x + (pos.y * LEM_IPC_BOARD_LEN_X)] = tile;
	sem_post(LEM_IPC_SEM.board);
}

void	set_board_move(t_pos from, t_pos to, t_tile tile)
{
	sem_wait(LEM_IPC_SEM.board);
	LEM_IPC_MEM->board[from.x + (from.y * LEM_IPC_BOARD_LEN_X)] = (t_tile){0, 0};
	LEM_IPC_MEM->board[to.x + (to.y * LEM_IPC_BOARD_LEN_X)] = tile;
	sem_post(LEM_IPC_SEM.board);
}
