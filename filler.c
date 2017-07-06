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

#include "./libft/libft.h"
#include "filler.h"
#include <stdio.h>

void	get_start_pos(t_game *game, t_var *var)
{
	while (game->board[var->s_x])
	{	
		while (game->board[var->s_x][var->s_y])
		{	
			if (game->board[var->s_x][var->s_y] == 'O')
				break;
			var->s_y++;
		}
		if (game->board[var->s_x][var->s_y] == 'O')
			break;
		var->s_y = 0;
		var->s_x++;
	}
}

int	check_grid(t_game *game, t_var *var, int x, int y)
{
	if (game->board[x][y] == 'x' || game->board[x][y] == 'X')
		return (-1);
	else if (game->board[x][y] == 'o' || game->board[x][y] == 'O')
	{
		var->overlap++;
		return (1);
	}
	else
		return (0);
}

int		check_token(t_game *game, t_var *var, int x, int y)
{
	int a = 0;
	int b = 0;
//	int x = var->s_x;
//	int y = var->s_y;
	int ret = 0;
	
	while (game->token[a])
	{	
		while (game->token[a][b])
		{
			if (game->token[a][b] == '*')
			{
				ret = check_grid(game, var, (x + a), (y + b));
				if (ret == -1 || var->overlap > 1)
					return (0);
			} 
			b++;	
		}
		b = 0;
		a++;
	}
	if (var->overlap == 0)
		return (0);
	else
		return (1);
}

int		main(void)
{
	t_game	game;
	t_var	var;
	int 	i;
	
	i = 0;
	ft_bzero(&var, sizeof(t_var));
	var.fd = 0;
	get_board_xy(&game, &var);
	get_board(&game, &var);
	get_token_xy(&game, &var);
	get_token(&game, &var);
//	get_start_pos(&game, &var);
	
	int x = 0;
	int y = 0;
	int ret = 0;
	while (game.board[x])
	{
		while (game.board[x][y])
		{
			if ((ret = check_token(&game, &var, x, y)) == 1)
			{
				printf("%d %d\n", x, y);
				break;
			}
			y++;
		}
		if (ret == 1)
			break;
		y = 0;
		x++;
	}
/*
	int a = 0;
	int b = 0;
	int x = var.s_x;
	int y = var.s_y;
	int ret = 0;
	
	while (game.token[a])
	{	
		while (game.token[a][b])
		{
			if (game.token[a][b] == '*')
			{
				ret = check_grid(&game, &var, (x + a), (y + b));
				if (ret == -1 || var->overlap > 1)
					return (0);
			}
			else 
				b++;	
		{
		b = 0;
		a++;
	}




*/
/*
	unsigned long kk = 0;
	while (kk < 1999999999)
	{
		kk++;
	}


	ft_putchar_fd(game.board[12][14], 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(var.s_x, 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(var.s_y, 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(game.t_x, 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(game.t_y, 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);
*/
	while (game.board[i])
	{
//		ft_putstr_fd(game.board[i], 2);
//		ft_putchar_fd('\n', 2);
		free(game.board[i]);
		i++;
	}
	i = 0;
	while (game.token[i])
	{
//		ft_putstr_fd(game.token[i], 2);
//		ft_putchar_fd('\n', 2);
		free(game.token[i]);
		i++;
	}
	return (0);
}
