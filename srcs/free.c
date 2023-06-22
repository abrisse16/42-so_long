/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:57:42 by abrisse           #+#    #+#             */
/*   Updated: 2022/09/15 12:00:57 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_graphic(t_graphic *g)
{
	if (g->empty.img)
		mlx_destroy_image(g->mlx, g->empty.img);
	if (g->wall.img)
		mlx_destroy_image(g->mlx, g->wall.img);
	if (g->item.img)
		mlx_destroy_image(g->mlx, g->item.img);
	if (g->player.img)
		mlx_destroy_image(g->mlx, g->player.img);
	if (g->exit.img)
		mlx_destroy_image(g->mlx, g->exit.img);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
}

void	free_map(t_data *data, char **map)
{
	int	i;

	i = -1;
	while (++i < data->map.height)
		free(map[i]);
	free (map);
}

void	free_some_map(char **map, int i)
{
	while (--i >= 0)
		free(map[i]);
	free(map);
}
