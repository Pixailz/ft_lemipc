/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shm_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:01:51 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 15:12:50 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

t_lem_ipc_mem	*LEM_IPC_MEM = FT_NULL;
extern t_bool	IS_SIGINT;

t_lemipc_error init_shm_mem(void)
{
	void	*shm_ptr;

	shm_ptr = get_shm((t_sho){
		.name = SHO_MEM_KEY,
		.size = SHO_MEM_SIZE,
		.o_oflag = SHO_MEM_OFLAG, .o_perm = SHO_MEM_PERM,
		.m_prot = SHM_PROT, .m_flag = SHM_FLAG
	});
	if (IS_SIGINT)
		return (STOP_SIGINT);
	if (shm_ptr == (void *)-ERR_SHO_FD)
		return (ERR_SHO_FD);
	if (shm_ptr == (void *)-ERR_SHM_PTR)
		return (ERR_SHM_PTR);
	LEM_IPC_MEM = (t_lem_ipc_mem *)shm_ptr;
	return (SUCCESS);
}

t_lemipc_error	init_shm(void)
{
	t_lemipc_error	ret;

	if ((ret = init_shm_mem()))
		return (ret);
	ft_printf("smh_init: succeed /dev/shm%s\n", SHO_MEM_KEY);
	return (SUCCESS);
}
