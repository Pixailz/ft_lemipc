/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:30:56 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/28 22:54:26 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern t_ai_id	AI_ID;
extern t_bool 	IS_SIGINT;
extern t_bool 	IS_DEAD;

t_bool	player_loop(void)
{
	usleep(LEM_IPC_FREQ);
	lemipc_check_pause();
	return (!IS_SIGINT && !IS_DEAD);
}

t_error	run_player(void)
{
	switch (AI_ID)
	{
		case (RANDOM):
			loop_random(); break ;
		case (LOW):
			loop_low(); break ;
	}
	return (SUCCESS);
}
