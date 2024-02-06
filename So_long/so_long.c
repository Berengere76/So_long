/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:32:08 by blebas            #+#    #+#             */
/*   Updated: 2023/12/09 12:13:14 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx42.h"

void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int	free_error(t_goty *goty, char *error)
{
	int	i;

	if (error != NULL)
	{
		i = -1;
		while (++i < goty->height / 64)
			free(goty->map.map[i]);
		free(goty->map.map);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

char	*file_is_ber(t_goty *goty, int ac)
{
	if (ac != 2)
		return ("Error\nWrong number of argument\n");
	if (ft_strchr_gnl(goty->map.file_map, '.') == NULL
		|| ft_strncmp(ft_strchr_gnl(goty->map.file_map, '.'), ".ber", 4) != 0)
		return ("Error\nWrong format\n");
	return (NULL);
}

int	check_file(t_goty *goty, int argc, char **argv)
{
	goty->map.file_map = argv[1];
	goty->map.fd = open(goty->map.file_map, O_RDONLY);
	if (goty->map.fd <= 0)
	{
		ft_printf("Error\nThe file can't open :'(\n");
		return (EXIT_FAILURE);
	}
	goty->error_file = file_is_ber(goty, argc);
	if (goty->error_file != NULL)
	{
		ft_printf("Error\nMap is not .ber :(\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int32_t	main(int argc, char **argv)
{
	t_goty	goty;
	char	*error;

	if (argc != 2)
		ft_printf("Error\nWrong number of argument :O\n");
	init_game(&goty);
	if (check_file(&goty, argc, argv))
		return (EXIT_FAILURE);
	lenght_map(&goty);
	goty.jpp = goty.map.count_y;
	goty.width = goty.wall_count * 64;
	goty.height = goty.map.count_y * 64;
	error = check_error(&goty);
	if (error)
	{
		ft_printf("Error\n%s\n", error);
		free_error(&goty, error);
		return (EXIT_FAILURE);
	}
	start_game(&goty);
	mlx_key_hook(goty.mlx, ft_hook, &goty);
	mlx_loop(goty.mlx);
	ft_quit(&goty);
	return (EXIT_SUCCESS);
}
