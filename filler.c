/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 15:51:20 by dzui              #+#    #+#             */
/*   Updated: 2017/06/04 15:52:31 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_set_values(t_filler *player)
{
	player->x_dir[0] = 1;
	player->x_dir[1] = 0;
	player->x_dir[2] = -1;
	player->x_dir[3] = 0;
	player->x_dir[4] = 1;
	player->x_dir[5] = -1;
	player->x_dir[6] = 1;
	player->x_dir[7] = -1;
	player->y_dir[0] = 0;
	player->y_dir[1] = 1;
	player->y_dir[2] = 0;
	player->y_dir[3] = -1;
	player->y_dir[4] = 1;
	player->y_dir[5] = 1;
	player->y_dir[6] = -1;
	player->y_dir[7] = -1;
	player->i = 0;
	player->x_size = 0;
	player->y_size = 0;
	player->fig_size_x = 0;
	player->fig_size_y = 0;
	player->touch = 0;
}

int		ft_first_move(t_filler *player)
{
	ft_write_map(player);
	ft_write_figure(player);
	ft_find_myself(player);
	if (player->self_y > player->y_size / 2)
		player->direction = 0;
	else
		player->direction = 1;
	if (player->x_size == 100)
		ft_write_path_map_corner(player);
	else
	{
		if (ft_find_enemy(player))
			ft_write_path_map_optimal(player);
		else
			ft_write_path_map(player);
	}
	if (ft_can_place(player))
		ft_printf("%d %d\n", player->place_x, player->place_y);
	else
	{
		ft_printf("0 0\n");
		return (0);
	}
	return (1);
}

int		ft_start_fight(t_filler *player)
{
	while (1)
	{
		get_next_line(0, &player->buff);
		get_next_line(0, &player->buff);
		ft_write_map(player);
		ft_write_figure(player);
		if (ft_can_place(player))
		{
			ft_printf("%d %d\n", player->place_x, player->place_y);
			ft_free_fig(player);
		}
		else
		{
			ft_free_fig(player);
			ft_printf("0 0\n");
			return (0);
		}
	}
}

int		main(void)
{
	t_filler player;

	ft_set_values(&player);
	player.buff = ft_strnew(BUFF_SIZE);
	get_next_line(0, &(player.buff));
	if (ft_strchr(player.buff, '1'))
	{
		player.player_sign = 'o';
		player.enemy_sign = 'x';
	}
	else
	{
		player.enemy_sign = 'o';
		player.player_sign = 'x';
	}
	get_next_line(0, &(player.buff));
	ft_get_map_size(&player, player.buff);
	get_next_line(0, &(player.buff));
	ft_alloc_maps(&player);
	if (!ft_first_move(&player))
		return (0);
	ft_start_fight(&player);
	return (0);
}
