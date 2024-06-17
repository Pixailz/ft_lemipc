/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pause.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:57:46 by brda-sil          #+#    #+#             */
/*   Updated: 2024/06/16 18:17:05 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern	t_lem_ipc_sem	LEM_IPC_SEM;

t_bool	IS_PAUSED = FALSE;

void	lemipc_check_pause(void)
{
	sem_wait(LEM_IPC_SEM.pause);
	sem_post(LEM_IPC_SEM.pause);
}

void	lemipc_pause_toggle(void)
{
	t_int32		sem_value;

	if (IS_PAUSED)
	{
		sem_post(LEM_IPC_SEM.pause);
		IS_PAUSED = FALSE;
	}
	else
	{
		sem_wait(LEM_IPC_SEM.pause);
		IS_PAUSED = TRUE;
	}
	ft_printf("IS_PAUSED %d\n", IS_PAUSED);
	sem_getvalue(LEM_IPC_SEM.pause, &sem_value);
	ft_printf("PAUSE LEM_IPC_SEM VALUE %d\n", sem_value);
}
