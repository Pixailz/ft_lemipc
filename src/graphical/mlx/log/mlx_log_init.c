/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_log_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 00:50:16 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/01 15:42:27 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

t_uint32		LEM_LOG_NB_LINE = -1;

extern t_pos	LEM_IPC_LOG_WIDTH;

void	get_nb_log_line(void)
{
	LEM_LOG_NB_LINE = LEM_IPC_LOG_WIDTH.y / MLX_FONT_UNIT_Y;
	LEM_LOG_NB_LINE -= LEM_IPC_LOG_HEADER_SIZE + LEM_IPC_LOG_FOOTER_SIZE;
	return ;
}

void	init_log_str(char ***log_str)
{
	get_nb_log_line();
	*log_str = (char **)ft_calloc(sizeof(char *), LEM_LOG_NB_LINE + 1);
}