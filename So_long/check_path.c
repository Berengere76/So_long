/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:02:28 by blebas            #+#    #+#             */
/*   Updated: 2023/12/09 12:06:44 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx42.h"

void	free_mapcheck(t_goty *goty)
{
	int	i;

	i = -1;
	while (++i <= goty->height / 64)
		free(goty->map.path[i]);
	free(goty->map.path);
}

void	init_mapcheck(t_goty *goty)
{
	int	y;
	int	x;

	goty->map.path = malloc((goty->height / 64 + 2) * sizeof(char *));
	y = -1;
	while (++y < (goty->height / 64))
	{
		goty->map.path[y] = ft_strdup(goty->map.map[y]);
		x = -1;
		while (goty->map.path[y][++x])
		{
			if (goty->map.path[y][x] != '1' && goty->map.path[y][x] != '\n')
				goty->map.path[y][x] = '0';
		}
	}
	goty->map.path[y] = NULL;
}

int	map_checked(t_goty *goty, int y, int x)
{
	return (goty->map.path[y][x] - 48);
}

void	count_items(t_goty *goty, int y, int x)
{
	if (goty->map.map[y][x] == 'C')
		goty->map.item += 1;
	if (goty->map.map[y][x] == 'E')
		goty->map.exit += 1;
	goty->map.path[y][x] = '1';
}

int	check_path(t_goty *goty, int y, int x)
{
	int	result[4];

	result[0] = 0;
	result[1] = 0;
	result[2] = 0;
	result[3] = 0;
	count_items(goty, y, x);
	if (goty->map.item == goty->nb_t && goty->map.exit >= 1)
		return (1);
	if (x < 0 || x >= goty->wall_count + 1 || y < 0
		|| y >= goty->jpp || goty->map.map[y][x] == '1')
		return (0);
	if (goty->map.map[y][x + 1] != '1' && !map_checked(goty, y, x + 1))
		result[0] = check_path(goty, y, x + 1);
	if (goty->map.map[y][x - 1] != '1' && !map_checked(goty, y, x - 1))
		result[1] = check_path(goty, y, x - 1);
	if (goty->map.map[y + 1][x] != '1' && !map_checked(goty, y + 1, x))
		result[2] = check_path(goty, y + 1, x);
	if (goty->map.map[y - 1][x] != '1' && !map_checked(goty, y - 1, x))
		result[3] = check_path(goty, y - 1, x);
	return (result[0] || result[1] || result[2] || result[3]);
}
