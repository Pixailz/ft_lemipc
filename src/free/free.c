/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:04:17 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/28 22:28:48 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern	t_bool			IS_GRAPHICAL;
extern	t_bool			IS_GRAPHICAL_TEXT;
extern t_lem_ipc_sem	LEM_IPC_SEM;

void	free_prog(void)
{
	if (IS_GRAPHICAL)
	{
		if (!IS_GRAPHICAL_TEXT)
			free_mlx();
	}
	else
		free_player();
	close_semaphores();
	close_message_queues();
}
