/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:29:30 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/25 06:17:59 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

t_ai_id_list	KEY_CODE_TO_STR[] = {
	{KEY_ESC, "KEY_ESC"},
	{KEY_SPACE, "KEY_SPACE"},
	{0, FT_NULL}
};

char	*key_code_to_str(int key_code)
{
	int	i;

	i = 0;
	while (KEY_CODE_TO_STR[i].str)
	{
		if (KEY_CODE_TO_STR[i].id == key_code)
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
	mlx_loop_end(mlx);
	return (0);
}