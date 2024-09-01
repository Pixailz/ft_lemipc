/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:10:59 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/31 18:09:51 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

// # define T_E			"⠀"
# define T_E			" "
// # define T_F			"⣿"
// # define T_U			"⠛"
// # define T_D			"⣿"
// # define T_C			"⠶"
// # define T_C			"•"
# define T_C			"█"

# define T_B_UL			"╭"
# define T_B_UR			"╮"
# define T_B_DL			"╰"
# define T_B_DR			"╯"
# define T_B_HO			"─"
# define T_B_VE			"│"

# define LEN_LINE		(LEM_IPC_BOARD_LEN_X + 2) * (LEM_IPC_BOARD_LEN_X + 2) * 24

extern t_bool			IS_SIGINT;

t_size	print_tile_color(t_lem_team_id team_id, char *line)
{

	char	*ptr;
	t_size	len;
	ptr = text_get_team_color(team_id);
	len = ft_strlen(ptr);
	ft_memcpy(line, ptr, len);
	return (len);
}

t_size	print_tile_char(t_lem_player_id player_id, char *line)
{
	t_size	len1;
	t_size	len2;
	char	*ptr;

	len2 = 0;
	if (player_id)
		ptr = T_C;
	else
		ptr = T_E;
	len1 = ft_strlen(ptr);
	ft_memcpy(line, ptr, len1);
	if (player_id)
	{
		line = &line[len1];
		len2 = ft_strlen(RSTDIM);
		ft_memcpy(line, RSTDIM, len2);
	}
	return (len1 + len2);
}

t_size	print_tile(t_tile tile, char *line)
{
	t_size	len;

	len = 0;
	if (tile.player_id)
	{
		len = print_tile_color(tile.team_id, line);
		line = &line[len];
	}
	len += print_tile_char(tile.player_id, line);
	return (len);
}

t_size	print_border(int cx, int cy, char *line, int *i)
{
	char	*ptr;
	t_size	len;

	line = &line[*i];
	ptr = FT_NULL;
	if (!cy && !cx)
		ptr = T_B_UL;
	else if (!cy && cx == LEM_IPC_BOARD_LEN_X + 1)
		ptr = T_B_UR;
	else if (cy == LEM_IPC_BOARD_LEN_Y + 1 && !cx)
		ptr = T_B_DL;
	else if (cy == LEM_IPC_BOARD_LEN_Y + 1 && cx == LEM_IPC_BOARD_LEN_X + 1)
		ptr = T_B_DR;
	else if (!cy || cy == LEM_IPC_BOARD_LEN_Y + 1)
		ptr = T_B_HO;
	else if (!cx || cx == LEM_IPC_BOARD_LEN_X + 1)
		ptr = T_B_VE;

	len = ft_strlen(ptr);
	if (len)
		ft_memcpy(line, ptr, len);
	*i += len;
	return (len);
}

void	render_map(t_tile *map)
{
	char	board[LEN_LINE] = {0};
	int		i;
	int		cx;
	int		cy;

	cy = 0;
	i = 0;
	while (cy < LEM_IPC_BOARD_LEN_Y + 2)
	{
		cx = 0;
		while (cx < LEM_IPC_BOARD_LEN_X + 2)
		{
			if (!print_border(cx, cy, &board[0], &i))
				i += print_tile(
					map[(cx - 1) + (cy - 1) * LEM_IPC_BOARD_LEN_X],
					&board[0] + i
				);
			cx++;
		}
		board[i++] = '\n';
		cy++;
	}
	ft_putstr_fd(board, 1);
}

t_error	run_graphical_text(void)
{
	t_uint64	i = 0;
	t_tile		*board;

	while (!IS_SIGINT)
	{
		check_for_player();
		ft_putstr_fd(CSI "H" CSI "J", 1);
		ft_printf("frame %d\n", i++);
		board = get_board();
		render_map(board);
		graphical_text_print_stat(board);
		usleep(A_SEC / LEM_IPC_GRAPH_FPS_TEXT);
	}
	return (SUCCESS);
}
