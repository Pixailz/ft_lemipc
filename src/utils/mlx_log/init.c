/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 00:50:16 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/25 06:59:10 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

int	LEM_LOG_NB_LINE = -1;

extern t_pos	LEM_IPC_LOG_WIDTH;

void	init_log_str(char ***log_str)
{
	LEM_LOG_NB_LINE = LEM_IPC_LOG_WIDTH.y / (
		LEM_IPC_LOG_FONT_SIZE_Y + LEM_IPC_LOG_FONT_SPACING
	);
	LEM_LOG_NB_LINE -= (LEM_IPC_LOG_HEADER_SIZE + LEM_IPC_LOG_FOOTER_SIZE);
	*log_str = (char **)ft_calloc(sizeof(char *), LEM_LOG_NB_LINE + 1);
}