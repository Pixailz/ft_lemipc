/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_team_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:20:46 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/31 17:51:25 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

t_int4	mlx_get_team_color(t_uint8 team_id)
{
	t_int4	COLOR[LEM_IPC_NB_TEAM + 1] = {
		MLX_BLACK,
		MLX_GRE,
		MLX_RED,
		MLX_BLU,
		MLX_YEL,
		MLX_ORA,
		MLX_PUR,
		MLX_CYA,
		MLX_WHITE
	};
	return (COLOR[team_id]);
}

char	*text_get_team_color(t_lem_team_id team_id)
{
	char	*COLOR[LEM_IPC_NB_TEAM + 1] = {
		GRE,
		GRE,
		RED,
		BLU,
		YEL,
		ORA,
		PUR,
		CYA,
		WHI
	};
	return (COLOR[team_id]);
}