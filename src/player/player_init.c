/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:15:31 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 15:12:50 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

t_pos					POS = {-1, -1};
t_lem_player_id			MY_ID = 0;
extern t_lem_team_id	TEAM_ID;

static	t_pos	get_empty_pos(void)
{
	t_pos	empty[LEM_IPC_BOARD_LEN] = {{-1, -1}};
	t_tile	*board;
	t_size	i;
	t_size	j;

	board = get_board();
	i = 0;
	j = 0;
	while (i < LEM_IPC_BOARD_LEN)
	{
		if (board[i].player_id == 0)
		{
			empty[j].x = i % LEM_IPC_BOARD_LEN_X;
			empty[j].y = i / LEM_IPC_BOARD_LEN_X;
			j++;
		}
		i++;
	}
	if (!j)
	{
		ft_perr("Board is FULL, try again later\n");
		return ((t_pos){-1, -1});
	}
	return (empty[ft_randint(0, j)]);
}

t_lemipc_error	get_random_pos(void)
{
	POS = get_empty_pos();
	if (POS.x == -1 && POS.y == -1)
		return (BOARD_FULL);
	return (SUCCESS);
}

t_lemipc_error	init_player(void)
{
	t_lemipc_error ret;

	if ((ret = init_msqs()))
		return (ret);
	if (get_random_pos())
		return (BOARD_FULL);
	MY_ID = inc_player_nb();
	set_board(POS, (t_tile){TEAM_ID, MY_ID});
	inc_max_player_nb();
	ft_printf("ID: %d | TEAM: %d\n", MY_ID, TEAM_ID);
	ft_printf("Random Pos\nx = %d\ny = %d\n", POS.x, POS.y);
	return (SUCCESS);
}
