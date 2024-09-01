/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msq_recv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 22:01:40 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/01 19:38:49 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern mqd_t			LEM_IPC_MSQ[LEM_IPC_NB_TEAM];
extern t_lem_team_id	TEAM_ID;

static t_bool	msq_recv_post(t_lem_ipc_message_type type)
{
	t_msq_hdr	*msg_hdr;

	msg_hdr = msq_get_hdr();
	ft_printf("msg_hdr->type: %d\n", msg_hdr->type);
	if (msg_hdr->type != type)
	{
		if (msq_send() && errno != 0)
			return (FALSE);
		return (msq_recv(type));
	}
	return (FALSE);
}

t_bool	msq_recv(t_lem_ipc_message_type type)
{
	char		*buff;
	size_t		*buff_len;
	ssize_t		tmp_buff_len;
	t_uint32	prio;

	buff = sing_msq_buff();
	buff_len = sing_msq_buff_len();
	errno = 0;
	tmp_buff_len = mq_receive(LEM_IPC_MSQ[TEAM_ID - 1], buff, MSQ_SIZE_MAX, &prio);
	if (tmp_buff_len == -1)
	{
		*buff_len = 0;
		if (errno != EAGAIN)
			perror("msq_recv");
		else
		{
			ft_perr("msq_recv: Message Queue EMPTY, Team %d\n", TEAM_ID);
			errno = 0;
		}
		return (TRUE);
	}
	*buff_len = tmp_buff_len;
	buff[*buff_len] = 0;
	return (msq_recv_post(type));
}