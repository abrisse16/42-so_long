/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:14:43 by abrisse           #+#    #+#             */
/*   Updated: 2022/09/15 12:05:46 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_texture(t_graphic *g, char *file, t_img *type)
{
	char	*dir;
	char	*path;

	dir = ft_strjoin(ASSETS_DIR, g->theme);
	path = ft_strjoin(dir, file);
	free(dir);
	if (!path)
		return (ft_perror("malloc"));
	type->img = mlx_xpm_file_to_image(g->mlx, path, &type->width,
			&type->height);
	if (!type->img)
	{
		ft_putstr_fd("Error\nCannot load texture: ", 1);
		ft_putendl_fd(path, 1);
	}
	free(path);
	return (type->img == NULL);
}

static int	create_textures(t_graphic *g)
{
	if (get_texture(g, T_EMPTY, &g->empty)
		|| get_texture(g, T_WALL, &g->wall)
		|| get_texture(g, T_ITEM, &g->item)
		|| get_texture(g, T_PLAYER, &g->player)
		|| get_texture(g, T_EXIT_CLOSED, &g->exit_closed)
		|| get_texture(g, T_EXIT, &g->exit))
		return (1);
	return (0);
}

void	chose_texture(t_data *data, char c, int x, int y)
{
	t_graphic	*g;
	t_img		*door;

	g = &data->graphic;
	door = &g->exit;
	if (data->game.item > 0)
		door = &g->exit_closed;
	if (c == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->wall.img,
			g->wall.width * x, g->wall.height * y);
	if (c == '0')
		mlx_put_image_to_window(g->mlx, g->win, g->empty.img,
			g->empty.width * x, g->empty.height * y);
	if (c == 'P')
		mlx_put_image_to_window(g->mlx, g->win, g->player.img,
			g->player.width * x, g->player.height * y);
	if (c == 'E')
		mlx_put_image_to_window(g->mlx, g->win, door->img,
			door->width * x, door->height * y);
	if (c == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->item.img,
			g->item.width * x, g->item.height * y);
}

void	push_textures(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map.height)
	{
		j = -1;
		while (++j < data->map.width)
			chose_texture(data, data->map.map[i][j], j, i);
	}
}

int	display(t_data *data)
{
	data->graphic.mlx = mlx_init();
	if (!data->graphic.mlx)
		return (ft_error("mlx_init"));
	if (create_textures(&data->graphic))
		return (1);
	data->graphic.win = mlx_new_window(data->graphic.mlx,
			data->graphic.empty.width * data->map.width,
			data->graphic.empty.height * data->map.height,
			"So long");
	if (!data->graphic.win)
		return (ft_perror("mlx_new_window"));
	push_textures(data);
	mlx_hook(data->graphic.win, 2, 1L << 0, key_press, data);
	mlx_hook(data->graphic.win, 17, 1L << 0, cross_press, data);
	mlx_loop(data->graphic.mlx);
	return (0);
}
