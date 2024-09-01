/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphical.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:14:15 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/01 19:41:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern	t_bool	IS_GRAPHICAL_TEXT;

t_error	init_graphical(void)
{
	t_error	ret;

	if ((ret = init_msqs_graphical()))
		return (ret);
	if (!IS_GRAPHICAL_TEXT)
	{
		if ((ret = init_graphical_mlx()))
			return (ret);
	}
	return (SUCCESS);
}
