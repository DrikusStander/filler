/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 15:53:37 by hstander          #+#    #+#             */
/*   Updated: 2017/07/07 13:44:35 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "./libft/libft.h"

typedef struct	s_game
{
	int			player;
	char		**board;
	char		**token;
	char 		*temp;
	int			b_x;
	int			b_y;
	int			t_x;
	int			t_y;
}				t_game;

typedef	struct	s_var
{
	char		*line;
	int			fd;
	int			s_x;
	int			s_y;
	int			overlap;
}				t_var;

void    translate_xy(t_game *game, char *buff);
void    get_board_xy(t_game *game, t_var *var);
void    get_board(t_game *game, t_var *var);
void    get_token_xy(t_game *game, t_var *var);
void    get_token(t_game *game, t_var *var);
void    get_player(t_game *game, t_var *var);

#endif
