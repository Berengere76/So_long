/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:21:03 by blebas            #+#    #+#             */
/*   Updated: 2023/12/04 16:48:47 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx42.h"

void	ft_loadpng(t_goty *goty)
{
	goty->texture.perso_texture = mlx_load_png("./assets/pig.png");
	if (!goty->texture.perso_texture)
		error();
	goty->texture.background_texture = mlx_load_png("./assets/decor.png");
	if (!goty->texture.background_texture)
		error();
	goty->texture.mur_texture = mlx_load_png("./assets/bush.png");
	if (!goty->texture.mur_texture)
		error();
	goty->texture.tomate_texture = mlx_load_png("./assets/tomate.png");
	if (!goty->texture.tomate_texture)
		error();
	goty->texture.sortie_texture = mlx_load_png("./assets/sortie.png");
	if (!goty->texture.sortie_texture)
		error();
}

void	ft_texture_image(t_goty *goty)
{
	goty->image.perso = mlx_texture_to_image(goty->mlx,
			goty->texture.perso_texture);
	if (!goty->image.perso)
		error();
	goty->image.background = mlx_texture_to_image(goty->mlx,
			goty->texture.background_texture);
	if (!goty->image.background)
		error();
	goty->image.mur = mlx_texture_to_image(goty->mlx,
			goty->texture.mur_texture);
	if (!goty->image.mur)
		error();
	goty->image.tomate = mlx_texture_to_image(goty->mlx,
			goty->texture.tomate_texture);
	if (!goty->image.tomate)
		error();
	goty->image.sortie = mlx_texture_to_image(goty->mlx,
			goty->texture.sortie_texture);
	if (!goty->image.sortie)
		error();
}

void	ft_resize(t_goty *goty)
{
	mlx_resize_image(goty->image.perso, 64, 64);
	mlx_resize_image(goty->image.mur, 64, 64);
	mlx_resize_image(goty->image.tomate, 64, 64);
	mlx_resize_image(goty->image.sortie, 64, 64);
	mlx_resize_image(goty->image.background, goty->width, goty->height);
}

void	ft_image(t_goty *goty)
{
	ft_loadpng(goty);
	ft_texture_image(goty);
	ft_resize(goty);
}
