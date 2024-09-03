/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msq_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:01:24 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/01 18:29:50 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

mqd_t			LEM_IPC_MSQ[LEM_IPC_NB_TEAM] = {0};

t_error	init_msq(mqd_t *msq, char *name)
{
	errno = 0;
	if ((*msq = mq_open(name, O_RDWR | O_CREAT | O_EXCL, 0644, FT_NULL)) == (mqd_t)-1)
	{
		// perror("mq_open");
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
			return (init_msq(msq, name));
		}
		else
			perror("mq_open");
	}
	return (SUCCESS);
}

t_error	set_attr_msq(mqd_t *msq)
{
	struct mq_attr	attr;

	if (mq_getattr(*msq, &attr) == -1)
	{
		perror("mq_getattr");
		return (ERR_MSQ_INIT);
	}
	attr.mq_flags = O_NONBLOCK;
	attr.mq_maxmsg = MSQ_MSG_MAX;
	if (mq_setattr(*msq, &attr, FT_NULL) == -1)
	{
		perror("mq_setattr");
		return (ERR_MSQ_INIT);
	}
	return (SUCCESS);
}

char	*get_msq_key(t_lem_team_id team_id)
{
	static char	buff[0xff];

	buff[ft_sprintf(buff, "/%s-team_%d", SHO_MSQ_KEY, team_id + 1)] = 0;
	return (buff);
}

t_error	init_msqs(void)
{
	t_error	retv;
	char	*tmp;
	int		i;

	i = 0;
	while (i < LEM_IPC_NB_TEAM)
	{
		tmp = get_msq_key(i);
		if ((retv = init_msq(&LEM_IPC_MSQ[i], tmp)))
			return (retv);
		if ((retv = set_attr_msq(&LEM_IPC_MSQ[i])))
			return (retv);
		i++;
		ft_printf("msq_init: succeed /dev/mqueue%s\n", tmp);
	}
	return (SUCCESS);
}
