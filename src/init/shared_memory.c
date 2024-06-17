/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:01:51 by brda-sil          #+#    #+#             */
/*   Updated: 2024/06/16 17:38:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

t_lem_ipc_mem	*LEM_IPC_MEM = FT_NULL;
extern t_bool	IS_SIGINT;

t_error init_shared_memory_mem(void)
{
	void	*shm_ptr;

	shm_ptr = get_shared_memory((t_sho){
		.name = SHO_MEM_KEY,
		.size = SHO_MEM_SIZE,
		.o_oflag = SHO_MEM_OFLAG, .o_perm = SHO_MEM_PERM,
		.m_prot = SHM_PROT, .m_flag = SHM_FLAG
	});
	if (IS_SIGINT)
		return (STOP_SIGINT);
	if (shm_ptr == (void *)-ERR_SHO_FD || shm_ptr == (void *)-ERR_SHM_PTR)
		return (-*(t_int32 *)shm_ptr);
	LEM_IPC_MEM = (t_lem_ipc_mem *)shm_ptr;
	return (SUCCESS);
}

t_error	init_shared_memory(void)
{
	t_error	ret;

	if ((ret = init_shared_memory_mem()))
		return (ret);
	return (SUCCESS);
}
