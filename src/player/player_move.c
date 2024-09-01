/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:14:53 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/31 19:53:41 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern t_pos				POS;
extern t_lem_team_id		TEAM_ID;
extern t_lem_player_id		MY_ID;
extern t_bool				IS_SIGINT;

t_bool	player_move(t_dir dir)
{
	t_pos	tmp;
	t_tile	*board;

	tmp = POS;
	if (dir == UP)
		tmp.y--;
	else if (dir == RIGHT)
		tmp.x++;
	else if (dir == DOWN)
		tmp.y++;
	else if (dir == LEFT)
		tmp.x--;
	if (tmp.x < 0 || tmp.x >= LEM_IPC_BOARD_LEN_X ||
		tmp.y < 0 || tmp.y >= LEM_IPC_BOARD_LEN_Y)
	{
		ft_printf("OUT OF BOUNDS MOVE\n");
		return (FALSE);
	}
	board = get_board();
	if (check_death(POS, board))
		return (TRUE);
	if (board[tmp.x + (tmp.y * LEM_IPC_BOARD_LEN_X)].player_id)
	{
		ft_printf("COLLISION\n");
		return (FALSE);
	}
	set_board_move(POS, tmp, (t_tile){TEAM_ID, MY_ID});
	POS = tmp;
	return (TRUE);
}

void	ensure_player_move(t_dir dir)
{
	while (!IS_SIGINT)
	{
		if (player_move(dir))
			break ;
		if (player_move(ft_randint(0, 4)))
			break ;
		usleep(A_SEC / 1000);
	}
}