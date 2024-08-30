/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_player_here.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:52:55 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/30 10:30:28 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

t_bool	is_here(char *prefix, char *name, int mode)
{
	static char	buff[0xff];

	buff[ft_sprintf(buff, "%s%s", prefix, name)] = 0;
	if (ft_isfile(buff, mode) == 1)
		return (FALSE);
	return (TRUE);
}

t_bool	is_shm_here(char *name)
{
	return (is_here("/dev/shm", name, 0644));
}

t_bool	is_sem_here(char *name)
{
	return (is_here("/dev/shm/sem.", name + 1, 0644));
}

t_bool	is_msq_here(char *name)
{
	return (is_here("/dev/mqueue", name, 0644));
}

t_bool	is_player_here(void)
{
	int		i;

	if (is_shm_here(SHO_MEM_KEY))
		return (FALSE);
	if (is_sem_here(get_semaphore_key("nb_player")))
		return (FALSE);
	if (is_sem_here(get_semaphore_key("board")))
		return (FALSE);
	if (is_sem_here(get_semaphore_key("pause")))
		return (FALSE);
	if (is_sem_here(get_semaphore_key("max_nb_player")))
		return (FALSE);
	i = 0;
	while (i < LEM_IPC_NB_TEAM)
	{
		if (is_msq_here(get_message_queue_key(i)))
			return (FALSE);
		i++;
	}
	return (TRUE);
}