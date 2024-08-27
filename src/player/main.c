/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:30:56 by brda-sil          #+#    #+#             */
/*   Updated: 2024/06/17 13:49:38 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern t_ai_id	AI_ID;
extern t_bool 	IS_SIGINT;
extern t_bool 	IS_DEAD;

t_bool	player_loop(void)
{
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
