/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 23:08:44 by abrisse           #+#    #+#             */
/*   Updated: 2022/10/17 20:12:16 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(char *str)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd(str, 1);
	return (1);
}

int	ft_perror(char *str)
{
	ft_putendl_fd("Error", 1);
	perror(str);
	return (1);
}

int	ft_lstclear_perror(t_list **lst, char *str)
{
	ft_lstclear(lst, free);
	return (ft_perror(str));
}
