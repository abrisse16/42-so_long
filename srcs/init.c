/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:32:18 by abrisse           #+#    #+#             */
/*   Updated: 2022/09/14 14:45:59 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map	init_map(void)
{
	t_map	ret;

	ret.width = 0;
	ret.height = 0;
	ret.path_count = 0;
	return (ret);
}

static t_game	init_game(void)
{
	t_game	ret;

	ret.pos = 0;
	ret.pos_x = 0;
	ret.pos_y = 0;
	ret.item = 0;
	ret.exit = 0;
	ret.count = 0;
	return (ret);
}

static t_img	init_img(void)
{
	t_img	ret;

	ret.img = NULL;
	return (ret);
}

static t_graphic	init_graphic(void)
{
	t_graphic	ret;

	ret.mlx = NULL;
	ret.win = NULL;
	ret.empty = init_img();
	ret.wall = init_img();
	ret.item = init_img();
	ret.player = init_img();
	ret.exit = init_img();
	return (ret);
}

t_data	init_data(void)
{
	t_data	ret;

	ret.map = init_map();
	ret.game = init_game();
	ret.graphic = init_graphic();
	return (ret);
}
