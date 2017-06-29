/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_map_figure.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 17:06:59 by dzui              #+#    #+#             */
/*   Updated: 2017/06/03 17:07:01 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_find_enemy(t_filler *player)
{
	int i;
	int j;

	i = 0;
	while (player->map[i])
	{
		j = 0;
		while (player->map[i][j])
		{
			if (player->map[i][j] == player->enemy_sign)
			{
				player->x_enemy = i;
				player->y_enemy = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_write_map(t_filler *player)
{
	int k;
	int l;
	int j;

	player->i = 0;
	k = 0;
	while (k < player->x_size)
	{
		l = 0;
		get_next_line(0, &player->buff);
		while (ft_isdigit(player->buff[l]) || ft_isspace(player->buff[l]))
			l++;
		j = 0;
		while (j < player->y_size)
		{
			player->map[k][j] = player->buff[l];
			l++;
			j++;
		}
		player->i++;
		k++;
	}
}

void	ft_write_figure(t_filler *player)
{
	int	k;
	int	l;
	int	j;

	k = 0;
	get_next_line(0, &player->buff);
	player->fig_size_x = 0;
	player->fig_size_y = 0;
	ft_get_figure_size(player, player->buff);
	player->figure = (char **)malloc(sizeof(char *) * (player->fig_size_x + 1));
	while (k < player->fig_size_x)
	{
		get_next_line(0, &player->buff);
		l = 0;
		j = 0;
		player->figure[k] = ft_strnew((size_t)(player->fig_size_y + 1));
		while (player->buff[j])
		{
			player->figure[k][l] = player->buff[j];
			l++;
			j++;
		}
		k++;
	}
	player->figure[k] = NULL;
}

void	ft_alloc_maps(t_filler *player)
{
	int i;

	player->map = (char **)malloc(sizeof(char *) * (player->x_size + 1));
	player->path_map = (int **)malloc(sizeof(int *) * (player->x_size));
	player->map[player->x_size] = NULL;
	i = 0;
	while (i < player->x_size)
	{
		player->map[i] = ft_strnew((size_t)(player->y_size));
		i++;
	}
	i = 0;
	while (i < player->x_size)
	{
		player->path_map[i] = (int *)malloc(sizeof(int) * player->y_size);
		i++;
	}
}
