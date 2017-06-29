/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 17:04:24 by dzui              #+#    #+#             */
/*   Updated: 2017/06/03 17:04:25 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_free_fig(t_filler *player)
{
	int i;

	i = 0;
	while (player->figure[i])
	{
		free(player->figure[i]);
		i++;
	}
	free(player->figure);
	player->figure = NULL;
}
