/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pix <pix@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:04:17 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/28 14:06:16 by pix              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern t_bool			IS_GRAPHICAL;
extern t_bool			IS_GRAPHICAL_TEXT;
extern t_lem_ipc_sem	LEM_IPC_SEM;
extern t_lem_ipc_mem	*LEM_IPC_MEM;

void	free_prog(void)
{
	if (IS_GRAPHICAL)
	{
		if (!IS_GRAPHICAL_TEXT)
			free_mlx();
	}
	else
		free_player();
	close_sems();
	close_msqs();
	munmap(LEM_IPC_MEM, SHO_MEM_SIZE);
}
