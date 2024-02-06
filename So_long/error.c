/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:29:23 by blebas            #+#    #+#             */
/*   Updated: 2023/12/09 12:10:40 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx42.h"

int	map_rectangle(t_goty *goty)
{
	int	i;

	i = 0;
	if (goty->map.map == NULL)
		return (1);
	while (i != (goty->height / 64))
	{
		if (i != (goty->height / 64) - 1)
		{
			if (ft_strlen(goty->map.map[i]) != ft_strlen(goty->map.map[i + 1]))
				return (0);
		}
		i++;
	}
	return (1);
}

int	is_wall(t_goty *goty)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	i = 0;
	while (goty->map.map[i])
		i++;
	while (goty->map.map[0][j] && goty->map.map[i - 1][j]
			&& goty->map.map[0][j] != '\n')
	{
		if (goty->map.map[0][j] != '1' || goty->map.map[i - 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	len = ft_strlen(goty->map.map[i]) - 2;
	while (goty->map.map[i] && goty->map.map[i][j] != '\n')
	{
		if (goty->map.map[i][0] != '1' || goty->map.map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

char	*check_error(t_goty *goty)
{
	if (!is_wall(goty))
		return ("The map must be closed or the guinea pig will escape!\n");
	if (!map_rectangle(goty))
		return ("The map must be a rectangle\n");
	if (goty->nb_e != 1)
		return ("There must be one house\n");
	if (goty->nb_t < 1)
		return ("If there is no tomato how Alphonse's gonna eat?!\n");
	if (goty->nb_p != 1)
		return ("There must be one guinea pig, Alphonse the pig god\n");
	init_mapcheck(goty);
	init_player(goty);
	if (!check_path(goty, goty->perso.pos_y, goty->perso.pos_x))
	{
		free_mapcheck(goty);
		return ("Map must be possible");
	}
	free_mapcheck(goty);
	return (NULL);
}
