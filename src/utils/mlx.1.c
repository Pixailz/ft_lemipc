/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:20:46 by brda-sil          #+#    #+#             */
/*   Updated: 2024/06/17 10:52:37 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern void				*MLX;
extern void				*WIN;
extern t_mlx_texture	SCENE;
extern t_lem_ipc_sem	LEM_IPC_SEM;
extern t_bool			IS_SIGINT;

void	ft_put_pixel(t_pos pos, t_mlx_texture *image, t_int4 color)
{
	int	point;

	if (pos.x < 0 || pos.y < 0)
		return ;
	point = pos.x + pos.y * (image->line_len / 4);
	image->buff[point] = color;
	return ;
}

t_int4	get_team_color(t_uint8 team_id)
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

void	put_cell(t_pos pos, t_lem_team_id team_id)
{
	t_pos	ppos;
	t_int4	color;

	ppos.y = (pos.y * CELL_SIZE) + 1;
	color = get_team_color(team_id);
	while (ppos.y < (pos.y + 1) * CELL_SIZE)
	{
		ppos.x = (pos.x * CELL_SIZE) + 1;
		while (ppos.x < (pos.x + 1) * CELL_SIZE)
		{
			ft_put_pixel(ppos, &SCENE, color);
			ppos.x++;
		}
		ppos.y++;
	}
}

void	wait_for_memory(void)
{
	if (!get_nb_player())
	{
		init_shared_memory();
		if (!IS_SIGINT)
		{
			sem_close(LEM_IPC_SEM.nb_player);
			sem_close(LEM_IPC_SEM.board);
			sem_close(LEM_IPC_SEM.pause);
			init_semaphores();
		}
	}
}
