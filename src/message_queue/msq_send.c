/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msq_send.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 22:01:40 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/01 19:19:08 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern mqd_t			LEM_IPC_MSQ[LEM_IPC_NB_TEAM];
extern t_lem_team_id	TEAM_ID;

t_bool	msq_send(void)
{
	char	*buff;
	size_t	*buff_len;

	buff = sing_msq_buff();
	buff_len = sing_msq_buff_len();
	errno = 0;
	if (mq_send(LEM_IPC_MSQ[TEAM_ID - 1], buff, *buff_len, 0) == -1)
	{
		if (errno != EAGAIN)
			perror("msq_send");
		else
		{
			ft_perr("msq_send: Message Queue FULL, Team %d\n", TEAM_ID);
			errno = 0;
		}
		return (TRUE);
	}
	ft_pdeb("msq_send: Message send Team %d (len %d)\n", TEAM_ID, buff, buff_len);
	return (FALSE);
}