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

extern		t_bool 			IS_SIGINT;
extern		t_bool 			IS_DEAD;

void	loop_random(void)
{
	while (!IS_SIGINT && !IS_DEAD)
	{
		usleep(LEM_IPC_FREQ);
		while (!move_player(ft_randint(0, 4)))
			;
	}
}
