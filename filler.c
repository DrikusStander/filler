/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 14:58:34 by hstander          #+#    #+#             */
/*   Updated: 2017/07/09 16:29:05 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <fcntl.h>
#include "filler.h"
#include <stdio.h>

void	get_game(t_game *game, t_var *var)
{
	get_board_xy(game, var);
	get_board(game, var);
	get_token_xy(game, var);
	get_token(game, var);
	if (var->start == 0)
	{
		get_start_pos(game, var);
		var->j = game->b_x;
		var->start = 1;
	}
}

int		place_all(t_game *game, t_var *var)
{
	int		ret;

	ret = 0;
	if (var->j < 1)
	{
		if (var->s_y < (game->b_y / 2))
			ret = place_token_tr(game, var, 0, (game->b_y - 1));
		else
			ret = place_token_bl(game, var, (game->b_x - 1), 0);
		var->j++;
	}
	else if (var->j > 0)
	{
		if (var->s_y < (game->b_y / 2))
			ret = place_token_br(game, var, (game->b_x - 1), (game->b_y - 1));
		else
			ret = place_token_tl(game, var, 0, 0);
		var->j--;
	}
	return (ret);
}

int		main(void)
{
	t_game	game;
	t_var	var;
	int		ret;

	ft_bzero(&var, sizeof(t_var));
	get_player(&game, &var);
	while (1)
	{
		get_game(&game, &var);
		ret = place_all(&game, &var);
		if (ret == 0)
		{
			free_mem(&game);
			ft_putnbr_fd(0, 1);
			ft_putchar_fd(' ', 1);
			ft_putnbr_fd(0, 1);
			ft_putchar_fd('\n', 1);
			break ;
		}
		free_mem(&game);
		if (ret == 0)
			break ;
	}
	return (0);
}
