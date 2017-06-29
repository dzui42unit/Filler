/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 15:58:37 by dzui              #+#    #+#             */
/*   Updated: 2017/06/04 15:58:39 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FILLER_H
# define FILLER_FILLER_H
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include "./libft/get_next_line.h"
# include "./libft/ft_printf.h"
# include "./libft/libft.h"

typedef struct	s_filler
{
	int			x_size;
	int			y_size;
	char		player_sign;
	char		enemy_sign;
	char		**map;
	char		**figure;
	char		*buff;
	int			fig_size_x;
	int			fig_size_y;
	int			i;
	int			j;
	int			**path_map;
	int			x_short;
	int			y_short;
	int			place_x;
	int			place_y;
	int			fig_i;
	int			fig_j;
	int			counter;
	int			self_y;
	int			direction;
	int			touch;
	int			x_enemy;
	int			y_enemy;
	int			x_dir[8];
	int			y_dir[8];
	int			place_random;
}				t_filler;

typedef struct	s_path
{
	int			d;
	int			i;
	int			j;
	int			k;
	int			i_x;
	int			i_y;
	int			stop;
}				t_path;

typedef struct	s_palce
{
	int			i;
	int			j;
	int			k;
	int			l;
	int			overlap_field;
	int			i_x;
	int			i_y;
}				t_place;

void			ft_write_path_map_optimal_2(t_filler *player, int i, int j);
void			ft_write_path_map_corner_2(t_filler *player, int i, int j);
void			ft_write_path_map_optimal(t_filler *player);
void			ft_write_path_map_2(t_filler *player, int i, int j);
void			ft_get_map_size(t_filler *player, char *str);
void			ft_write_map(t_filler *player);
void			ft_choose_algo(t_filler *player);
void			ft_get_figure_size(t_filler *player, char *str);
void			ft_write_path_map(t_filler *player);
void			ft_write_figure(t_filler *player);
void			ft_alloc_maps(t_filler *player);
void			ft_free_fig(t_filler *player);
void			ft_find_myself(t_filler *player);
void			ft_write_path_map_corner(t_filler *player);
void			ft_set_values(t_filler *player);
int				ft_check_neighbours(t_filler *player, int i, int j);
int				ft_find_where_to_place(t_filler *player);
int				ft_can_place(t_filler *player);
int				ft_check_coord(t_filler *player, int i, int j);
int				ft_sign_neighbours(t_path *path, t_filler *player);
int				ft_check_place(t_filler *player, t_place *place);
int				ft_place_token(t_filler *player);
int				ft_is_touched(t_filler *player);
int				ft_place_random(t_filler *player);
int				ft_find_enemy(t_filler *player);
int				ft_check_place_2(t_filler *player, t_place *place);
int				ft_place_token_2(t_filler *player, t_place *place);
int				ft_place_random_2(t_filler *player);
int				ft_first_move(t_filler *player);
int				ft_start_fight(t_filler *player);
int				ft_try_point(t_filler *player, int i, int j);
int				get_red(int color);
int				get_green(int color);
int				get_blue(int color);
void			put_pixel_to_img(t_filler *world, int x, int y, int color);
void			img_clear(t_filler *world);
int				draw_board(t_filler *world);
int				draw_rect(t_filler *world, int i, int j, int color);

#endif
