/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:47:40 by brda-sil          #+#    #+#             */
/*   Updated: 2024/06/17 11:11:35 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

static void	text_print_nb_player(void)
{
	t_lem_player_id	n;
	t_lem_player_id	max;

	n = get_nb_player();
	max = get_max_nb_player();
	ft_printf("PLAYERS (%d/%d)\n", n, max);
}

static void	text_print_teams(t_tile *board)
{
	int	i;
	int	nb_player[9] = {0};

	i = 0;
	while (i < LEM_IPC_BOARD_LEN)
	{
		if (board[i].team_id)
			nb_player[board[i].team_id]++;
		i++;
	}
	i = 0;
	while (i < LEM_IPC_NB_TEAM)
	{
		i++;
		ft_printf("TEAM %s%d%s: " BOL "%d" RBOL "\n",
			text_get_team_color(i), i, RST, nb_player[i]);
	}
}

void	graphical_text_print_stat(t_tile *board)
{
	text_print_nb_player();
	text_print_teams(board);
}
