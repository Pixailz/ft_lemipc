/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:29:30 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/28 21:14:08 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern void				*MLX;
extern void				*WIN;
extern t_mlx_texture	SCENE_BOARD;
extern t_mlx_texture	SCENE_LOG;
extern t_bool			IS_SIGINT;
extern t_pos			LEM_IPC_SCREEN;
extern t_pos			LEM_IPC_BOARD_WIDTH;
extern t_pos			LEM_IPC_LOG_WIDTH;

t_pos					ORIGIN_BOARD = {0};
t_pos					ORIGIN_LOG = {0};

int	handler_mlx(void *mlx)
{
	t_tile	*board;

	if (IS_SIGINT)
		return (end_hook(mlx));
	board = get_board();
	fill_board(board);
	mlx_log_put_stat(board);
	mlx_log_put_total_nb();
	mlx_put_image_to_window(mlx, WIN, SCENE_BOARD.ptr, ORIGIN_BOARD.x, ORIGIN_BOARD.y);
	wait_for_memory();
	usleep(A_SEC / LEM_IPC_GRAPH_FPS_MLX);
	return (0);
}

t_bin	run_graphical_mlx(void)
{
	if (LEM_IPC_LOG_POS == 1)
		ORIGIN_LOG.x = LEM_IPC_BOARD_WIDTH.x;
	else if (LEM_IPC_LOG_POS == 2)
		ORIGIN_BOARD.x = LEM_IPC_LOG_WIDTH.x;
	else if (LEM_IPC_LOG_POS == 3)
		ORIGIN_BOARD.y = LEM_IPC_LOG_WIDTH.y;
	else if (LEM_IPC_LOG_POS == 4)
		ORIGIN_LOG.y = LEM_IPC_BOARD_WIDTH.y;
	if (LEM_IPC_LOG_POS)
	{
		mlx_put_image_to_window(MLX, WIN, SCENE_LOG.ptr, ORIGIN_LOG.x, ORIGIN_LOG.y);
		mlx_log_put_team_default();
		mlx_log_put_total_nb_default();
	}
	mlx_loop(MLX);
	return (SUCCESS);
}
