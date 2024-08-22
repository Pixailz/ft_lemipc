/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:00:58 by brda-sil          #+#    #+#             */
/*   Updated: 2024/06/16 17:29:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern	t_bool	IS_GRAPHICAL;
extern	t_bool	MY_ID;
extern	t_ai_id	AI_ID;

t_error	init_prog(void)
{
	t_error	ret;

	if ((ret = init_signal()))
		return (ret);
	if ((ret = init_shared_memory()))
		return (ret);
	if ((ret = init_semaphores()))
		return (ret);
	if (IS_GRAPHICAL)
		init_graphical();
	else
		init_player();
	ft_printf("IS_GRAPHICAL = %d\n", IS_GRAPHICAL);
	ft_printf("MY_ID = %d\n", MY_ID);
	ft_printf("MY_AI_ID = %d\n", AI_ID);
	return (ret);
}
