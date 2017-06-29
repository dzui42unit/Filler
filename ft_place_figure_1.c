/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_figure_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 17:03:29 by dzui              #+#    #+#             */
/*   Updated: 2017/06/04 15:55:51 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#include "filler.h"

int		ft_place_random(t_filler *pl)
{
	pl->i = 0;
	while (pl->map[pl->i])
	{
		pl->j = 0;
		while (pl->map[pl->i][pl->j])
		{
			if ((pl->map[pl->i][pl->j] == pl->player_sign
				|| pl->map[pl->i][pl->j] == ft_toupper(pl->player_sign))
				&& ft_check_neighbours(pl, pl->i, pl->j))
			{
				if (ft_place_random_2(pl))
					return (1);
			}
			pl->j++;
		}
		pl->i++;
	}
	return (0);
}

int		ft_place_random_2(t_filler *player)
{
	int i;
	int j;

	i = 0;
	while (player->figure[i])
	{
		j = 0;
		while (player->figure[i][j])
		{
			if (player->figure[i][j] == '*')
			{
				player->fig_i = i;
				player->fig_j = j;
				player->x_short = player->i;
				player->y_short = player->j;
				if (ft_place_token(player))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_can_place(t_filler *player)
{
	int i;
	int j;

	ft_choose_algo(player);
	while (ft_find_where_to_place(player))
	{
		i = 0;
		while (player->figure[i])
		{
			j = 0;
			while (player->figure[i][j])
			{
				if (ft_try_point(player, i, j))
					return (1);
				j++;
			}
			i++;
		}
		player->map[player->x_short][player->y_short] = '!';
		ft_choose_algo(player);
	}
	if (ft_place_random(player))
		return (1);
	return (0);
}

int		ft_try_point(t_filler *player, int i, int j)
{
	if (player->figure[i][j] == '*')
	{
		player->fig_i = i;
		player->fig_j = j;
		if (ft_place_token(player))
			return (1);
	}
	return (0);
}

void	ft_choose_algo(t_filler *player)
{
	if (player->x_size > 24)
	{
		if (ft_is_touched(player))
			player->touch = 1;
		if (!player->touch)
			ft_write_path_map_corner(player);
		else if (ft_find_enemy(player))
			ft_write_path_map_optimal(player);
		else
			ft_write_path_map(player);
	}
	else
	{
		if (ft_find_enemy(player))
			ft_write_path_map_optimal(player);
		else
			ft_write_path_map(player);
	}
}
