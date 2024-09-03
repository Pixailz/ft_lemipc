/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pause.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:57:46 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/02 21:55:42 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern	t_lem_ipc_sem	LEM_IPC_SEM;

# define PAUSE_HEADER	"[PAUSE]: "
# define PAUSE_ENABLE	"paused"
# define PAUSE_DISABLE	"not paused"

t_bool	IS_PAUSED = FALSE;

void	lemipc_check_pause(void)
{
	sem_wait(LEM_IPC_SEM.pause);
	sem_post(LEM_IPC_SEM.pause);
}

void	lemipc_pause_toggle(void)
{
	t_int32		sem_value;

	sem_getvalue(LEM_IPC_SEM.pause, &sem_value);
	print_mlx_log(
		PAUSE_HEADER "Waiting for %s",
		sem_value ? PAUSE_ENABLE : PAUSE_DISABLE
	);
	if (sem_value)
	{
		sem_wait(LEM_IPC_SEM.pause);
		IS_PAUSED = TRUE;
	}
	else
	{
		sem_post(LEM_IPC_SEM.pause);
		IS_PAUSED = FALSE;
	}
	print_mlx_log(
		PAUSE_HEADER "Now %s",
		IS_PAUSED ? PAUSE_ENABLE : PAUSE_DISABLE
	);
}

void	lemipc_pause_set(t_bool target)
{
	t_int32		sem_value;

	sem_getvalue(LEM_IPC_SEM.pause, &sem_value);
	if (target && sem_value)
		sem_wait(LEM_IPC_SEM.pause);
	else if (!target && !sem_value)
		sem_post(LEM_IPC_SEM.pause);
}