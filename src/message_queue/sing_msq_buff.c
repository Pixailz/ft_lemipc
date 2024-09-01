/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sing_msq_buff.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 22:01:40 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/01 19:38:49 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

char	*sing_msq_buff(void)
{
	static char	buff[MSQ_SIZE_MAX] = {0};

	return (buff);
}

size_t	*sing_msq_buff_len(void)
{
	static size_t	buff = 0;

	return (&buff);
}
