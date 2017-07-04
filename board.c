/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 17:43:30 by hstander          #+#    #+#             */
/*   Updated: 2017/07/04 17:47:29 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void    translate_xy(t_game *game, char *buff)
{
	while (*buff)
		buff++;
	buff--;
	while (*buff)
	{
		if ((ft_isdigit(*buff) == 1) && (ft_isdigit(*(buff - 1)) == 0))
			break;
		buff--;
	}
	game->b_y = ft_atoi(buff);
	buff--;
	while (*buff)
	{
		if ((ft_isdigit(*buff) == 1) && (ft_isdigit(*(buff - 1)) == 0))
			break;
		buff--;
	}
	game->b_x = ft_atoi(buff);
}

void    get_board_xy(t_game *game, t_var *var)
{
	char    *buff;
	int     i;

	buff = (char *)ft_memalloc(sizeof(char));
	i = 0;
	while (i < 2)
	{
		get_next_line(var->fd, &var->line);
		game->temp = ft_strjoin(buff, var->line);
		free(buff);
		free(var->line);
		buff = game->temp;
		i++;
	}
	translate_xy(game, buff);
	free(game->temp);
}


void    get_board(t_game *game, t_var *var)
{
	int     i;

	i =0;
	get_next_line(var->fd, &var->line);
	free(var->line);
	game->board = (char **)ft_memalloc(sizeof(char *) * (game->b_x + 2));
	while (i < game->b_x)
	{
		get_next_line(var->fd, &var->line);
		game->board[i] = strdup(&var->line[4]);
		free(var->line);
		var->line = NULL;
		i++;
	}
}
