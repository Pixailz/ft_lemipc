/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:01:24 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/25 05:57:24 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"


t_error	init_message_queue(mqd_t *msq, char *name)
{
	if ((*msq = mq_open(name, O_CREAT, 0666, NULL)) == (mqd_t)-1)
	{
		if (errno == EEXIST)
		{
			if ((*msq = mq_open(name, 0666)) == (mqd_t)-1)
			{
				ft_perr("mq_open: failed to open %s\n", name);
				return (ERR_SEM_INIT);
			}
		}
		else
			return (ERR_SEM_INIT);
	}
	return (SUCCESS);
}

t_error	init_messages_queue(void)
{
	// t_error	retv;
	// mqd_t	test_1;

	// retv = init_message_queue(&test_1, "/test");

	// ft_printf("retv   %d\n", retv);
	// ft_printf("test_1 %d\n", test_1);

	// if (())
	// 	return (retv);

	return (SUCCESS);
}
