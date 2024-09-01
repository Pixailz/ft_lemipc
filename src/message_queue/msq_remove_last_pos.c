/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msq_remove_last_pos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 00:13:52 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/02 00:23:30 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern t_pos	LAST_POS;
extern t_bool	IS_SIGINT;

void	msq_remove_last_pos(void)
{
	t_msq_atk	*msg;

	while (!IS_SIGINT)
	{
		if (msq_recv(MSQ_TYPE_ATK))
			return ;
		msg = msq_get_attack();
		if (msg != FT_NULL &&
			msg->target.x == LAST_POS.x && msg->target.y == LAST_POS.y
		)
			return ;
		msq_send();
	}
}

