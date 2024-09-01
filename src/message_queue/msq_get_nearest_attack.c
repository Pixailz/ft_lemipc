/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msq_get_attack.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:37:20 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/01 19:40:37 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern t_bool	IS_SIGINT;
extern t_pos	POS;

t_msq_atk	*msq_get_nearest_attack(void)
{
	t_msq_atk	*msg;
	t_vec		tmp;

	while (!IS_SIGINT)
	{
		if (msq_recv(MSQ_TYPE_ATK))
			return (FT_NULL);
		msg = msq_get_attack();
		if (msg == FT_NULL)
			return (FT_NULL);
		if (msg->target.x == -1 && msg->target.y == -1)
			return (FT_NULL);
		msq_send();
		tmp.pos.x = msg->target.x - POS.x;
		tmp.pos.y = msg->target.y - POS.y;
		tmp.dir.x = ft_get_abs(tmp.pos.x) + ft_get_abs(tmp.pos.y);
		if (tmp.dir.x < 16)
			break;
	}
	return (msg);
}
