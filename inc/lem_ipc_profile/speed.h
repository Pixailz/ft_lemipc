/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:14:17 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/02 20:44:52 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IPC_PROFILE_SPEED_H
# define LEM_IPC_PROFILE_SPEED_H

# if LEM_IPC_PROFILE_SPEED == LEM_IPC_PROFILE_SPEED_HIGHLY_FAST
# define 	LEM_IPC_FREQ	A_SEC / 50

# elif LEM_IPC_PROFILE_SPEED == LEM_IPC_PROFILE_SPEED_VERY_FAST
# define 	LEM_IPC_FREQ	A_SEC / 25

# elif LEM_IPC_PROFILE_SPEED == LEM_IPC_PROFILE_SPEED_MEDIUM_FAST
# define 	LEM_IPC_FREQ	A_SEC / 10

# elif LEM_IPC_PROFILE_SPEED == LEM_IPC_PROFILE_SPEED_FAST
# define 	LEM_IPC_FREQ	A_SEC / 5

# elif LEM_IPC_PROFILE_SPEED == LEM_IPC_PROFILE_SPEED_LITTLE_FAST
# define 	LEM_IPC_FREQ	A_SEC / 2

# elif LEM_IPC_PROFILE_SPEED == LEM_IPC_PROFILE_SPEED_ONE
# define 	LEM_IPC_FREQ	A_SEC

# elif LEM_IPC_PROFILE_SPEED == LEM_IPC_PROFILE_SPEED_LITTLE_SLOW
# define 	LEM_IPC_FREQ	A_SEC * 2

# elif LEM_IPC_PROFILE_SPEED == LEM_IPC_PROFILE_SPEED_SLOW
# define 	LEM_IPC_FREQ	A_SEC * 5

# elif LEM_IPC_PROFILE_SPEED == LEM_IPC_PROFILE_SPEED_MEDIUM_SLOW
# define 	LEM_IPC_FREQ	A_SEC * 10

# elif LEM_IPC_PROFILE_SPEED == LEM_IPC_PROFILE_SPEED_VERY_SLOW
# define 	LEM_IPC_FREQ	A_SEC * 25

# elif LEM_IPC_PROFILE_SPEED == LEM_IPC_PROFILE_SPEED_HIGHLY_SLOW
# define 	LEM_IPC_FREQ	A_SEC * 50

# endif

#endif // LEM_IPC_PROFILE_SPEED_H