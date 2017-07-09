/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 15:53:37 by hstander          #+#    #+#             */
/*   Updated: 2017/07/09 16:08:07 by hstander         ###   ########.fr       */
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
	char		*temp;
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
	int			start;
	int			j;
}				t_var;

typedef struct	s_token
{
	char		mt;
	char		mt1;
	char		et;
	char		et1;
}				t_token;

void			translate_xy(t_game *game, char *buff);
void			get_board_xy(t_game *game, t_var *var);
void			get_board(t_game *game, t_var *var);
void			get_token_xy(t_game *game, t_var *var);
void			get_token(t_game *game, t_var *var);
void			get_player(t_game *game, t_var *var);
int				place_token_bl(t_game *game, t_var *var, int x, int y);
int				place_token_br(t_game *game, t_var *var, int x, int y);
int				place_token_tl(t_game *game, t_var *var, int x, int y);
int				place_token_tr(t_game *game, t_var *var, int x, int y);
int				check_token(t_game *game, t_var *var, int x, int y);
int				check_grid(t_game *game, t_var *var, int x, int y);
void			get_start_pos(t_game *game, t_var *var);
void			free_mem(t_game *game);
int				place_all(t_game *game, t_var *var);
void			get_game(t_game *game, t_var *var);

#endif
