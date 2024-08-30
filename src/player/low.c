/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:30:56 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/29 00:40:22 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern t_pos			POS;
extern t_lem_team_id	TEAM_ID;

# define MAX_ITER (LEM_IPC_BOARD_LEN_X > LEM_IPC_BOARD_LEN_Y ? LEM_IPC_BOARD_LEN_X : LEM_IPC_BOARD_LEN_Y)

int	get_tile_team_id(t_tile *board, t_pos pos)
{
	t_lem_team_id	current_id;

	if (pos.x < 0 || pos.y < 0 || \
		pos.x > LEM_IPC_BOARD_LEN_X || pos.y > LEM_IPC_BOARD_LEN_X)
		return (-1);
	current_id = board[pos.y * LEM_IPC_BOARD_LEN_X + pos.x].team_id;
	if (current_id == 0)
		return (-1);
	return (current_id);
}

t_pos	get_nearest_line(t_tile *board, t_vec vec, int index, int mode)
{
	int	i;
	int	d;
	int	current_id;

	i = 0;
	if (vec.dir.x == 1)
		d = 1;
	else
		d = -1;
	while (i < (index * 2) + 1)
	{
		i++;
		vec.pos.x += d;
		current_id = get_tile_team_id(board, vec.pos);
		if (current_id == -1)
			continue ;
		if (mode == 1)
		{
			if ((t_uint32)current_id != TEAM_ID)
				return (vec.pos);
		}
		else
		{
			if ((t_uint32)current_id == TEAM_ID)
				return (vec.pos);
		}
	}
	return ((t_pos){-1, -1});
}

t_pos	get_nearest_column(t_tile *board, t_vec vec, int index, int mode)
{
	int	i;
	int	d;
	int	current_id;

	i = 0;
	if (vec.dir.y == 1)
		d = 1;
	else
		d = -1;
	while (i < (index * 2) + 1)
	{
		i++;
		vec.pos.y += d;
		current_id = get_tile_team_id(board, vec.pos);
		if (current_id == -1)
			continue ;
		if (mode == 1)
		{
			if ((t_uint32)current_id != TEAM_ID)
				return (vec.pos);
		}
		else
		{
			if ((t_uint32)current_id == TEAM_ID)
				return (vec.pos);
		}
	}
	return ((t_pos){-1, -1});
}

t_pos	get_nearest_player(t_tile *board, int mode)
{
	t_vec	vec;
	t_pos	retv;
	int		i;

	i = 1;
	while (i < MAX_ITER)
	{
		vec.pos = POS;
		vec.pos.x -= i;
		vec.pos.y -= i;
		vec.dir = (t_pos){1, 1};
		retv = get_nearest_line(board, vec, i, mode);
		if (retv.x != -1 && retv.y != -1)
			return (retv);
		retv = get_nearest_column(board, vec, i, mode);
		if (retv.x != -1 && retv.y != -1)
			return (retv);

		vec.pos.y += i * 2;
		vec.pos.x += i * 2;
		vec.dir = (t_pos){-1, -1};
		retv = get_nearest_line(board, vec, i, mode);
		if (retv.x != -1 && retv.y != -1)
			return (retv);
		retv = get_nearest_column(board, vec, i, mode);
		if (retv.x != -1 && retv.y != -1)
			return (retv);
		i++;
	}
	return ((t_pos){-1, -1});
}

static t_vec	compute_move(t_tile *board)
{
	t_vec vec;

	vec.pos = get_nearest_player(board, 1);
	if (vec.pos.x == -1 && vec.pos.y == -1)
	{
		ft_printf("(%02d,%02d) NO ENEMY FOUND\n", POS.x, POS.y);
		return (vec);
	}
	ft_printf("(%02d,%02d) ENEMY FOUND\n", vec.pos.x, vec.pos.y);
	return (vec);
}

void	computed_move(t_vec next_move)
{
	if (next_move.dir.x == 1)
		move_player(RIGHT);
	else if (next_move.dir.x == -1)
		move_player(LEFT);
	else if (next_move.dir.y == 1)
		move_player(DOWN);
	else if (next_move.dir.y == -1)
		move_player(UP);
	else
		random_move();
}

void	loop_low(void)
{
	t_tile	*board;
	t_vec	next_move;

	while (player_loop())
	{
		board = get_board();
		next_move = compute_move(board);
		computed_move(next_move);
	}
}
