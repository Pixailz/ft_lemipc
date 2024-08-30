/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:35:16 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/28 22:32:48 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern t_lem_ipc_sem	LEM_IPC_SEM;

void	close_semaphores(void)
{
	sem_close(LEM_IPC_SEM.nb_player);
	sem_close(LEM_IPC_SEM.board);
	sem_close(LEM_IPC_SEM.pause);
	sem_close(LEM_IPC_SEM.max_nb_player);
}

void	unlink_semaphores(void)
{
	sem_unlink(get_semaphore_key("nb_player"));
	sem_unlink(get_semaphore_key("board"));
	sem_unlink(get_semaphore_key("pause"));
	sem_unlink(get_semaphore_key("max_nb_player"));
}