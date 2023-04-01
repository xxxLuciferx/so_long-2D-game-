/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:10:06 by khaimer           #+#    #+#             */
/*   Updated: 2023/04/01 22:33:39 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	valid_map_name(int argc, char **argv)
{
	int i;

	i = 0;
	if(argc != 2)
	{
		write(1, "incorrect arguments\n", 19);
		exit(1);
	}
	while(argv[1][i])
		i++;
	if(argv[1][i - 1] != 'r' || argv[1][i - 2] != 'e' || argv[1][i - 3] != 'b' || argv[1][i - 4] != '.')
	{
		write(1, "incorrect map\n", 14);
		exit(1);
	}
}

void	free_map(t_tools *map)
{
	int i;

	i = 0;
	if(map->tab && map->tab[i])
	{	
		while(map->tab[i])
		{
			free(map->tab[i]);
			i++;
		}
		free(map->tab);
	}
	write(1, "Error in map\n", 13);
	exit(1);
}