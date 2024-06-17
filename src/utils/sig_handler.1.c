/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:42:39 by brda-sil          #+#    #+#             */
/*   Updated: 2024/06/16 14:21:40 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

t_bool IS_SIGINT = FALSE;

void	sig_handler(int sig)
{
	ft_printf("\nSig Handler: recv(%d)\n", sig);
	IS_SIGINT = TRUE;
}
