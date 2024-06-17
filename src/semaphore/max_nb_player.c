/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_nb_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:08:36 by brda-sil          #+#    #+#             */
/*   Updated: 2024/06/17 10:45:58 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern	t_lem_ipc_mem	*LEM_IPC_MEM;
extern	t_lem_ipc_sem	LEM_IPC_SEM;

t_lem_player_id	inc_max_nb_player(void)
{
	t_lem_player_id	max_nb_player;

	sem_wait(LEM_IPC_SEM.max_nb_player);
	max_nb_player = ++LEM_IPC_MEM->max_nb_player;
	sem_post(LEM_IPC_SEM.max_nb_player);
	return (max_nb_player);
}

t_lem_player_id get_max_nb_player(void)
{
	t_lem_player_id	max_nb_player;

	sem_wait(LEM_IPC_SEM.max_nb_player);
	max_nb_player = LEM_IPC_MEM->max_nb_player;
	sem_post(LEM_IPC_SEM.max_nb_player);
	return (max_nb_player);
}
