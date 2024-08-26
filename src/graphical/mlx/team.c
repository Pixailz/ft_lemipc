/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   team.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:29:30 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/26 09:37:35 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern void				*MLX;
extern void				*WIN;
extern t_pos			LEM_IPC_SCREEN;
extern t_pos			LEM_IPC_BOARD_WIDTH;
extern t_pos			LEM_IPC_LOG_WIDTH;

extern t_pos			ORIGIN_BOARD;
extern t_pos			ORIGIN_LOG;

void	mlx_log_put_team(t_tile *board)
{
	return ;
}

void	mlx_log_put_team_default(void)
{
	print_mlx_log("[TEAM]");
	int		team_id;
	char	*team_str;
	int		team_str_len;
	int		index[2];

	team_id = 0;
	index[0] = 0;
	index[1] = 1;
	while (team_id < LEM_IPC_NB_TEAM)
	{
		team_str = ft_itoa(team_id);
		team_str_len = ft_strlen(team_str);
		if (
			LEM_IPC_LOG_FONT_SPACING + (
				LEM_IPC_LOG_FONT_UNIT_X * (index[0] + team_str_len)
			) > LEM_IPC_LOG_WIDTH.x
		)
		{
			index[0] = 0;
			index[1]++;
		}
		mlx_string_put(
			MLX, WIN,
			ORIGIN_LOG.x + LEM_IPC_LOG_FONT_SPACING + (LEM_IPC_LOG_FONT_UNIT_X * index[0]),
			ORIGIN_LOG.y + (LEM_IPC_LOG_FONT_UNIT_Y * index[1]),
			get_team_color(team_id),
			team_str
		);
		index[0] += team_str_len;
		free(team_str);
		if (
			LEM_IPC_LOG_FONT_SPACING + (
				LEM_IPC_LOG_FONT_UNIT_X * (index[0] + 7)
			) > LEM_IPC_LOG_WIDTH.x
		)
		{
			index[0] = 0;
			index[1]++;
		}
		mlx_string_put(
			MLX, WIN,
			ORIGIN_LOG.x + LEM_IPC_LOG_FONT_SPACING + (LEM_IPC_LOG_FONT_UNIT_X * index[0]),
			ORIGIN_LOG.y + (LEM_IPC_LOG_FONT_UNIT_Y * index[1]),
			LEM_IPC_LOG_FONT_COLOR,
			": "
		);
		index[0] += 7;
		team_id++;
	}
}