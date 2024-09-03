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

t_msq_atk	*msq_get_attack_by_id(t_lem_player_id id)
{
	t_msq_hdr	*msg;
	int			counter;

	counter = 0;
	while (42)
	{
		if (msq_recv(MSQ_TYPE_ATK))
			return (FT_NULL);
		msg = msq_get_header();
		if (msg == FT_NULL)
			return (FT_NULL);
		msq_send();
		if (msg->player_id == id)
			break;
		counter++;
		if (counter == MSQ_MSG_MAX)
			return (FT_NULL);
	}
	return (msq_get_attack());
}
