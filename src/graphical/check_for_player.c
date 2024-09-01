/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:20:46 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/01 19:44:49 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern t_bool			IS_SIGINT;

void	check_for_player(void)
{
	if (!get_player_nb())
	{
		init_shm();
		if (!IS_SIGINT)
		{
			close_sems();
			close_msqs();
			init_sems();
			init_msqs_graphical();
		}
	}
}
