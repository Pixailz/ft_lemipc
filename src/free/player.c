/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:05:08 by brda-sil          #+#    #+#             */
/*   Updated: 2024/06/17 11:10:09 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern t_pos			POS;

void	free_player(void)
{
	t_lem_player_id	nb_player;

	dec_nb_player();
	set_board(POS, (t_tile){0, 0});
	nb_player = get_nb_player();
	ft_printf("FREE: nb_player = %d\n", nb_player);
	if (!nb_player)
	{
		sem_unlink("/nb_player");
		sem_unlink("/board");
		sem_unlink("/pause");
		sem_unlink("/max_nb_player");
		shm_unlink(SHO_MEM_KEY);
	}
}
