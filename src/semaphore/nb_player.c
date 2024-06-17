/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:08:36 by brda-sil          #+#    #+#             */
/*   Updated: 2024/06/16 17:16:07 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern	t_lem_ipc_mem	*LEM_IPC_MEM;
extern	t_lem_ipc_sem	LEM_IPC_SEM;

t_lem_player_id	inc_nb_player(void)
{
	t_lem_player_id	nb_player;

	sem_wait(LEM_IPC_SEM.nb_player);
	nb_player = ++LEM_IPC_MEM->nb_player;
	sem_post(LEM_IPC_SEM.nb_player);
	return (nb_player);
}

t_lem_player_id dec_nb_player(void)
{
	t_lem_player_id	nb_player;

	sem_wait(LEM_IPC_SEM.nb_player);
	nb_player = --LEM_IPC_MEM->nb_player;
	sem_post(LEM_IPC_SEM.nb_player);
	return (nb_player);
}

t_lem_player_id get_nb_player(void)
{
	t_lem_player_id	nb_player;

	sem_wait(LEM_IPC_SEM.nb_player);
	nb_player = LEM_IPC_MEM->nb_player;
	sem_post(LEM_IPC_SEM.nb_player);
	return (nb_player);
}
