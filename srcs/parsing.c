/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 00:22:15 by abrisse           #+#    #+#             */
/*   Updated: 2022/10/18 14:28:08 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_args(int ac, char **av)
{
	char	*str;

	if (ac != 2)
		return (ft_error("Incorrect number of arguments"));
	str = ft_strrchr(av[1], '/');
	if (str && ft_strlen(str) <= 5)
		return (ft_error("Invalid format file"));
	if (ft_strlen(av[1]) <= 4)
		return (ft_error("Invalid format file"));
	str = ft_strrchr(av[1], '.');
	if (str == NULL || ft_strcmp(str, ".ber"))
		return (ft_error("Invalid format file"));
	return (0);
}

static t_list	*get_map(int fd, t_data *data)
{
	char	*line;
	t_list	*lst;

	line = get_next_line(fd);
	if (!line)
	{
		ft_error("Empty file");
		return (NULL);
	}
	data->map.width = ft_strlen(line) - 1;
	lst = NULL;
	while (line)
	{
		data->map.height++;
		ft_lstadd_back(&lst, ft_lstnew(line));
		line = get_next_line(fd);
	}
	return (lst);
}

static int	create_map(t_list **lst, t_data *data)
{
	int		i;
	t_list	*tmp;

	data->map.map = (char **)malloc(sizeof(char *) * data->map.height);
	if (!data->map.map)
		return (ft_lstclear_perror(lst, "malloc"));
	tmp = *lst;
	i = -1;
	while (tmp && ++i < data->map.height)
	{
		data->map.map[i] = (char *)malloc(sizeof(char)
				* ft_strlen(tmp->content) + 1);
		if (!data->map.map[i])
		{
			ft_lstclear(lst, free);
			free_some_map(data->map.map, i);
			return (ft_perror("maloc"));
		}
		ft_strlcpy(data->map.map[i], (char *)tmp->content,
			ft_strlen(tmp->content));
		tmp = tmp->next;
	}
	ft_lstclear(lst, free);
	return (0);
}

static int	collect_data(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map.height)
	{
		j = -1;
		while (++j < (int)ft_strlen(data->map.map[i]))
		{
			if (data->map.map[i][j] == 'C')
				data->game.item++;
			if (data->map.map[i][j] == 'P')
			{
				data->game.pos++;
				data->game.pos_x = j;
				data->game.pos_y = i;
			}
			if (data->map.map[i][j] == 'E')
				data->game.exit++;
		}
	}
	return (0);
}

int	parsing(int fd, t_data *data)
{
	t_list	*lst;

	lst = get_map(fd, data);
	if (!lst)
		return (1);
	if (create_map(&lst, data))
		return (1);
	collect_data(data);
	if (check_map(data))
	{
		free_map(data, data->map.map);
		return (1);
	}
	return (0);
}
