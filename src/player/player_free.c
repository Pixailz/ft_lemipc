/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:05:08 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/01 19:44:49 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern t_pos			POS;
extern t_lem_ipc_mem	*LEM_IPC_MEM;

void	free_player(void)
{
	t_lem_player_id	player_nb;

	if (LEM_IPC_MEM == FT_NULL)
		return ;
	dec_player_nb();
	set_board(POS, (t_tile){0, 0});
	player_nb = get_player_nb();
	ft_printf("FREE: player_nb = %d\n", player_nb);
	if (!player_nb)
	{
		unlink_sems();
		unlink_msqs();
		shm_unlink(SHO_MEM_KEY);
	}
}
