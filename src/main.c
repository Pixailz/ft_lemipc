/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 03:26:32 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/12 15:28:19 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern	t_bool	IS_GRAPHICAL;
extern	t_bool	IS_GRAPHICAL_TEXT;

t_bool			OPT_EXECUTED = FALSE;

t_bin	init(int ac, char **av)
{
	int	retv;

	retv = parse_opts(ac, av);
	if (retv == BIT_01)
	{
		OPT_EXECUTED = TRUE;
		return (ft_opt_exec_cmd());
	}
	else if (retv != SUCCESS)
		return (retv);
	if ((retv = init_prog()))
		return (retv);
	return (retv);
}

t_bin	run(void)
{
	int	retv;

	if (IS_GRAPHICAL)
	{
		if (IS_GRAPHICAL_TEXT)
			retv = run_graphical_text();
		else
			retv = run_graphical_mlx();
	}
	else
	{
		retv = run_player();
	}
	return (retv);
}

int	main(int ac, char **av)
{
	char	retv = 0;

	if ((retv = init(ac, av)))
		return (retv);
	if (OPT_EXECUTED)
		return (retv);
	if ((retv = run()))
		return (retv);
	// debug_msq(ac, av);
	free_prog();
	return (retv);
}
