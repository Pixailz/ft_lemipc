/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:01:24 by brda-sil          #+#    #+#             */
/*   Updated: 2024/06/17 11:12:16 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

t_lem_ipc_sem	LEM_IPC_SEM = {0};
extern t_bool	IS_MANAGED;

t_error	init_semaphore(sem_t **sem, char *name, int value)
{
	t_int32		sem_value;

	errno = 0;
	if ((*sem = sem_open(name, O_CREAT, 0666, value)) == SEM_FAILED)
	{
		if (errno == EEXIST)
		{
			if ((*sem = sem_open(name, 0666)) == SEM_FAILED)
			{
				ft_perr("sem_init: failed to open %s\n", name);
				return (ERR_SEM_INIT);
			}
		}
		else
			return (ERR_SEM_INIT);
	}
	sem_getvalue(*sem, &sem_value);
	ft_printf("sem_init: succeed %s (%d)\n", name, sem_value);
	return (SUCCESS);
}

t_error	init_semaphores(void)
{
	t_error	ret;

	if ((ret = init_semaphore(&LEM_IPC_SEM.nb_player, "/nb_player", 1)))
		return (ret);
	if ((ret = init_semaphore(&LEM_IPC_SEM.board, "/board", 1)))
		return (ret);
	if ((ret = init_semaphore(&LEM_IPC_SEM.pause, "/pause", 1)))
		return (ret);
	if ((ret = init_semaphore(&LEM_IPC_SEM.max_nb_player, "/max_nb_player", 1)))
		return (ret);
	return (SUCCESS);
}
