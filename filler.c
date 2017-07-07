/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 14:58:34 by hstander          #+#    #+#             */
/*   Updated: 2017/07/07 15:37:51 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <fcntl.h>
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
	if (x >= game->b_x || y >= game->b_y)
	   return (-1);	
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
	
	var->overlap = 0;	
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
	if (var->overlap != 1)
		return (0);
	return (1);
}
/*
int		place_token(t_game *game, t_var *var, int x, int y)
{
	int ret = 0;
	while (game->board[x])
	{
		while (game->board[x][y])
		{
			if ((ret = check_token(game, var, x, y)) == 1)
			{
				//printf("%d %d\n", x, y);
				var->s_x = x;
				var->s_y = y;
				return (1);
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (0);
}
*/
int		place_token(t_game *game, t_var *var, int x, int y)
{
	int ret = 0;
	while (x >= 0)
	{
		while (y >= 0)
		{
			if ((ret = check_token(game, var, x, y)) == 1)
			{
				//printf("%d %d\n", x, y);
				var->s_x = x;
				var->s_y = y;
				return (1);
			}
			y--;
		}
		y = (game->b_y - 1);
		x--;
	}
	return (0);
}


int		main(void)
{
	t_game	game;
	t_var	var;
	int 	i;
	int ret;

	ret = 2;
		ft_bzero(&var, sizeof(t_var));
		var.fd = 0;
		get_player(&game, &var);
/*		get_board_xy(&game, &var);
		get_board(&game, &var);
		get_token_xy(&game, &var);	
		get_token(&game, &var);
		get_start_pos(&game, &var);
*/
		int fd;
		fd = open("test.txt", O_WRONLY);
	while (1)
{

		ft_putstr_fd("start of loop\n", 2);
		get_board_xy(&game, &var);
		ft_putstr_fd("get board xy\n", 2);
		get_board(&game, &var);
		ft_putstr_fd("get board\n", 2);
		get_token_xy(&game, &var);
		ft_putstr_fd("get token xy\n", 2);
		get_token(&game, &var);
		ft_putstr_fd("get token\n", 2);
	//	get_start_pos(&game, &var);

		ft_putstr_fd("test", fd);
	
		ret = place_token(&game, &var, (game.b_x - 1), (game.b_y - 1));
		ft_putstr_fd("place token\n", 2);
		if (ret == 1 )
		{
			ft_putstr_fd("ret = 1\n", 2);
			 dprintf(1, "%d %d\n", var.s_x, var.s_y);
			 dprintf(2, "%d %d\n", var.s_x, var.s_y);
		}
		 if (ret == 0)
		{	
		   	ft_putstr_fd("ret = 0\n", 2);
			printf("%d %d\n", 0, 0);
			break;
		}	

 
/*	unsigned long kk = 0;
	while (kk < 999999)
	{
		kk++;
	}
*/
		i = 0;
		while (game.board[i])
		{
		   	ft_putstr_fd("free board\n", 2);
			free(game.board[i]);
			i++;
		}
		free(game.board);

		i = 0;
		while (game.token[i])
		{
		   	ft_putstr_fd("free token\n", 2);
			free(game.token[i]);
			i++;
		}
		free(game.token);
//		get_board_xy(&game, &var);
//		get_board(&game, &var);
//		get_token_xy(&game, &var);
//		get_token(&game, &var);
		ft_putstr_fd("end of loop\n", 2);



	}
		return (0);
}
