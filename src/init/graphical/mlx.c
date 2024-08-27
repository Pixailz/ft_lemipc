/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:09:53 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/27 09:41:36 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

void			*MLX = FT_NULL;
void			*WIN = FT_NULL;
t_mlx_texture	SCENE_BOARD = {0};
t_mlx_texture	SCENE_LOG = {0};
t_pos			LEM_IPC_SCREEN = {0};
t_pos			LEM_IPC_BOARD_WIDTH = {0};
t_pos			LEM_IPC_LOG_WIDTH = {0};

t_error	init_scene_board_border(t_size cell_size)
{
	t_bool	xx;
	t_pos	pos;

	pos.x = 0;
	xx = 0;
	while (pos.x < LEM_IPC_BOARD_WIDTH.x)
	{
		pos.y = 0;
		while (pos.y < LEM_IPC_BOARD_WIDTH.y)
		{
			if (	pos.x == 0 || pos.x == LEM_IPC_BOARD_WIDTH.x - 1 ||
					pos.y == 0 || pos.y == LEM_IPC_BOARD_WIDTH.y - 1)
				ft_put_pixel(pos, &SCENE_BOARD, MLX_GRAY);
			else if (xx || !(pos.y % cell_size))
				ft_put_pixel(pos, &SCENE_BOARD, MLX_GRAY);
			pos.y++;
		}
		pos.x++;
		xx = !(pos.x % cell_size);
	}
	return (SUCCESS);
}

void	init_scene_log_border(void)
{
	t_pos	pos;

	pos.x = 0;
	while (pos.x < LEM_IPC_LOG_WIDTH.x)
	{
		pos.y = 0;
		while (pos.y < LEM_IPC_LOG_WIDTH.y)
		{
			if (	pos.x == 0 || pos.x == LEM_IPC_LOG_WIDTH.x - 1 ||
					pos.y == 0 || pos.y == LEM_IPC_LOG_WIDTH.y - 1)
				ft_put_pixel(pos, &SCENE_LOG, LEM_IPC_LOG_BORDER);
			else
				ft_put_pixel(pos, &SCENE_LOG, LEM_IPC_LOG_BACK);
			pos.y++;
		}
		pos.x++;
	}
}

t_error	init_scene(t_mlx_texture *scene, t_pos size)
{
	scene->ptr = mlx_new_image(MLX, size.x, size.y);
	if (!scene->ptr)
		return (ERR_INIT_MLX_IMG);
	scene->buff = (t_uint32 *)mlx_get_data_addr(scene->ptr, &scene->bpp, &scene->line_len, &scene->endian);
	if (!scene->buff)
		return (ERR_INIT_MLX_IMG);
	ft_bzero(scene->buff, size.x * size.y * 4);
	return (SUCCESS);
}

t_error	init_scenes(void)
{
	init_scene(&SCENE_BOARD, LEM_IPC_BOARD_WIDTH);
	init_scene_board_border(CELL_SIZE);
	if (LEM_IPC_LOG_POS)
	{
		init_scene(&SCENE_LOG, LEM_IPC_LOG_WIDTH);
		init_scene_log_border();
	}
	return (SUCCESS);
}

void	get_screen_size(void)
{
	LEM_IPC_BOARD_WIDTH.x = LEM_IPC_BOARD_LEN_X * CELL_SIZE + 1;
	LEM_IPC_BOARD_WIDTH.y = LEM_IPC_BOARD_LEN_Y * CELL_SIZE + 1;
	LEM_IPC_LOG_WIDTH.x = 0;
	LEM_IPC_LOG_WIDTH.y = 0;
	LEM_IPC_SCREEN.x = LEM_IPC_BOARD_WIDTH.x;
	LEM_IPC_SCREEN.y = LEM_IPC_BOARD_WIDTH.y;
	if (LEM_IPC_LOG_POS)
	{
		if (LEM_IPC_LOG_POS == 1 || LEM_IPC_LOG_POS == 2)
		{
			LEM_IPC_LOG_WIDTH.x = LEM_IPC_LOG_SIZE_X + 2;
			LEM_IPC_LOG_WIDTH.y = LEM_IPC_BOARD_WIDTH.y;
			LEM_IPC_SCREEN.x += LEM_IPC_LOG_WIDTH.x;
		}
		else
		{
			LEM_IPC_LOG_WIDTH.x = LEM_IPC_BOARD_WIDTH.x;
			LEM_IPC_LOG_WIDTH.y = LEM_IPC_LOG_SIZE_Y + 2;
			LEM_IPC_SCREEN.y += LEM_IPC_LOG_WIDTH.y;
		}
	}
}

t_error	init_graphical_mlx(void)
{
	t_error	ret;

	ft_printf("init_graphical_mlx\n");
	MLX = mlx_init();
	if (!MLX)
		return (ERR_INIT_MLX);
	get_screen_size();
	get_nb_log_line();
	WIN = mlx_new_window(MLX, LEM_IPC_SCREEN.x, LEM_IPC_SCREEN.y, "lem_ipc");
	if (!WIN)
		return (ERR_INIT_MLX_WIN);
	if ((ret = init_scenes()))
		return (ret);
	mlx_hook(WIN, 33, (1L << 17), end_hook, MLX);
	mlx_hook(WIN, 2, (1L << 0), key_press, MLX);
	mlx_hook(WIN, 3, (1L << 1), key_release, MLX);
	mlx_loop_hook(MLX, &handler_mlx, MLX);
	return (SUCCESS);
}
