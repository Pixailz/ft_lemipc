/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 00:50:16 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/25 06:07:20 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern int	LEM_LOG_NB_LINE;

void	mlx_log_free(char **log_str)
{
	int	i;

	i = 0;
	while (i < LEM_LOG_NB_LINE)
	{
		if (log_str[i] != FT_NULL)
		{
			free(log_str[i]);
			log_str[i] = FT_NULL;
		}
		i++;
	}
	free(log_str);
	log_str = FT_NULL;
}