/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:01:15 by brda-sil          #+#    #+#             */
/*   Updated: 2024/06/16 16:17:19 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

t_bool			IS_GRAPHICAL = FALSE;
t_bool			IS_GRAPHICAL_TEXT = FALSE;
t_lem_team_id	TEAM_ID = 0;

t_lem_team_id	get_team_id(void)
{
	t_opt_value		*ptr;
	t_lem_team_id	team_id;
	int				has_overflow;
	t_opts			*opts;

	opts = ft_get_opts(0);
	if (ft_opts_len(opts) != 1)
	{
		ft_perr("Only one arg is needed\n");
		return (ERR_PARSING);
	}
	ptr = opts->value;
	if (!ptr || !ptr->value || (ptr->next && ptr->next->value))
	{
		ft_perr("Unknown\n");
		return (ERR_PARSING);
	}

	team_id = ft_patoi(ptr->value, &has_overflow);
	if (has_overflow || team_id < 1 || team_id > LEM_IPC_NB_TEAM)
	{
		ft_perr("Enter a valid team id\n");
		return (ERR_PARSING);
	}
	TEAM_ID = team_id;
	return (SUCCESS);
}

t_bin	post_parse_grapical(void)
{
	if (ft_optget("text")->is_present)
		IS_GRAPHICAL_TEXT = TRUE;
	return (SUCCESS);
}

t_bin	post_parse_player(void)
{
	if (get_team_id())
		return (ERR_PARSING);
	return (SUCCESS);
}

t_bin	post_parse(void)
{
	if (ft_optget("graphical")->is_present)
		IS_GRAPHICAL = TRUE;
	if (IS_GRAPHICAL)
		return (post_parse_grapical());
	else
		return (post_parse_player());
	return (0);
}

t_bin	parse_opts(int ac, char **av)
{
	ft_optadd_cmd("help", '?', help);
	ft_optadd_cmd("usage", 0, usage);
	ft_optadd("verbose", 'v', OPT_FLAG);
	ft_optadd("graphical", 'G', OPT_FLAG);
	ft_optadd("text", 't', OPT_FLAG);
	ft_optparse(ac, av);
	return (ft_opt_post_parse(post_parse));
}
