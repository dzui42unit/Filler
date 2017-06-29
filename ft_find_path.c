/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:57:22 by dzui              #+#    #+#             */
/*   Updated: 2017/06/03 16:57:24 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_check_coord(t_filler *player, int i, int j)
{
	if (i < 0 || j < 0 || (i >= (player->x_size) || (j > player->y_size)))
		return (0);
	if (i + player->fig_size_x >= player->x_size)
		return (0);
	if (j + player->fig_size_y >= player->y_size)
		return (0);
	return (1);
}

int		ft_find_where_to_place(t_filler *player)
{
	t_path path;

	path.stop = 0;
	path.d = 0;
	while (!path.stop)
	{
		path.stop = 1;
		path.i = 0;
		while (path.i < player->x_size)
		{
			path.j = 0;
			while (path.j < player->y_size)
			{
				if (ft_sign_neighbours(&path, player))
					return (1);
				path.j++;
			}
			path.i++;
		}
		path.d++;
	}
	return (0);
}

int		ft_sign_neighbours(t_path *path, t_filler *player)
{
	if (player->path_map[path->i][path->j] == path->d)
	{
		path->k = 0;
		while (path->k < 4)
		{
			path->i_x = path->i + player->x_dir[path->k];
			path->i_y = path->j + player->y_dir[path->k];
			if (path->i_x >= 0 && path->i_x < player->x_size
				&& path->i_y >= 0 && path->i_y < player->y_size
				&& (player->path_map[path->i_x][path->i_y] == -1
					|| player->path_map[path->i_x][path->i_y] == -3))
			{
				path->stop = 0;
				if (player->path_map[path->i_x][path->i_y] == -3)
				{
					player->x_short = path->i_x;
					player->y_short = path->i_y;
					return (1);
				}
				player->path_map[path->i_x][path->i_y] = path->d + 1;
			}
			path->k++;
		}
	}
	return (0);
}

int		ft_check_neighbours(t_filler *player, int i, int j)
{
	int i_y;
	int i_x;
	int k;

	k = 0;
	while (k < 4)
	{
		i_x = i + player->x_dir[k];
		i_y = j + player->y_dir[k];
		if (i_x >= 0 && i_x < player->x_size && i_y >= 0
			&& i_x < player->y_size && (player->map[i_x][i_y] == '.'))
			return (1);
		k++;
	}
	return (0);
}
