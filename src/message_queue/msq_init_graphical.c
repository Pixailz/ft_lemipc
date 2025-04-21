/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msq_graphical.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:01:24 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/30 11:11:26 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern mqd_t	LEM_IPC_MSQ[LEM_IPC_NB_TEAM];

t_lemipc_error	init_msq_graphical(mqd_t *msq, char *name)
{
	errno = 0;
	while ((*msq = mq_open(name, O_RDWR, 0644, FT_NULL)) == (mqd_t)-1)
	{
		if (errno != ENOENT)
		{
			ft_perr("mq_open: failed to open %s\n", name);
			perror("graphical: mq_open");
			return (ERR_MSQ_INIT);
		}
		errno = 0;
	}
	return (SUCCESS);
}

t_lemipc_error	init_msqs_graphical(void)
{
	t_lemipc_error	retv;
	char	*tmp;
	int		i;

	i = 0;
	while (i < LEM_IPC_NB_TEAM)
	{
		tmp = get_msq_key(i);
		if ((retv = init_msq_graphical(&LEM_IPC_MSQ[i], tmp)))
			return (retv);
		i++;
		ft_printf("msq_init: succeed /dev/mqueue%s\n", tmp);
	}
	return (SUCCESS);
}
