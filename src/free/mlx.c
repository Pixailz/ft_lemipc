/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:08:34 by brda-sil          #+#    #+#             */
/*   Updated: 2024/06/16 14:09:07 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern void				*MLX;
extern void				*WIN;
extern t_mlx_texture	SCENE;

void	free_mlx(void)
{
	if (MLX)
	{
		if (WIN)
			mlx_destroy_window(MLX, WIN);
		mlx_destroy_image(MLX, SCENE.ptr);

		mlx_destroy_display(MLX);
		free(MLX);
	}
}
