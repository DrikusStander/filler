/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 14:58:34 by hstander          #+#    #+#             */
/*   Updated: 2017/07/04 17:50:09 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 09:04:58 by hstander          #+#    #+#             */
/*   Updated: 2017/07/04 14:58:09 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "filler.h"
#include <stdio.h>
/*
void	translate_xy(t_game *game, char *buff)
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

void	get_board_xy(t_game *game, t_var *var)
{
	char	*buff;
	int		i;

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

void	get_board(t_game *game, t_var *var)
{
	int		i;

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
*//*
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
				break;
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
*/
int		main(void)
{
	t_game	game;
	t_var	var;
	int 	i;

	i = 0;
	var.fd = 0;
	get_board_xy(&game, &var);
	get_board(&game, &var);
	get_token_xy(&game, &var);
	get_token(&game, &var);


	unsigned long k = 0;
	while (k < 1999999999)
	{
		k++;
	}
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(game.b_x, 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(game.b_y, 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(game.t_x, 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(game.t_y, 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);
	while (game.board[i])
	{
		ft_putstr_fd(game.board[i], 2);
		ft_putchar_fd('\n', 2);
		free(game.board[i]);
		i++;
	}
	i = 0;
	while (game.token[i])
	{
		ft_putstr_fd(game.token[i], 2);
		ft_putchar_fd('\n', 2);
		free(game.token[i]);
		i++;
	}
	return (0);
}
