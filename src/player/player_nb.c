/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_nb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:08:36 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/31 17:41:37 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern	t_lem_ipc_mem	*LEM_IPC_MEM;
extern	t_lem_ipc_sem	LEM_IPC_SEM;

t_lem_player_id	inc_player_nb(void)
{
	t_lem_player_id	player_nb;

	sem_wait(LEM_IPC_SEM.player_nb);
	player_nb = ++LEM_IPC_MEM->player_nb;
	sem_post(LEM_IPC_SEM.player_nb);
	return (player_nb);
}

t_lem_player_id dec_player_nb(void)
{
	t_lem_player_id	player_nb;

	sem_wait(LEM_IPC_SEM.player_nb);
	player_nb = --LEM_IPC_MEM->player_nb;
	sem_post(LEM_IPC_SEM.player_nb);
	return (player_nb);
}

t_lem_player_id get_player_nb(void)
{
	t_lem_player_id	player_nb;

	sem_wait(LEM_IPC_SEM.player_nb);
	player_nb = LEM_IPC_MEM->player_nb;
	sem_post(LEM_IPC_SEM.player_nb);
	return (player_nb);
}
