/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msq_remove_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 00:13:52 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/02 22:24:59 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern t_bool			IS_SIGINT;
extern t_lem_player_id	MY_ID;

void	msq_remove_all(t_lem_ipc_message_type type)
{
	int			counter;

	counter = 0;
	while (counter < MSQ_MSG_MAX)
	{
		if (msq_recv(type))
			return ;
		counter++;
	}
}
