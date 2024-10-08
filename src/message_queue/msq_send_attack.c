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

extern t_pos			POS;
extern t_lem_player_id	MY_ID;

t_bool	msq_send_attack(t_pos enemy_pos)
{
	size_t		*buff_len;
	t_msq_hdr	*msg_hdr;
	t_msq_atk	*msg_atk;

	buff_len = sing_msq_buff_len();
	*buff_len = MSQ_SIZE_HDR + MSQ_SIZE_ATK;
	msg_hdr = msq_get_header();
	msg_hdr->type = MSQ_TYPE_ATK;
	msg_hdr->player_id = MY_ID;
	msg_atk = msq_get_attack();
	msg_atk->leader = POS;
	msg_atk->target = enemy_pos;
	return (msq_send());
}