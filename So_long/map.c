/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:20:02 by blebas            #+#    #+#             */
/*   Updated: 2023/12/04 17:13:32 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx42.h"

void	lenght_map(t_goty *goty)
{
	int		i;
	char	*str;

	i = 0;
	goty->map.map = NULL;
	goty->map.fd = open(goty->map.file_map, O_RDONLY);
	str = get_next_line(goty->map.fd);
	if (!str)
		return ;
	goty->wall_count = ft_strlen(str) - 1;
	while (1)
	{
		free(str);
		str = get_next_line(goty->map.fd);
		if (str == NULL)
			break ;
		i++;
	}
	close(goty->map.fd);
	goty->map.count_y = i + 1;
	goty->map.map = (char **)malloc(sizeof (char *) * (i + 2));
	goty->map.fd = open(goty->map.file_map, O_RDONLY);
	init_map(goty, i, str);
}

void	init_map(t_goty *goty, int i, char *str)
{
	int	j;

	i = 0;
	while (1)
	{
		str = get_next_line(goty->map.fd);
		if (str == NULL)
			break ;
		j = -1;
		while (str[++j])
		{
			if (str[j] == 'E')
				goty->nb_e += 1;
			if (str[j] == 'C')
				goty->nb_t += 1;
			if (str[j] == 'P')
				goty->nb_p += 1;
		}
		goty->map.map[i] = str;
		i++;
	}
	goty->map.map[i] = NULL;
	close(goty->map.fd);
}

void	fill_item(t_goty *goty, int x, int y)
{
	if (goty->map.map[y][x] == 'C')
	{
		goty->count_tomate++;
		mlx_image_to_window(goty->mlx, goty->image.tomate, goty->map.count_x,
			goty->map.count_y);
	}
	if (goty->map.map[y][x] == 'E')
	{
		goty->can_exit++;
		mlx_image_to_window(goty->mlx, goty->image.sortie,
			goty->map.count_x, goty->map.count_y);
	}
}

void	fill_map(t_goty *goty)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	goty->map.count_y = 0;
	goty->map.count_x = 0;
	while (goty->map.map[y])
	{
		while (goty->map.map[y][x])
		{
			if (goty->map.map[y][x] == '1')
				mlx_image_to_window(goty->mlx, goty->image.mur,
					goty->map.count_x, goty->map.count_y);
			fill_item(goty, x, y);
			goty->map.count_x += 64;
			x++;
		}
		goty->map.count_y += 64;
		goty->map.count_x = 0;
		x = 0;
		y++;
	}
}
