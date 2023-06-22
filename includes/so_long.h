/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 23:01:15 by abrisse           #+#    #+#             */
/*   Updated: 2022/10/17 20:12:03 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

# include "libft.h"
# include "mlx.h"

# define P_EMPTY "ressources/sand.xpm"
# define P_WALL "ressources/cactus.xpm"
# define P_ITEM "ressources/drop1.xpm"
# define P_PLAYER "ressources/dino1.xpm"
# define P_EXIT "ressources/puddle.xpm"

# define ESCAPE 65307
# define W 119
# define A 97
# define S 115
# define D 100

typedef struct s_map
{
	char	**map;
	char	**path;
	int		width;
	int		height;
	int		path_count;
}	t_map;

typedef struct s_game
{
	int	pos;
	int	pos_x;
	int	pos_y;
	int	item;
	int	exit;
	int	count;
}	t_game;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_graphic
{
	void	*mlx;
	void	*win;
	t_img	empty;
	t_img	wall;
	t_img	item;
	t_img	player;
	t_img	exit;
}	t_graphic;	

typedef struct s_data
{
	t_map		map;
	t_game		game;
	t_graphic	graphic;
}	t_data;

/* initialize */
t_data	init_data(void);

/* error message */
int		ft_error(char *str);
int		ft_perror(char *str);
int		ft_lstclear_perror(t_list **lst, char *str);

/* parsing */
int		check_args(int ac, char **av);
int		parsing(int fd, t_data *data);

/* checking the map */
int		check_map(t_data *data);

/* graphic */
int		display(t_data *data);
void	push_textures(t_data *data);

/* actions */
int		key_press(int key, t_data *data);
int		cross_press(t_data *data);

/* free things */
void	free_graphic(t_graphic *graph);
void	free_map(t_data *data, char **map);
void	free_some_map(char **map, int i);

#endif
