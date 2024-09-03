/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:14:17 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/02 20:49:03 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IPC_PROFILE_DEFINE_H
# define LEM_IPC_PROFILE_DEFINE_H

typedef enum e_log_pos
{
	LOG_POS_DISABLE = 0,
	LOG_POS_RIGHT = 1,
	LOG_POS_LEFT = 2,
	LOG_POS_TOP = 3,
	LOG_POS_BOTTOM = 4
}	t_log_pos;

# define LEM_IPC_PROFILE_SIZE_SMALL			1
# define LEM_IPC_PROFILE_SIZE_MEDIUM		2
# define LEM_IPC_PROFILE_SIZE_LARGE			3
# define LEM_IPC_PROFILE_SIZE_VERY_LARGE	4
# define LEM_IPC_PROFILE_SIZE_HUGE			5

# define LEM_IPC_PROFILE_SPEED_HIGHLY_FAST	1
# define LEM_IPC_PROFILE_SPEED_VERY_FAST	2
# define LEM_IPC_PROFILE_SPEED_MEDIUM_FAST	3
# define LEM_IPC_PROFILE_SPEED_FAST			4
# define LEM_IPC_PROFILE_SPEED_LITTLE_FAST	5
# define LEM_IPC_PROFILE_SPEED_ONE			6
# define LEM_IPC_PROFILE_SPEED_LITTLE_SLOW	7
# define LEM_IPC_PROFILE_SPEED_SLOW			8
# define LEM_IPC_PROFILE_SPEED_MEDIUM_SLOW	9
# define LEM_IPC_PROFILE_SPEED_VERY_SLOW	10
# define LEM_IPC_PROFILE_SPEED_HIGHLY_SLOW	11

#endif // LEM_IPC_PROFILE_DEFINE_H