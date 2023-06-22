/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 23:02:59 by abrisse           #+#    #+#             */
/*   Updated: 2022/09/15 11:59:17 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	int		fd;
	t_data	data;

	data = init_data();
	if (check_args(ac, av))
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_perror("open"));
	if (parsing(fd, &data))
	{
		close(fd);
		return (1);
	}
	close(fd);
	display(&data);
	free_graphic(&data.graphic);
	free_map(&data, (&data)->map.map);
	return (0);
}
