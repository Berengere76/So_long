/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:29:41 by blebas            #+#    #+#             */
/*   Updated: 2023/12/09 12:27:51 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "minilibx/mlx42.h"
# include "Libft/libft.h"

typedef struct image
{
	mlx_image_t	*perso;
	mlx_image_t	*background;
	mlx_image_t	*mur;
	mlx_image_t	*tomate;
	mlx_image_t	*sortie;
}		t_image;

typedef struct texture
{
	mlx_texture_t	*perso_texture;
	mlx_texture_t	*background_texture;
	mlx_texture_t	*mur_texture;
	mlx_texture_t	*tomate_texture;
	mlx_texture_t	*sortie_texture;
}		t_texture;

typedef struct map
{
	char	**map;
	char	**path;
	char	*file_map;
	int		item;
	int		exit;
	int		fd;
	int		count_y;
	int		count_x;
}		t_map;

typedef struct perso
{
	int		pos_y;
	int		pos_x;
	int		nb_mouv;
}		t_perso;

typedef struct goty
{
	mlx_t		*mlx;
	t_image		image;
	t_texture	texture;
	t_map		map;
	t_perso		perso;
	int			wall_count;
	int			width;
	int			height;
	int			count_tomate;
	int			can_exit;
	int			nb_p;
	int			nb_t;
	int			nb_e;
	int			jpp;
	char		*error_file;
}		t_goty;

//texture.c
void	ft_loadpng(t_goty *goty);
void	ft_texture_image(t_goty *goty);
void	ft_resize(t_goty *goty);
void	ft_image(t_goty *goty);

//game.c
void	init_game(t_goty *goty);
void	start_game(t_goty *goty);
void	free_map(t_goty *goty);
void	ft_quit(t_goty *goty);

//map.c
void	lenght_map(t_goty *goty);
void	init_map(t_goty *goty, int i, char *str);
void	fill_item(t_goty *goty, int x, int y);
void	fill_map(t_goty *goty);

//perso.c
void	init_player(t_goty *goty);
void	fill_player(t_goty *goty, int x, int y);
void	start_player(t_goty *goty);
void	eat_tomato(t_goty *goty, int x, int y);
void	ft_can_exit(t_goty *goty);

//movement.c
void	ft_hook(mlx_key_data_t keydata, void *param);
void	move_up(t_goty *goty);
void	move_down(t_goty *goty);
void	move_left(t_goty *goty);
void	move_right(t_goty *goty);

//error.c
int		map_rectangle(t_goty *goty);
int		is_wall(t_goty *goty);
char	*check_error(t_goty *goty);

//check_path.c
void	free_mapcheck(t_goty *goty);
void	init_mapcheck(t_goty *goty);
int		map_checked(t_goty *goty, int y, int x);
void	count_items(t_goty *games, int y, int x);
int		check_path(t_goty *goty, int y, int x);

//so_long.c
void	error(void);
int		free_error(t_goty *goty, char *error);
char	*file_is_ber(t_goty *goty, int ac);
int		check_file(t_goty *goty, int ac, char **av);
int32_t	main(int ac, char **av);

#endif
