/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:29:30 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/01 15:42:27 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

static void	put_nb_at(int nb, t_pos pos, int color)
{
	char	*tmp;

	tmp = ft_itoa(nb);
	pos.x += LEM_IPC_LEN_NB_TOTAL - ft_strlen(tmp);
	mlxput_text_at(tmp, color, pos, TRUE);
	free(tmp);
}

static void	put_nb(int last_nb, int new_nb, t_pos pos)
{
	if (last_nb != new_nb)
	{
		put_nb_at(last_nb, pos, LEM_IPC_LOG_BACK);
		put_nb_at(new_nb, pos, MLX_FONT_COLOR);
	}
}

void	mlx_log_put_total_nb(void)
{
	static int		last_nb = 0;
	static int		last_total_nb = 0;
	static t_pos	pos_nb = {-1, -1};
	static t_pos	pos_nb_total = {-1, -1};
	int				tmp;

	if (pos_nb.x == -1 && pos_nb.y == -1)
	{
		pos_nb.x = ft_strlen(LEM_IPC_NB_TOTAL) + 1;
		pos_nb.y = 0;
		pos_nb_total.x = pos_nb.x + LEM_IPC_LEN_NB_TOTAL + 1;
		pos_nb_total.y = pos_nb.y;
	}
	tmp = get_player_nb();
	put_nb(last_nb, tmp, pos_nb);
	last_nb = tmp;
	tmp = get_max_player_nb();
	put_nb(last_total_nb, tmp, pos_nb_total);
	last_total_nb = tmp;
}