/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:29:30 by brda-sil          #+#    #+#             */
/*   Updated: 2024/06/17 10:53:54 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern void				*MLX;
extern void				*WIN;
extern t_mlx_texture	SCENE;
extern t_bool			IS_SIGINT;

int	end_hook(void *mlx)
{
	mlx_loop_end(mlx);
	return (0);
}

void	fill_board(void)
{
	t_tile			*board;
	t_pos			pos;

	board = get_board();
	pos.y = 0;
	while (pos.y < LEM_IPC_BOARD_LEN_Y)
	{
		pos.x = 0;
		while (pos.x < LEM_IPC_BOARD_LEN_X)
		{
			put_cell(pos, board[pos.x + pos.y * LEM_IPC_BOARD_LEN_X].team_id);
			pos.x++;
		}
		pos.y++;
	}
}

int	handler_mlx(void *mlx)
{
	if (IS_SIGINT)
		return (end_hook(mlx));
	fill_board();
	mlx_put_image_to_window(mlx, WIN, SCENE.ptr, 0, 0);
	wait_for_memory();
	usleep(A_SEC / LEM_IPC_GRAPH_FPS_MLX);
	return (0);
}

int	key_press(int key_code, void *mlx)
{
	(void)mlx;
	ft_printf("key code: %04x\n", key_code);
	return (0);
}

int	key_release(int key_code, void *mlx)
{
	if (key_code == KEY_ESC)
		return (end_hook(mlx));
	if (key_code == KEY_SPACE)
		lemipc_pause_toggle();
	return (0);
}

t_bin	run_graphical_mlx(void)
{
	mlx_loop(MLX);
	return (SUCCESS);
}
