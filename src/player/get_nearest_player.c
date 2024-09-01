/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nearest_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:30:56 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/01 16:40:38 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern t_pos			POS;
extern t_lem_team_id	TEAM_ID;

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