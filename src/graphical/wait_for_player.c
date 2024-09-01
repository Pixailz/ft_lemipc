/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:35:15 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/01 19:44:49 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern t_bool		IS_SIGINT;

int	wait_for_player(char *name, t_uint32 oflag, t_uint32 perm)
{
	int	sho_fd;

	sho_fd = -1;
	print_mlx_log("Waiting for players");
	while (sho_fd == -1)
	{
		if (IS_SIGINT)
			return (-1);
		usleep(A_SEC / 10);
		sho_fd = shm_open(name, oflag, perm);
	}
	print_mlx_log("Player(s) has arrived");
	return (sho_fd);
}

// t_bool	wait_for_player_2(void)
// {
// 	if (is_player_here())
// 	{
// 		print_mlx_log("Player has arrived");
// 		return TRUE;
// 	}
// 	close_sems();
// 	close_msqs();
// 	while (!IS_SIGINT && !is_player_here())
// 		usleep(A_SEC / 3);
// 	return FALSE;
// }