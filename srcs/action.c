/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:12:11 by abrisse           #+#    #+#             */
/*   Updated: 2022/10/17 00:33:35 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_dir(t_data *data, int x, int y)
{
	if (data->map.map[y][x] == '1')
		return (0);
	if (data->map.map[y][x] != 'E')
		return (1);
	if (data->map.map[y][x] == 'E' && data->game.item == 0)
		return (1);
	return (0);
}

static void	move(t_data *data, int x, int y)
{
	if (data->map.map[y][x] == 'C')
		data->game.item--;
	if (data->map.map[y][x] == 'E' && data->game.item == 0)
	{
		ft_putstr_fd("You WON with ", 1);
		ft_putnbr_fd(++data->game.count, 1);
		ft_putstr_fd(" moves!\n", 1);
		mlx_loop_end(data->graphic.mlx);
		return ;
	}
	data->map.map[data->game.pos_y][data->game.pos_x] = '0';
	data->map.map[y][x] = 'P';
	data->game.pos_x = x;
	data->game.pos_y = y;
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(++data->game.count, 1);
	ft_putstr_fd("\n", 1);
	push_textures(data);
}

int	key_press(int key, t_data *data)
{
	if (key == ESCAPE)
		mlx_loop_end(data->graphic.mlx);
	else if (key == W
		&& check_dir(data, data->game.pos_x, data->game.pos_y - 1))
		move(data, data->game.pos_x, data->game.pos_y - 1);
	else if (key == A
		&& check_dir(data, data->game.pos_x - 1, data->game.pos_y))
		move(data, data->game.pos_x - 1, data->game.pos_y);
	else if (key == S
		&& check_dir(data, data->game.pos_x, data->game.pos_y + 1))
		move(data, data->game.pos_x, data->game.pos_y + 1);
	else if (key == D
		&& check_dir(data, data->game.pos_x + 1, data->game.pos_y))
		move(data, data->game.pos_x + 1, data->game.pos_y);
	return (0);
}

int	cross_press(t_data *data)
{
	mlx_loop_end(data->graphic.mlx);
	return (0);
}
