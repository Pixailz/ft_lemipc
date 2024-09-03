/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_run_wrapper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:30:56 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/02 22:22:04 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern t_algo_id			AI_ID;
extern t_bool 				IS_SIGINT;
extern t_bool 				IS_DEAD;
extern t_str_algo_func_node	AI_ID_LIST[NB_ALGO];

t_bool	player_loop(void)
{
	usleep(LEM_IPC_FREQ);
	lemipc_check_pause();
	return (!IS_SIGINT && !IS_DEAD);
}

t_error	run_player(void)
{
	t_algo_func func;

	func = AI_ID_LIST[AI_ID].func;
	while (player_loop())
		func();
	msq_remove_last(MSQ_TYPE_ATK);
	return (SUCCESS);
}
