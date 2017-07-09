/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_start_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 13:17:52 by hstander          #+#    #+#             */
/*   Updated: 2017/07/09 13:49:59 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_start_pos(t_game *game, t_var *var)
{
	char	token;

	if (game->player == 1)
		token = 'O';
	if (game->player == 2)
		token = 'X';
	var->s_x = 0;
	var->s_y = 0;
	while (game->board[var->s_x])
	{
		while (game->board[var->s_x][var->s_y])
		{
			if (game->board[var->s_x][var->s_y] == token)
				break ;
			var->s_y++;
		}
		if (game->board[var->s_x][var->s_y] == token)
			break ;
		var->s_y = 0;
		var->s_x++;
	}
}

void	free_mem(t_game *game)
{
	int		i;

	i = 0;
	while (game->board[i])
	{
		free(game->board[i]);
		i++;
	}
	free(game->board);
	i = 0;
	while (game->token[i])
	{
		free(game->token[i]);
		i++;
	}
	free(game->token);
}
