/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 17:05:18 by dzui              #+#    #+#             */
/*   Updated: 2017/06/03 17:05:18 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_get_map_size(t_filler *player, char *str)
{
	int j;

	j = 0;
	player->x_size = 0;
	player->y_size = 0;
	if (str)
	{
		while (str[j] && !ft_isdigit(str[j]))
			j++;
		while (str[j] && ft_isdigit(str[j]))
		{
			player->x_size += str[j] - '0';
			player->x_size *= 10;
			j++;
		}
		player->x_size /= 10;
		j++;
		while (str[j] && ft_isdigit(str[j]))
		{
			player->y_size += str[j] - '0';
			player->y_size *= 10;
			j++;
		}
		player->y_size /= 10;
	}
}

void	ft_get_figure_size(t_filler *player, char *str)
{
	int i;

	i = 0;
	while (str[i] && !ft_isdigit(str[i]))
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		player->fig_size_x += str[i++] - '0';
		player->fig_size_x *= 10;
	}
	player->fig_size_x /= 10;
	i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		player->fig_size_y += str[i++] - '0';
		player->fig_size_y *= 10;
	}
	player->fig_size_y /= 10;
}
