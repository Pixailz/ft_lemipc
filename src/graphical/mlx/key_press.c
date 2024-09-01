/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:29:30 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/01 17:43:26 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

t_bool			IS_ESCAPE = FALSE;

# define		NB_KEY_CODE_TO_STR	3

t_str_int_node	KEY_CODE_TO_STR[NB_KEY_CODE_TO_STR] = {
	{FT_NULL,		0},
	{"ESC",		KEY_ESC},
	{"SPACE",	KEY_SPACE},
};

char	*key_code_to_str(int key_code)
{
	int	i;

	i = 0;
	while (i < NB_KEY_CODE_TO_STR)
	{
		if (KEY_CODE_TO_STR[i].nb == key_code)
			return (KEY_CODE_TO_STR[i].str);
		i++;
	}
	return (FT_NULL);
}

int	key_press(int key_code, void *mlx)
{
	char	*key_str;

	(void)mlx;
	key_str = key_code_to_str(key_code);
	if (key_str == FT_NULL)
		print_mlx_log("[KEY_PRESS]: %#06x", key_code);
	else
		print_mlx_log("[KEY_PRESS]: %#06x (%s)", key_code, key_str);
	return (0);
}

int	key_release(int key_code, void *mlx)
{
	if (key_code == KEY_ESC)
		return (end_hook(mlx));
	if (key_code == KEY_SPACE)
		lemipc_pause_toggle();
	return (0);
}

int	end_hook(void *mlx)
{
	IS_ESCAPE = TRUE;
	mlx_loop_end(mlx);
	return (0);
}