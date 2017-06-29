/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_path_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 17:37:05 by dzui              #+#    #+#             */
/*   Updated: 2017/06/03 17:37:19 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_write_path_map_optimal(t_filler *player)
{
	int i;
	int j;

	i = 0;
	while (player->map[i])
	{
		j = 0;
		while (player->map[i][j])
		{
			if (player->map[i][j] == '!')
				player->path_map[i][j] = -2;
			ft_write_path_map_optimal_2(player, i, j);
			j++;
		}
		i++;
	}
	player->path_map[player->x_enemy][player->y_enemy] = 0;
}

void	ft_write_path_map_optimal_2(t_filler *player, int i, int j)
{
	if (player->map[i][j] == player->player_sign
		|| player->map[i][j] == ft_toupper(player->player_sign))
	{
		if (ft_check_neighbours(player, i, j))
			player->path_map[i][j] = -3;
		else
			player->path_map[i][j] = -2;
	}
	if (((player->map[i][j] == player->enemy_sign
		|| player->map[i][j] == ft_toupper(player->enemy_sign)))
		|| player->map[i][j] == '.')
		player->path_map[i][j] = -1;
}

void	ft_write_path_map(t_filler *player)
{
	int i;
	int j;

	i = 0;
	while (player->map[i])
	{
		j = 0;
		while (player->map[i][j])
		{
			if (player->map[i][j] == '!')
				player->path_map[i][j] = -2;
			if (player->map[i][j] == player->enemy_sign
				|| player->map[i][j] == ft_toupper(player->enemy_sign))
			{
				if (ft_check_neighbours(player, i, j))
					player->path_map[i][j] = 0;
				else
					player->path_map[i][j] = -2;
			}
			ft_write_path_map_2(player, i, j);
			j++;
		}
		i++;
	}
}

void	ft_write_path_map_2(t_filler *player, int i, int j)
{
	if (player->map[i][j] == player->player_sign
		|| player->map[i][j] == ft_toupper(player->player_sign))
	{
		if (ft_check_neighbours(player, i, j))
			player->path_map[i][j] = -3;
		else
			player->path_map[i][j] = -2;
	}
	if (player->map[i][j] == '.')
		player->path_map[i][j] = -1;
}

void	ft_find_myself(t_filler *player)
{
	int i;
	int j;

	i = 0;
	while (player->map[i])
	{
		j = 0;
		while (player->map[i][j])
		{
			if (player->map[i][j] == ft_toupper(player->player_sign))
			{
				player->self_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}
