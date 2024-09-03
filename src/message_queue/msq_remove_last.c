/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msq_remove_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 00:13:52 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/02 22:22:56 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern t_bool			IS_SIGINT;
extern t_lem_player_id	MY_ID;

void	msq_remove_last(t_lem_ipc_message_type type)
{
	t_msq_hdr	*msg;
	int			counter;

	counter = 0;
	while (counter < MSQ_MSG_MAX)
	{
		if (msq_recv(type))
			return ;
		msg = msq_get_header();
		counter++;
		if (msg == FT_NULL)
			return ;
		if (msg->player_id == MY_ID)
			continue ;
		msq_send();
	}
}
