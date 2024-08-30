/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:01:24 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/30 10:41:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

t_lem_ipc_sem	LEM_IPC_SEM = {
	.nb_player = 0,
	.board = 0,
	.pause = 0,
	.max_nb_player = 0
};
extern t_bool	IS_MANAGED;

t_error	init_semaphore(sem_t **sem, char *name, int value)
{
	t_int32		sem_value;

	errno = 0;
	if ((*sem = sem_open(name, O_CREAT, 0666, value)) == SEM_FAILED)
	{
		if (errno == EEXIST)
		{
			ft_printf("sem_init: %s already exist\n", name);
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
	ft_printf("sem_init: succeed /dev/shm/sem.%s (%d)\n", name + 1, sem_value);
	return (SUCCESS);
}

char	*get_semaphore_key(char *key)
{
	static char	buff[0xff];

	buff[ft_sprintf(buff, "/%s-%s", SHO_SEM_KEY, key)] = 0;
	return (buff);
}

t_error	init_semaphores(void)
{
	t_error	ret;

	if ((ret = init_semaphore(
			&LEM_IPC_SEM.nb_player,
			get_semaphore_key("nb_player"),
			1
		)))
		return (ret);
	if ((ret = init_semaphore(
			&LEM_IPC_SEM.board,
			get_semaphore_key("board"),
			1
		)))
		return (ret);
	if ((ret = init_semaphore(
			&LEM_IPC_SEM.pause,
			get_semaphore_key("pause"),
			1
		)))
		return (ret);
	if ((ret = init_semaphore(
			&LEM_IPC_SEM.max_nb_player,
			get_semaphore_key("max_nb_player"),
			1
		)))
		return (ret);
	return (SUCCESS);
}
