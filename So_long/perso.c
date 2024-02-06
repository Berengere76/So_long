/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perso.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:13:52 by blebas            #+#    #+#             */
/*   Updated: 2023/12/04 17:25:08 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx42.h"

void	init_player(t_goty *goty)
{
	int	y;
	int	x;

	y = -1;
	while (goty->map.map[++y])
	{
		x = -1;
		while (goty->map.map[y][++x])
		{
			if (goty->map.map[y][x] == 'P')
			{
				goty->perso.pos_y = y;
				goty->perso.pos_x = x;
			}
		}
	}
}

void	fill_player(t_goty *goty, int x, int y)
{
	if (goty->map.map[y][x] == 'P')
	{
		goty->perso.pos_y = y;
		goty->perso.pos_x = x;
		goty->nb_p += 1;
		mlx_image_to_window(goty->mlx, goty->image.perso,
			goty->map.count_x, goty->map.count_y);
	}
}

void	start_player(t_goty *goty)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	goty->perso.pos_y = 0;
	goty->perso.pos_x = 0;
	goty->map.count_y = 0;
	while (goty->map.map[y])
	{
		while (goty->map.map[y][x])
		{
			fill_player(goty, x, y);
			goty->map.count_x += 64;
			x++;
		}
		goty->map.count_y += 64;
		goty->map.count_x = 0;
		x = 0;
		y++;
	}
}

void	eat_tomato(t_goty *goty, int y, int x)
{
	int	i;

	i = -1;
	if (!(goty->map.map[y][x] == 'C'))
		return ;
	while (++i < (int)goty->image.tomate->count)
	{
		if (goty->image.tomate->instances[i].y / 64 != y)
			continue ;
		if (goty->image.tomate->instances[i].x / 64 != x)
			continue ;
		if (!(goty->image.tomate->instances[i].enabled))
			continue ;
		goty->image.tomate->instances[i].enabled = false;
		goty->count_tomate -= 1;
		if (goty->count_tomate <= 0)
			goty->can_exit = 0;
	}
}

void	ft_can_exit(t_goty*goty)
{
	if ((goty->can_exit == 0)
		&& (goty->map.map[goty->perso.pos_y][goty->perso.pos_x] == 'E'))
	{
		mlx_close_window(goty->mlx);
		ft_printf("Vous avez fini en %i coups\n", goty->perso.nb_mouv);
		ft_printf("YOU WIN !\n");
	}
}
