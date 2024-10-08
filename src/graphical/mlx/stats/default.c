/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:29:30 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/01 15:42:27 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern t_pos	LEM_IPC_LOG_WIDTH;

void	mlx_log_put_team_default(void)
{
	int		team_id;
	char	*team_str;
	int		team_str_len;
	t_pos	index;

	team_id = 0;
	index.x = 0;
	index.y = 1;
	while (team_id < LEM_IPC_NB_TEAM)
	{
		team_str = ft_itoa(team_id + 1);
		team_str_len = ft_strlen(team_str);
		if (
			MLX_FONT_SPACING_X + (
				MLX_FONT_UNIT_X * (index.x + LEM_IPC_LEN_TOTAL + 1)
			) > LEM_IPC_LOG_WIDTH.x
		)
		{
			index.x = 0;
			index.y++;
		}
		index.x += LEM_IPC_LEN_TEAM_ID - team_str_len;
		mlxput_text_at(team_str, mlx_get_team_color(team_id + 1), index, FALSE);
		free(team_str);
		index.x += team_str_len;
		mlxput_text_at(LEM_IPC_TEAM_ID_SUFFIX, MLX_FONT_COLOR, index, FALSE);
		index.x += LEM_IPC_LEN_NB_TEAM + ft_strlen(LEM_IPC_TEAM_ID_SUFFIX) + 1;
		team_id++;
	}
}

void	mlx_log_put_total_nb_default(void)
{
	t_pos	pos;

	pos.x = 1;
	pos.y = 0;
	mlxput_text_at(LEM_IPC_NB_TOTAL, MLX_FONT_COLOR, pos, TRUE);
	pos.x += ft_strlen(LEM_IPC_NB_TOTAL) + LEM_IPC_LEN_NB_TOTAL;
	mlxput_text_at("/", MLX_FONT_COLOR, pos, TRUE);
}
