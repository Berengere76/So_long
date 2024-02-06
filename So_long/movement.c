/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:49:14 by blebas            #+#    #+#             */
/*   Updated: 2023/12/09 12:12:49 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx42.h"

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_goty	*goty;

	goty = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_up(goty);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_down(goty);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_left(goty);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_right(goty);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(goty->mlx);
}

void	move_up(t_goty *goty)
{
	int	x;
	int	y;

	y = goty->perso.pos_y;
	x = goty->perso.pos_x;
	if (goty->map.map[y - 1][x] == '1')
		return ;
	goty->image.perso->instances[0].y -= 64;
	goty->perso.pos_y -= 1;
	goty->perso.nb_mouv += 1;
	ft_printf("Nombre de coups : %i\n", goty->perso.nb_mouv);
	eat_tomato(goty, goty->perso.pos_y, x);
	ft_can_exit(goty);
}

void	move_down(t_goty *goty)
{
	int	x;
	int	y;

	y = goty->perso.pos_y;
	x = goty->perso.pos_x;
	if (goty->map.map[y + 1][x] == '1')
		return ;
	goty->image.perso->instances[0].y += 64;
	goty->perso.pos_y += 1;
	goty->perso.nb_mouv += 1;
	ft_printf("Nombre de coups : %i\n", goty->perso.nb_mouv);
	eat_tomato(goty, goty->perso.pos_y, x);
	ft_can_exit(goty);
}

void	move_left(t_goty *goty)
{
	int	x;
	int	y;

	y = goty->perso.pos_y;
	x = goty->perso.pos_x;
	if (goty->map.map[y][x - 1] == '1')
		return ;
	goty->image.perso->instances[0].x -= 64;
	goty->perso.pos_x -= 1;
	goty->perso.nb_mouv += 1;
	ft_printf("Nombre de coups : %i\n", goty->perso.nb_mouv);
	eat_tomato(goty, y, goty->perso.pos_x);
	ft_can_exit(goty);
}

void	move_right(t_goty *goty)
{
	int	x;
	int	y;

	y = goty->perso.pos_y;
	x = goty->perso.pos_x;
	if (goty->map.map[y][x + 1] == '1')
		return ;
	goty->image.perso->instances[0].x += 64;
	goty->perso.pos_x += 1;
	goty->perso.nb_mouv += 1;
	ft_printf("Nombre de coups : %i\n", goty->perso.nb_mouv);
	eat_tomato(goty, y, goty->perso.pos_x);
	ft_can_exit(goty);
}
