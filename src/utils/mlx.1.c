/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:20:46 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/30 10:30:01 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

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

void	put_cell(t_pos pos, t_lem_team_id team_id, t_mlx_texture *scene)
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
			ft_put_pixel(ppos, scene, color);
			ppos.x++;
		}
		ppos.y++;
	}
}


t_bool	wait_for_player_2(void)
{
	if (is_player_here())
	{
		print_mlx_log("Player has arrived");
		return TRUE;
	}
	close_semaphores();
	close_message_queues();
	while (!IS_SIGINT && !is_player_here())
		usleep(A_SEC / 3);
	return FALSE;
}

void	wait_for_memory(void)
{
	// if (wait_for_player_2())
	// 	return ;
	if (!get_nb_player())
	{
		init_shared_memory();
		if (!IS_SIGINT)
		{
			close_semaphores();
			close_message_queues();
			init_semaphores();
			init_message_queues_graphical();
		}
	}
}
