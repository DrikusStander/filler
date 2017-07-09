/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 17:48:03 by hstander          #+#    #+#             */
/*   Updated: 2017/07/09 13:45:22 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_token_xy(t_game *game, t_var *var)
{
	char	*buff;

	get_next_line(var->fd, &var->line);
	game->temp = ft_strdup(var->line);
	buff = game->temp;
	free(var->line);
	while (ft_isdigit(*buff) == 0)
	{
		buff++;
	}
	game->t_x = ft_atoi(buff);
	while (*buff)
		buff++;
	while (1)
	{
		if ((ft_isdigit(*buff) == 1) && (ft_isdigit(*(buff - 1)) == 0))
			break ;
		buff--;
	}
	game->t_y = ft_atoi(buff);
	free(game->temp);
}

void	get_token(t_game *game, t_var *var)
{
	int		i;

	i = 0;
	game->token = (char **)ft_memalloc(sizeof(char *) * (game->t_x + 1));
	while (i < game->t_x)
	{
		get_next_line(var->fd, &var->line);
		game->token[i] = strdup(var->line);
		free(var->line);
		var->line = NULL;
		i++;
	}
}
