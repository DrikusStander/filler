/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 17:43:30 by hstander          #+#    #+#             */
/*   Updated: 2017/07/09 14:09:53 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_board_xy(t_game *game, t_var *var)
{
	char	*buff;

	get_next_line(var->fd, &var->line);
	buff = var->line;
	while (*buff)
		buff++;
	buff--;
	while (*buff)
	{
		if ((ft_isdigit(*buff) == 1) && (ft_isdigit(*(buff - 1)) == 0))
			break ;
		buff--;
	}
	game->b_y = ft_atoi(buff);
	buff--;
	while (*buff)
	{
		if ((ft_isdigit(*buff) == 1) && (ft_isdigit(*(buff - 1)) == 0))
			break ;
		buff--;
	}
	game->b_x = ft_atoi(buff);
	free(var->line);
}

void	get_player(t_game *game, t_var *var)
{
	char	*temp;

	get_next_line(var->fd, &var->line);
	if ((temp = ft_strchr(var->line, '1')) != NULL)
		game->player = ft_atoi(temp);
	else if ((temp = ft_strchr(var->line, '2')) != NULL)
		game->player = ft_atoi(temp);
	free(var->line);
}

void	get_board(t_game *game, t_var *var)
{
	int		i;

	i = 0;
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
