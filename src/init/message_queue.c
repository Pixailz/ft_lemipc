/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:01:24 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/30 11:13:03 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

mqd_t	LEM_IPC_MSQ[LEM_IPC_NB_TEAM] = {0};

t_error	init_message_queue(mqd_t *msq, char *name)
{
	errno = 0;
	if ((*msq = mq_open(name, O_RDWR | O_CREAT | O_EXCL, 0644, FT_NULL)) == (mqd_t)-1)
	{
		perror("mq_open");
		if (errno == EEXIST)
		{
			if ((*msq = mq_open(name, O_RDWR, 0644, FT_NULL)) == (mqd_t)-1)
			{
				ft_printf("Errno %d\n", errno);
				perror("mq_reopen");
				return (ERR_MSQ_INIT);
			}
		}
		else if (errno == EMFILE)
		{
			usleep(A_SEC / 10);
			return (init_message_queue(msq, name));
		}
	}
	return (SUCCESS);
}

char	*get_message_queue_key(t_lem_team_id team_id)
{
	static char	buff[0xff];

	buff[ft_sprintf(buff, "/%s-team_%d", SHO_MSQ_KEY, team_id + 1)] = 0;
	return (buff);
}

t_error	init_message_queues(void)
{
	t_error	retv;
	char	*tmp;
	int		i;

	i = 0;
	while (i < LEM_IPC_NB_TEAM)
	{
		tmp = get_message_queue_key(i);
		if ((retv = init_message_queue(&LEM_IPC_MSQ[i], tmp)))
			return (retv);
		i++;
		ft_printf("msq_init: succeed /dev/mqueue%s\n", tmp);
	}
	return (SUCCESS);
}
