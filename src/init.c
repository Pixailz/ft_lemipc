/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:00:58 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 15:12:50 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern	t_bool			IS_GRAPHICAL;
extern	t_lem_player_id	MY_ID;
extern	t_algo_id		AI_ID;

t_lemipc_error	init_prog(void)
{
	t_lemipc_error	ret;

	if ((ret = init_signal()))
		return (ret);
	if ((ret = init_shm()))
		return (ret);
	if ((ret = init_sems()))
		return (ret);
	if (IS_GRAPHICAL)
	{
		if ((ret = init_graphical()))
			return (ret);
	}
	else
	{
		if ((ret = init_player()))
			return (ret);
	}
	ft_printf("IS_GRAPHICAL = %d\n", IS_GRAPHICAL);
	ft_printf("MY_ID = %d\n", MY_ID);
	ft_printf("MY_AI_ID = %d\n", AI_ID);
	return (ret);
}
