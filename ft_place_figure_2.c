/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_figure_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 17:39:06 by dzui              #+#    #+#             */
/*   Updated: 2017/06/03 17:39:17 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_check_place(t_filler *player, t_place *place)
{
	place->overlap_field = 0;
	place->i = 0;
	place->k = player->place_x;
	while (player->figure[place->i])
	{
		place->j = 0;
		place->l = player->place_y;
		while (player->figure[place->i][place->j])
		{
			if (!ft_check_place_2(player, place))
				return (0);
			place->j++;
			place->l++;
		}
		place->k++;
		place->i++;
	}
	if (place->overlap_field == 1)
		return (1);
	return (0);
}

int		ft_check_place_2(t_filler *player, t_place *place)
{
	if ((player->figure[place->i][place->j] == '*')
		&& (player->map[place->k][place->l] == ft_toupper(player->player_sign)
			|| player->map[place->k][place->l] == (player->player_sign)
			|| (player->map[place->k][place->l] == '!')))
		place->overlap_field++;
	if ((player->figure[place->i][place->j] == '*')
		&& (player->map[place->k][place->l] == ft_toupper(player->enemy_sign)
			|| player->map[place->k][place->l] == (player->enemy_sign)))
		return (0);
	return (1);
}

int		ft_place_token(t_filler *player)
{
	t_place place;

	if (ft_check_coord(player, player->x_short - player->fig_i,
		player->y_short - player->fig_j))
	{
		player->place_x = player->x_short - player->fig_i;
		player->place_y = player->y_short - player->fig_j;
		if (ft_check_place(player, &place))
			return (1);
	}
	if (ft_place_token_2(player, &place))
		return (1);
	return (0);
}

int		ft_place_token_2(t_filler *player, t_place *place)
{
	int k;

	k = 0;
	while (k < 8)
	{
		place->i_x = player->x_short + player->x_dir[k];
		place->i_y = player->y_short + player->y_dir[k];
		if (place->i_x >= 0 && place->i_x < player->x_size
			&& place->i_y >= 0 && place->i_x < player->y_size)
		{
			if (ft_check_coord(player,
				player->x_short - player->fig_i + place->i_x,
				player->y_short - player->fig_j + place->i_y))
			{
				player->place_x = player->x_short - player->fig_i + place->i_x;
				player->place_y = player->y_short - player->fig_j + place->i_y;
				if (ft_check_place(player, place))
					return (1);
			}
		}
		k++;
	}
	return (0);
}
