/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:09:53 by brda-sil          #+#    #+#             */
/*   Updated: 2024/06/16 18:33:39 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

void			*MLX = FT_NULL;
void			*WIN = FT_NULL;
t_mlx_texture	SCENE = {0};

t_error	init_scene_border(t_size cell_size)
{
	t_bool	xx;
	t_pos	pos;

	pos.x = 0;
	xx = 0;
	ft_bzero(SCENE.buff, LEM_IPC_SCREEN_X * LEM_IPC_SCREEN_Y * 4);
	while (pos.x < LEM_IPC_SCREEN_X)
	{
		pos.y = 0;
		while (pos.y < LEM_IPC_SCREEN_Y)
		{
			if (	pos.x == 0 || pos.x == LEM_IPC_SCREEN_X - 1 ||
					pos.y == 0 || pos.y == LEM_IPC_SCREEN_Y - 1)
				ft_put_pixel(pos, &SCENE, MLX_GRAY);
			else if (xx || !(pos.y % cell_size))
				ft_put_pixel(pos, &SCENE, MLX_GRAY);
			pos.y++;
			if ((t_uint32)pos.y > LEM_IPC_BOARD_LEN_Y * cell_size)
				break ;
		}
		pos.x++;
		if ((t_uint32)pos.x > LEM_IPC_BOARD_LEN_X * cell_size)
			break ;
		xx = !(pos.x % cell_size);
	}
	return (SUCCESS);
}

t_error	init_scene(void)
{
	SCENE.ptr = mlx_new_image(MLX, LEM_IPC_SCREEN_X, LEM_IPC_SCREEN_Y);
	if (!SCENE.ptr)
		return (ERR_INIT_MLX_IMG);
	SCENE.buff = (t_uint32 *)mlx_get_data_addr(SCENE.ptr, &SCENE.bpp, &SCENE.line_len, &SCENE.endian);
	if (!SCENE.buff)
		return (ERR_INIT_MLX_IMG);
	init_scene_border(CELL_SIZE);
	return (SUCCESS);
}

t_error	init_graphical_mlx(void)
{
	t_error	ret;

	ft_printf("init_graphical_mlx\n");
	MLX = mlx_init();
	if (!MLX)
		return (ERR_INIT_MLX);
	WIN = mlx_new_window(MLX, LEM_IPC_SCREEN_X, LEM_IPC_SCREEN_Y, "lem_ipc");
	if (!WIN)
		return (ERR_INIT_MLX_WIN);
	if ((ret = init_scene()))
		return (ret);
	mlx_hook(WIN, 33, (1L << 17), end_hook, MLX);
	mlx_hook(WIN, 2, (1L << 0), key_press, MLX);
	mlx_hook(WIN, 3, (1L << 1), key_release, MLX);
	mlx_loop_hook(MLX, &handler_mlx, MLX);
	return (SUCCESS);
}
