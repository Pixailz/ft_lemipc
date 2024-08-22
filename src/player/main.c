/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:30:56 by brda-sil          #+#    #+#             */
/*   Updated: 2024/06/17 13:49:38 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

extern t_ai_id AI_ID;

t_error	run_player(void)
{
	switch (AI_ID)
	{
		case (RANDOM):
			loop_random(); break ;
		case (LOW):
			loop_low(); break ;
	}
	return (SUCCESS);
}
