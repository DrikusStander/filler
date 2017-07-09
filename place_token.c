/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 13:12:51 by hstander          #+#    #+#             */
/*   Updated: 2017/07/09 15:03:50 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		place_token_br(t_game *game, t_var *var, int x, int y)
{
	int		ret;

	ret = 0;
	while (x >= 0)
	{
		while (y >= 0)
		{
			if ((ret = check_token(game, var, x, y)) == 1)
			{
				ft_putnbr_fd(x, 1);
				ft_putchar_fd(' ', 1);
				ft_putnbr_fd(y, 1);
				ft_putchar_fd('\n', 1);
				return (1);
			}
			y--;
		}
		y = (game->b_y - 1);
		x--;
	}
	return (0);
}

int		place_token_bl(t_game *game, t_var *var, int x, int y)
{
	int		ret;

	ret = 0;
	while (x >= 0)
	{
		while (game->board[x][y])
		{
			if ((ret = check_token(game, var, x, y)) == 1)
			{
				ft_putnbr_fd(x, 1);
				ft_putchar_fd(' ', 1);
				ft_putnbr_fd(y, 1);
				ft_putchar_fd('\n', 1);
				return (1);
			}
			y++;
		}
		y = 0;
		x--;
	}
	return (0);
}

int		place_token_tr(t_game *game, t_var *var, int x, int y)
{
	int		ret;

	ret = 0;
	while (game->board[x])
	{
		while (y >= 0)
		{
			if ((ret = check_token(game, var, x, y)) == 1)
			{
				ft_putnbr_fd(x, 1);
				ft_putchar_fd(' ', 1);
				ft_putnbr_fd(y, 1);
				ft_putchar_fd('\n', 1);
				return (1);
			}
			y--;
		}
		y = (game->b_y - 1);
		x++;
	}
	return (0);
}

int		place_token_tl(t_game *game, t_var *var, int x, int y)
{
	int		ret;

	ret = 0;
	while (game->board[x])
	{
		while (game->board[x][y])
		{
			if ((ret = check_token(game, var, x, y)) == 1)
			{
				ft_putnbr_fd(x, 1);
				ft_putchar_fd(' ', 1);
				ft_putnbr_fd(y, 1);
				ft_putchar_fd('\n', 1);
				return (1);
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (0);
}
