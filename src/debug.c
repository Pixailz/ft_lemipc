/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:04:56 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/02 18:23:41 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern t_lem_team_id	TEAM_ID;

void	debug_msq_recv(void)
{
	t_msq_hdr	*msg_hdr;
	t_msq_atk	*msg_atk;

	if (msq_recv(MSQ_TYPE_ATK))
		return ;
	msq_send();
	msg_hdr = msq_get_header();
	msg_atk = msq_get_attack();
	ft_printf("msg_hdr->type = %d\n", msg_hdr->type);
	ft_printf("msg_atk->leader = %d %d\n", msg_atk->leader.x, msg_atk->leader.y);
	ft_printf("msg_atk->target = %d %d\n", msg_atk->target.x, msg_atk->target.y);
}

void	debug_msq_get_nearest_attack(void)
{
	t_msq_atk	*msg_atk;

	msg_atk = msq_get_nearest_attack();
	if (msg_atk == FT_NULL)
		return ;
	ft_printf("msg_atk->leader = %d %d\n", msg_atk->leader.x, msg_atk->leader.y);
	ft_printf("msg_atk->target = %d %d\n", msg_atk->target.x, msg_atk->target.y);
}

void	debug_msq(int ac, char **av)
{
	char	*mode;

	TEAM_ID = 1;
	if (init_msqs())
		return ;
	if (ac != 2)
		return ;
	mode = av[1];
	if (!ft_strcmp(mode, "send"))
		msq_send_attack((t_pos){1, 2});
	else if (!ft_strcmp(mode, "recv"))
		debug_msq_recv();
	else if (!ft_strcmp(mode, "nearest"))
		debug_msq_get_nearest_attack();
	else if (!ft_strcmp(mode, "last"))
		msq_remove_last(MSQ_TYPE_ATK);
}
