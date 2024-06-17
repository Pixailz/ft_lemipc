/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 03:26:32 by brda-sil          #+#    #+#             */
/*   Updated: 2024/06/16 17:40:54 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern	t_bool	IS_GRAPHICAL;
extern	t_bool	IS_GRAPHICAL_TEXT;

t_bin	run(int ac, char **av)
{
	int	ret;

	ret = parse_opts(ac, av);
	if (ret == BIT_01)
		return (ft_opt_exec_cmd());
	else if (ret != SUCCESS)
		return (ret);
	if ((ret = init_prog()))
		return (ret);
	if (IS_GRAPHICAL)
	{
		if (IS_GRAPHICAL_TEXT)
			ret = run_graphical_text();
		else
			ret = run_graphical_mlx();
	}
	else
	{
		ret = run_player();
	}
	return (ret);
}

int	main(int ac, char **av)
{
	char	ret = 0;

	ret = run(ac, av);
	free_prog();
	return (ret);
}
