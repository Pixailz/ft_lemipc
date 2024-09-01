/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:08:34 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/31 17:55:13 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern void				*MLX;
extern void				*WIN;
extern t_mlx_texture	SCENE_BOARD;
extern t_mlx_texture	SCENE_LOG;

void	free_mlx(void)
{
	if (MLX)
	{
		if (WIN)
			mlx_destroy_window(MLX, WIN);
		mlx_destroy_image(MLX, SCENE_BOARD.ptr);
		if (LEM_IPC_LOG_POS)
			mlx_destroy_image(MLX, SCENE_LOG.ptr);
		mlx_log(FT_NULL);
		mlx_destroy_display(MLX);
		free(MLX);
	}
}
