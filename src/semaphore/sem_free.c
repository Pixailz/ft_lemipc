/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:35:16 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/31 17:41:37 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern t_lem_ipc_sem	LEM_IPC_SEM;

void	close_sems(void)
{
	sem_close(LEM_IPC_SEM.player_nb);
	sem_close(LEM_IPC_SEM.board);
	sem_close(LEM_IPC_SEM.pause);
	sem_close(LEM_IPC_SEM.max_player_nb);
}

void	unlink_sems(void)
{
	sem_unlink(get_sem_key("player_nb"));
	sem_unlink(get_sem_key("board"));
	sem_unlink(get_sem_key("pause"));
	sem_unlink(get_sem_key("max_player_nb"));
}