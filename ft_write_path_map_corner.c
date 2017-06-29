/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_path_map_corner.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 15:48:54 by dzui              #+#    #+#             */
/*   Updated: 2017/06/04 15:49:14 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_is_touched(t_filler *player)
{
	int i;
	int j;

	i = 0;
	if (player->direction)
		j = player->y_size - player->y_size / 12;
	else
		j = 0;
	while (player->map[i])
	{
		if (player->map[i][j] == player->player_sign
			|| player->map[i][j] == ft_toupper(player->player_sign))
			return (1);
		i++;
	}
	return (0);
}

void	ft_write_path_map_corner(t_filler *player)
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
				player->path_map[i][j] = -2;
			ft_write_path_map_corner_2(player, i, j);
			j++;
		}
		i++;
	}
}

void	ft_write_path_map_corner_2(t_filler *player, int i, int j)
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
	if (j == player->y_size - 1 && player->direction)
		player->path_map[i][j] = 0;
	if (j == 0 && !player->direction)
		player->path_map[i][j] = 0;
}
