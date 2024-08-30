/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_memory.1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:35:15 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/30 10:28:03 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern t_bool		IS_GRAPHICAL;
extern t_bool		IS_SIGINT;

static int	wait_for_player(char *name, t_uint32 oflag, t_uint32 perm)
{
	int	sho_fd;

	sho_fd = -1;
	print_mlx_log("Waiting for players");
	while (sho_fd == -1)
	{
		if (IS_SIGINT)
			return (-1);
		usleep(A_SEC / 10);
		sho_fd = shm_open(name, oflag, perm);
	}
	print_mlx_log("Player(s) has arrived");
	return (sho_fd);
}

int	get_sho_fd(char *name, t_size size, t_uint32 oflag, t_uint32 perm)
{
	int		shm_fd;

	errno = 0;
	shm_fd = shm_open(name, oflag, perm);
	if (shm_fd == -1)
	{
		if (ft_strncmp(name, SHO_MEM_KEY, ft_strlen(SHO_MEM_KEY)) == 0)
		{
			if (IS_GRAPHICAL)
				return (wait_for_player(name, oflag, perm));
		}
		shm_fd = shm_open(name, O_CREAT | oflag, perm);
		if (shm_fd == -1)
			perror("shm_open");
		if (ftruncate(shm_fd, size) == -1)
			perror("ftruncate");
	}
	return (shm_fd);
}

void	*get_shm_ptr(int sho_fd, t_size size, t_uint32 prot, t_uint32 flag)
{
	void	*shm_ptr;

	shm_ptr = mmap(NULL, size, prot, flag, sho_fd, 0);
	if (shm_ptr == MAP_FAILED)
		perror("mmap");
	return (shm_ptr);
}

void	*get_shared_memory(t_sho sho)
{
	int		sho_fd;
	void	*shm_ptr;

	sho_fd = get_sho_fd(sho.name, sho.size, sho.o_oflag, sho.o_perm);
	if (sho_fd == -1)
		return ((void *)-ERR_SHO_FD);
	shm_ptr = get_shm_ptr(sho_fd, sho.size, sho.m_prot, sho.m_flag);
	close(sho_fd);
	if (shm_ptr == MAP_FAILED)
		return ((void *)-ERR_SHM_PTR);
	return (shm_ptr);
}
