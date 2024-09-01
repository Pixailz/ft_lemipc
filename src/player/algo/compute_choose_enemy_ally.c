/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_choose_enemy_ally.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:30:56 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/01 19:55:59 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

t_vec	compute_choose_enemy_ally(t_vec enemy, t_vec ally)
{
	t_vec	dir;
	t_vec	retv;
	char	*retv_str;

	dir.pos.x = ft_get_abs(ally.dir.x) + ft_get_abs(ally.dir.y);
	dir.pos.y = ft_get_abs(enemy.dir.x) + ft_get_abs(enemy.dir.y);
	dir.dir.x = dir.pos.x - dir.pos.y;
	if (dir.pos.x > 3 || dir.pos.y < 3)
	{
		retv = ally;
		retv_str = "A";
	}
	else
	{
		retv = enemy;
		retv_str = "E";
	}
	ft_pdeb("A = %d, E = %d" SEP "%s\n", dir.pos.x, dir.pos.y, retv_str);
	return (retv);
}