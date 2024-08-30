/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:05:08 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/29 02:03:39 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern t_pos			POS;
extern t_lem_ipc_mem	*LEM_IPC_MEM;

void	free_player(void)
{
	t_lem_player_id	nb_player;

	if (LEM_IPC_MEM == FT_NULL)
		return ;
	dec_nb_player();
	set_board(POS, (t_tile){0, 0});
	nb_player = get_nb_player();
	ft_printf("FREE: nb_player = %d\n", nb_player);
	if (!nb_player)
	{
		unlink_semaphores();
		unlink_message_queues();
		shm_unlink(SHO_MEM_KEY);
	}
}
