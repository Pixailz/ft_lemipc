/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   team.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:29:30 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/27 14:22:14 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern	void*	MLX;
extern	void*	WIN;

extern	t_pos	LEM_IPC_LOG_WIDTH;
extern	t_pos	ORIGIN_LOG;

void	mlx_log_put_team_get_stat(t_tile *board, int *stats)
{
	int	counter;
	int	id;

	counter = 0;
	while (counter < LEM_IPC_NB_TEAM)
	{
		stats[counter] = 0;
		counter++;
	}
	counter = 0;
	while (counter < LEM_IPC_BOARD_LEN_X * LEM_IPC_BOARD_LEN_Y)
	{
		if (board[counter].team_id)
		{
			id = (board[counter].team_id - 1) % LEM_IPC_NB_TEAM;
			stats[id] += 1;
		}
		counter++;
	}
}

void	mlx_log_put_stat_team(int *stat, int color)
{
	int		team_id;
	char	*nb_str;
	int		nb_str_len;
	t_pos	index;

	team_id = 0;
	index.x = 0;
	index.y = 1;
	while (team_id < LEM_IPC_NB_TEAM)
	{
		nb_str = ft_itoa(stat[team_id]);
		nb_str_len = ft_strlen(nb_str);
		update_index_new_line(&index);
		index.x += LEM_IPC_LEN_TEAM_STR + (LEM_IPC_LEN_NB_TEAM - nb_str_len);
		mlxput_text_at(nb_str, color, index, FALSE);
		free(nb_str);
		index.x += nb_str_len + 1;
		team_id++;
	}
}

int	*mlx_log_put_stat(t_tile *board)
{
	static	int	last_stats[LEM_IPC_NB_TEAM] = {0};

	mlx_log_put_stat_team(last_stats, LEM_IPC_LOG_BACK);
	mlx_log_put_team_get_stat(board, last_stats);
	mlx_log_put_stat_team(last_stats, LEM_IPC_LOG_FONT_COLOR);
	return last_stats;
}
