/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:50:41 by abrisse           #+#    #+#             */
/*   Updated: 2022/09/15 11:54:24 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_len(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->map.height)
	{
		if (ft_strlen(data->map.map[i]) != ((unsigned long)data->map.width))
			return (ft_error("Map isn't rectangular"));
	}
	return (0);
}

static int	check_char(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map.height)
	{
		j = -1;
		while (++j < data->map.width)
		{
			if (ft_strchr("01CEP", data->map.map[i][j]) == NULL)
				return (ft_error("Wrong character"));
			if ((i == 0 || j == 0 || i == data->map.height - 1
					|| j == data->map.width - 1) && data->map.map[i][j] != '1')
				return (ft_error("The map must be closed by walls"));
			if (data->game.pos != 1)
				return (ft_error("The map must contain 1 starting position"));
			if (data->game.exit != 1)
				return (ft_error("The map must contain 1 exit"));
			if (data->game.item < 1)
				return (ft_error(
						"The map must contain at least 1 collectible"));
		}
	}
	return (0);
}

static int	find_path(t_data *data, int x, int y)
{
	if (ft_strchr("0CEP", data->map.path[y][x]))
	{
		if (ft_strchr("CE", data->map.path[y][x]))
			data->map.path_count++;
		data->map.path[y][x] = 'X';
		if (!ft_strchr("1X", data->map.path[y][x + 1])
			&& x + 1 < data->map.width)
			find_path(data, x + 1, y);
		if (!ft_strchr("1X", data->map.path[y + 1][x])
			&& y + 1 < data->map.height)
			find_path(data, x, y + 1);
		if (!ft_strchr("1X", data->map.path[y][x - 1]) && x - 1 >= 0)
			find_path(data, x - 1, y);
		if (!ft_strchr("1X", data->map.path[y - 1][x]) && y - 1 >= 0)
			find_path(data, x, y - 1);
	}
	else
		return (1);
	if (data->map.path_count == data->game.item + 1)
		return (0);
	else
		return (1);
}

static int	check_path(t_data *data)
{
	int	i;
	int	j;

	data->map.path = (char **)malloc(sizeof(char *) * data->map.height);
	if (!data->map.path)
		return (ft_perror("malloc"));
	i = -1;
	while (++i < data->map.height)
	{
		data->map.path[i] = (char *)malloc(sizeof(char) * data->map.width);
		if (!data->map.path[i])
		{
			free_some_map(data->map.path, i);
			return (ft_perror("malloc"));
		}
		j = -1;
		while (++j < data->map.width)
			data->map.path[i][j] = data->map.map[i][j];
	}
	if (find_path(data, data->game.pos_x, data->game.pos_y))
		return (ft_error("Not valid path"));
	return (0);
}

int	check_map(t_data *data)
{
	if (check_len(data))
		return (1);
	if (check_char(data))
		return (1);
	if (check_path(data))
	{
		free_map(data, data->map.path);
		return (1);
	}
	free_map(data, data->map.path);
	return (0);
}
