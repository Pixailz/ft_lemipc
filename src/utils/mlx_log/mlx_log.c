/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 00:50:16 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/28 21:26:31 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern void*			MLX;
extern void*			WIN;
extern t_mlx_texture	SCENE_LOG;
extern t_pos			ORIGIN_LOG;
extern int				LEM_LOG_NB_LINE;

int	mlx_log_get_last_id(char **log_str)
{
	int	i;

	i = 0;
	while (log_str[i] != FT_NULL && i < LEM_LOG_NB_LINE)
		i++;
	return (i);
}

void	mlx_log_at(int lvl, char *msg, int color)
{
	lvl++;
	mlxput_text_at(msg, color, (t_pos){1, lvl + LEM_IPC_LOG_HEADER_SIZE}, FALSE);
}

void	mlx_log_move_up(char **log_str)
{
	int		i;
	int 	ii;

	i = 1;
	ii = i - 1;
	while (i < LEM_LOG_NB_LINE)
	{
		ii = i - 1;
		if (log_str[ii] != FT_NULL)
		{
			mlx_log_at(ii, log_str[ii], LEM_IPC_LOG_BACK);
			if (!ii)
				free(log_str[ii]);
		}
		if (log_str[i] != FT_NULL)
			mlx_log_at(ii, log_str[i], LEM_IPC_LOG_FONT_COLOR);
		log_str[ii] = log_str[i];
		i++;
	}
}

t_bool	mlx_log(char *msg)
{
	static	char**	log_str = FT_NULL;
	int				id;

	if (msg == FT_NULL)
	{
		mlx_log_free(log_str);
		return (TRUE);
	}
	if (log_str == FT_NULL)
	{
		init_log_str(&log_str);
		print_mlx_log("[MLX_LOG]: NB_LINE {%d}", LEM_LOG_NB_LINE);
		return (TRUE);
	}
	id = mlx_log_get_last_id(log_str);
	if (id == LEM_LOG_NB_LINE)
	{
		mlx_log_move_up(log_str);
		id--;
	}
	if (log_str[id] != FT_NULL)
		mlx_log_at(id, log_str[id], LEM_IPC_LOG_BACK);
	log_str[id] = ft_strdup(msg);
	mlx_log_at(id, log_str[id], LEM_IPC_LOG_FONT_COLOR);
	return (FALSE);
}

t_size	print_mlx_log(const char *format, ...)
{
	va_list	args;
	char	*ptr_buffer;
	t_size	ret;

	va_start(args, format);
	ret = ft_printf_parse(args, format);
	va_end(args);
	ptr_buffer = ft_printf_buff_get();
	ptr_buffer[ret] = 0;
	if (MLX && mlx_log(ptr_buffer))
	{
		va_start(args, format);
		ret = ft_printf_parse(args, format);
		va_end(args);
		ptr_buffer = ft_printf_buff_get();
		ptr_buffer[ret] = 0;
		mlx_log(ptr_buffer);
	}
	ft_putnstr_fd(ptr_buffer, ret, 1);
	ft_putchar_fd('\n', 1);
	return (ret);
}
