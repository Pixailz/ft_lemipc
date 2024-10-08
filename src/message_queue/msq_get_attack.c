/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msq_get_attack.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:37:20 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/01 19:40:37 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

t_msq_atk	*msq_get_attack(void)
{
	char	*buff;
	size_t	*buff_len;

	buff = sing_msq_buff();
	buff_len = sing_msq_buff_len();
	if (*buff_len < MSQ_SIZE_HDR + MSQ_SIZE_ATK)
		return (FT_NULL);
	return ((t_msq_atk *)(buff + MSQ_SIZE_HDR));
}
