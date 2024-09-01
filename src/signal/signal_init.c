/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:01:51 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/31 18:00:11 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

t_error	init_signal(void)
{
	if (signal(SIGINT, &sig_handler) == SIG_ERR)
	{
		ft_perr("signal: failed to set SIGINT\n");
		return (ERR_SIGNAL);
	}
	return (SUCCESS);
}
