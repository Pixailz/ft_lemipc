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
extern		t_lem_player_id	MY_ID;

// void	__loop(void)
// {
// 	int	i = 0;
// 	int	ii;

// 	while (!IS_SIGINT)
// 	{
// 		ii = i % 4;

// 		ft_printf("ii %d\n", ii);
// 		if (ii == 0)
// 		{
// 			move_player(UP);
// 			i = 0;
// 		}
// 		else if (ii == 1)
// 			move_player(RIGHT);
// 		else if (ii == 2)
// 			move_player(DOWN);
// 		else
// 			move_player(LEFT);
// 		i++;
// 		usleep(A_SEC / 2);
// 	}
// }

void	__loop(void)
{
	while (!IS_SIGINT && !IS_DEAD)
	{
		usleep(LEM_IPC_FREQ);
		while (!move_player(ft_randint(0, 4)))
			;
	}
}

t_error	run_player(void)
{
	__loop();
	return (SUCCESS);
}
