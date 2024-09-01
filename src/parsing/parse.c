/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:01:15 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/01 17:45:27 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

t_bool			IS_GRAPHICAL = FALSE;
t_bool			IS_GRAPHICAL_TEXT = FALSE;
t_lem_team_id	TEAM_ID = 0;
t_algo_id		AI_ID = 0;

t_str_algo_func_node	AI_ID_LIST[NB_ALGO] = {
	// Player algo
	/// Default algo, random move
	{"random",	random_move},
	/// Move to the nearest enemy
	{"easy",	loop_easy},
	/// Move to the nearest ally and then do low algo
	{"medium",	loop_medium},
	/// Medium algo with msq communication
	{"hard",	loop_hard},
	// Debug algo
	{"up",		up_move},
	{"down",	down_move},
	{"right",	right_move},
	{"left",	left_move},
};

t_lem_team_id	get_team_id(void)
{
	t_opt_value		*ptr;
	t_lem_team_id	team_id;
	int				has_overflow;
	t_opts			*opts;

	opts = ft_get_opts(0);
	if (ft_opts_len(opts) < 1)
	{
		ft_perr("1 or 2 arg is expected\n");
		return (ERR_PARSING);
	}
	ptr = opts->value;
	if (!ptr || !ptr->value)
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

t_algo_id translate_algo_id(char *algo_id_str)
{
	t_algo_id	counter;

	counter = 0;
	while (counter < NB_ALGO)
	{
		if (!ft_strcmp(AI_ID_LIST[counter].str, algo_id_str))
			return (counter);
		counter++;
	}
	return (RANDOM);
}

t_bin get_ai(void)
{
	t_opt_value		*ptr;

	ptr = ft_get_opts(0)->value;
	if (!ptr->next || !ptr->next->value)
	{
		AI_ID = AI_ID_DEFAULT;
		return (SUCCESS);
	}
	AI_ID = translate_algo_id(ptr->next->value);
	if (AI_ID < 0)
	{
		ft_perr("Enter a valid team id\n");
		return (ERR_PARSING);
	}
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
	if (get_ai())
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
