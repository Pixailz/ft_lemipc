/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 22:01:40 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/29 00:01:40 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern mqd_t	LEM_IPC_MSQ[LEM_IPC_NB_TEAM];

void	unlink_message_queues(void)
{
	int		i;

	i = 0;
	while (i < LEM_IPC_NB_TEAM)
		mq_unlink(get_message_queue_key(i++));
}

void	close_message_queues(void)
{
	int		i;

	i = 0;
	while (i < LEM_IPC_NB_TEAM)
		mq_close(LEM_IPC_MSQ[i++]);
}