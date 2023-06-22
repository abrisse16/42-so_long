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

static int	get_texture(void *mlx, char *path, t_img *type)
{
	type->img = mlx_xpm_file_to_image(mlx, path, &type->height, &type->width);
	if (!type->img)
		return (ft_perror("mlx_xpm_file_to_image"));
	return (0);
}

static int	create_textures(t_graphic *graph)
{
	if (get_texture(graph->mlx, P_EMPTY, &graph->empty)
		|| get_texture(graph->mlx, P_WALL, &graph->wall)
		|| get_texture(graph->mlx, P_ITEM, &graph->item)
		|| get_texture(graph->mlx, P_PLAYER, &graph->player)
		|| get_texture(graph->mlx, P_EXIT, &graph->exit))
		return (1);
	return (0);
}

void	chose_texture(t_graphic *g, char c, int x, int y)
{
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
		mlx_put_image_to_window(g->mlx, g->win, g->exit.img,
			g->exit.width * x, g->exit.height * y);
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
			chose_texture(&data->graphic, data->map.map[i][j], j, i);
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
