/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:35:16 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/27 14:28:21 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern	t_lem_ipc_mem	*LEM_IPC_MEM;
extern	t_lem_ipc_sem	LEM_IPC_SEM;

t_lem_ipc_mem	get_mem(void)
{
	t_lem_ipc_mem	mem;

	sem_wait(LEM_IPC_SEM.board);
	mem = *LEM_IPC_MEM;
	sem_post(LEM_IPC_SEM.board);
	return (mem);
}

t_tile	*get_board(void)
{
	return (get_mem().board);
}

void	set_board(t_pos pos, t_tile tile)
{
	sem_wait(LEM_IPC_SEM.board);
	LEM_IPC_MEM->board[pos.x + (pos.y * LEM_IPC_BOARD_LEN_X)] = tile;
	sem_post(LEM_IPC_SEM.board);
}
