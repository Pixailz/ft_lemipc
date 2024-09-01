/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:47:40 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/31 17:57:51 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

static void	text_print_player_nb(void)
{
	t_lem_player_id	n;
	t_lem_player_id	max;

	n = get_player_nb();
	max = get_max_player_nb();
	ft_printf("PLAYERS (%d/%d)\n", n, max);
}

static void	text_print_teams(t_tile *board)
{
	int	i;
	int	player_nb[9] = {0};

	i = 0;
	while (i < LEM_IPC_BOARD_LEN)
	{
		if (board[i].team_id)
			player_nb[board[i].team_id]++;
		i++;
	}
	i = 0;
	while (i < LEM_IPC_NB_TEAM)
	{
		i++;
		ft_printf("TEAM %s%d%s: " BOL "%d" RBOL "\n",
			text_get_team_color(i), i, RST, player_nb[i]);
	}
}

void	graphical_text_print_stat(t_tile *board)
{
	text_print_player_nb();
	text_print_teams(board);
}
