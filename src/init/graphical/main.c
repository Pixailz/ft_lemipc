/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:14:15 by brda-sil          #+#    #+#             */
/*   Updated: 2024/06/16 14:15:05 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern	t_bool	IS_GRAPHICAL_TEXT;

t_error	init_graphical(void)
{
	t_error	ret;

	if (!IS_GRAPHICAL_TEXT)
		if ((ret = init_graphical_mlx()))
			return (ret);
	return (SUCCESS);
}
