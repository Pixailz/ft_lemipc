/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:14:17 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/02 20:42:53 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IPC_PROFILE_SIZE_H
# define LEM_IPC_PROFILE_SIZE_H

# if LEM_IPC_PROFILE_SIZE == LEM_IPC_PROFILE_SIZE_SMALL
#  define	LEM_IPC_BOARD_LEN_X			25
#  define	LEM_IPC_BOARD_LEN_Y			25
#  define	CELL_SIZE					24

# elif LEM_IPC_PROFILE_SIZE == LEM_IPC_PROFILE_SIZE_MEDIUM
#  define	LEM_IPC_BOARD_LEN_X			50
#  define	LEM_IPC_BOARD_LEN_Y			50
#  define	CELL_SIZE					12

# elif LEM_IPC_PROFILE_SIZE == LEM_IPC_PROFILE_SIZE_LARGE
#  define	LEM_IPC_BOARD_LEN_X			100
#  define	LEM_IPC_BOARD_LEN_Y			100
#  define	CELL_SIZE					6

# elif LEM_IPC_PROFILE_SIZE == LEM_IPC_PROFILE_SIZE_VERY_LARGE
#  define	LEM_IPC_BOARD_LEN_X			200
#  define	LEM_IPC_BOARD_LEN_Y			200
#  define	CELL_SIZE					3

# elif LEM_IPC_PROFILE_SIZE == LEM_IPC_PROFILE_SIZE_HUGE
#  define	LEM_IPC_BOARD_LEN_X			400
#  define	LEM_IPC_BOARD_LEN_Y			400
#  define	CELL_SIZE					2

# endif

#endif // LEM_IPC_PROFILE_SIZE_H