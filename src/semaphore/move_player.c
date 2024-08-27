/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:14:53 by brda-sil          #+#    #+#             */
/*   Updated: 2024/06/16 19:23:55 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"


extern t_lem_ipc_mem		*LEM_IPC_MEM;
extern t_pos				POS;
extern t_lem_player_id		MY_ID;
extern t_lem_team_id		TEAM_ID;
t_bool						IS_DEAD = FALSE;

t_bool	is_dead(t_pos pos, t_tile *board)
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

	if (x_max || y_zero)
		tile[2] = board[(pos.x + 1) + ((pos.y - 1) * LEM_IPC_BOARD_LEN_X)];

	if (x_max)
		tile[3] = board[(pos.x + 1) + (pos.y * LEM_IPC_BOARD_LEN_X)];

	if (x_max || y_max)
		tile[4] = board[(pos.x + 1) + ((pos.y + 1) * LEM_IPC_BOARD_LEN_X)];

	if (x_zero || y_max)
		tile[5] = board[(pos.x - 1) + ((pos.y + 1) * LEM_IPC_BOARD_LEN_X)];

	if (x_zero)
		tile[6] = board[(pos.x - 1) + (pos.y * LEM_IPC_BOARD_LEN_X)];

	if (x_zero || y_zero)
		tile[7] = board[(pos.x - 1) + ((pos.y - 1) * LEM_IPC_BOARD_LEN_X)];

	for (int i = 1; i <= LEM_IPC_NB_TEAM; i++)
	{
		n = 0;
		for (int j = 0; j < 8; j++)
		{
			if (tile[j].team_id == i && tile[j].team_id != TEAM_ID)
				n++;
			if (n >= 2)
			{
				IS_DEAD = TRUE;
				set_board(POS, (t_tile){0, 0});
				return (TRUE);
			}
		}
	}
	return (FALSE);
}

t_bool	move_player(t_dir dir)
{
	t_pos	tmp;
	t_tile	*board;

	tmp = POS;
	if (dir == UP)
		tmp.y--;
	else if (dir == RIGHT)
		tmp.x++;
	else if (dir == DOWN)
		tmp.y++;
	else if (dir == LEFT)
		tmp.x--;
	if (tmp.x < 0 || tmp.x >= LEM_IPC_BOARD_LEN_X ||
		tmp.y < 0 || tmp.y >= LEM_IPC_BOARD_LEN_Y)
	{
		ft_printf("OUT OF BOUNDS MOVE\n");
		return (FALSE);
	}
	board = get_board();
	if (is_dead(POS, board))
		return (TRUE);
	if (board[tmp.x + (tmp.y * LEM_IPC_BOARD_LEN_X)].player_id)
	{
		ft_printf("COLLISION\n");
		return (FALSE);
	}
	set_board(POS, (t_tile){0, 0});
	set_board(tmp, (t_tile){TEAM_ID, MY_ID});
	POS = tmp;
	return (TRUE);
}
