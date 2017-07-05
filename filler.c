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

void	get_start_pos(t_game *game, t_var *var)
{
	while (game->board[var->s_x])
	{	
		while (game->board[var->s_x][var->s_y])
		{	
			if (game->board[var->s_x][var->s_y] == 'X')
				break;
			var->s_y++;
		}
		if (game->board[var->s_x][var->s_y] == 'X')
			break;
		var->s_y = 0;
		var->s_x++;
	}
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
	get_start_pos(&game, &var);


	int a = 0;
	int b = 0;
	int x = var.s_x;
	int y = var.s_y;
	while (game.token[a])
	{	
		while (game.token[a][b])
		{
			if (game.token[a][b] == '*')
			{
				
			}
			else 
				b++;	
		{
		b = 0;
		a++;
	}






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
