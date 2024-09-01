/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:27:49 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/01 15:18:58 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

t_bool					IS_DEAD = FALSE;
extern t_pos			POS;
extern t_lem_team_id	TEAM_ID;

t_bool	check_death(t_pos pos, t_tile *board)
{
	t_tile	tile[8] = {0};
	t_uint8	n;

	t_bool	y_zero;
	t_bool	x_zero;
	t_bool	y_max;
	t_bool	x_max;

	y_zero = pos.y != 0;
	x_zero = pos.x != 0;
	y_max = pos.y != LEM_IPC_BOARD_LEN_Y - 1;
	x_max = pos.x != LEM_IPC_BOARD_LEN_X - 1;

	if (y_zero)
		tile[0] = board[pos.x + ((pos.y - 1) * LEM_IPC_BOARD_LEN_X)];

	if (y_max)
		tile[1] = board[pos.x + ((pos.y + 1) * LEM_IPC_BOARD_LEN_X)];

	if (x_max && y_zero)
		tile[2] = board[(pos.x + 1) + ((pos.y - 1) * LEM_IPC_BOARD_LEN_X)];

	if (x_max)
		tile[3] = board[(pos.x + 1) + (pos.y * LEM_IPC_BOARD_LEN_X)];

	if (x_max && y_max)
		tile[4] = board[(pos.x + 1) + ((pos.y + 1) * LEM_IPC_BOARD_LEN_X)];

	if (x_zero && y_max)
		tile[5] = board[(pos.x - 1) + ((pos.y + 1) * LEM_IPC_BOARD_LEN_X)];

	if (x_zero)
		tile[6] = board[(pos.x - 1) + (pos.y * LEM_IPC_BOARD_LEN_X)];

	if (x_zero && y_zero)
		tile[7] = board[(pos.x - 1) + ((pos.y - 1) * LEM_IPC_BOARD_LEN_X)];

	for (int i = 1; i <= LEM_IPC_NB_TEAM; i++)
	{
		if (i == TEAM_ID)
			continue;
		n = 0;
		for (int j = 0; j < 8; j++)
		{
			if (tile[j].team_id == i)
				n++;
			if (n > 1)
			{
				IS_DEAD = TRUE;
				return (TRUE);
			}
		}
	}
	return (FALSE);
}