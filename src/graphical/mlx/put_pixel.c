/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:20:46 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/31 17:50:20 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

void	ft_put_pixel(t_pos pos, t_mlx_texture *image, t_int4 color)
{
	int	point;

	if (pos.x < 0 || pos.y < 0)
		return ;
	point = pos.x + pos.y * (image->line_len / 4);
	image->buff[point] = color;
	return ;
}