/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 13:14:14 by hstander          #+#    #+#             */
/*   Updated: 2017/07/09 14:08:09 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	player_token(t_game *game, t_token *token)
{
	if (game->player == 1)
	{
		token->mt = 'o';
		token->mt1 = 'O';
		token->et = 'x';
		token->et1 = 'X';
	}
	if (game->player == 2)
	{
		token->mt = 'x';
		token->mt1 = 'X';
		token->et = 'o';
		token->et1 = 'O';
	}
}

int		check_grid(t_game *game, t_var *var, int x, int y)
{
	t_token	tk;

	player_token(game, &tk);
	if ((x >= game->b_x || y >= game->b_y))
		return (-1);
	if (game->board[x][y] == tk.et || game->board[x][y] == tk.et1)
		return (-1);
	if (game->board[x][y] == tk.mt || game->board[x][y] == tk.mt1)
	{
		var->overlap++;
		return (1);
	}
	return (0);
}

int		check_token(t_game *game, t_var *var, int x, int y)
{
	int		a;
	int		b;

	var->overlap = 0;
	a = 0;
	b = 0;
	while (game->token[a])
	{
		while (game->token[a][b])
		{
			if (game->token[a][b] == '*')
			{
				if (((check_grid(game, var, (x + a), (y + b))) == -1) ||
					(var->overlap > 1))
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
