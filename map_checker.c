/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:27:38 by khaimer           #+#    #+#             */
/*   Updated: 2023/04/14 21:53:12 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	wall_checker(t_tools *map, int i, int j)
{
	if (map->tab[0][j] != '1' || map->tab[i][0] != '1'
				|| map->tab[map->line - 1][j] != '1' || map->tab[i][map->length
				- 1] != '1')
		return (1);
	return (0);
}

void	map_checker(t_tools *map, int i, int j)
{
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[i][j] != '\n' && map->tab[i][j] != '\0')
		{
			if (wall_checker(map, i, j))
				free_map(map);
			if (map->tab[i][j] == 'C')
				map->coin++;
			else if (map->tab[i][j] == 'P')
			{
				map->y = i;
				map->x = j;
				map->player++;
			}
			else if (map->tab[i][j] == 'E')
				map->exit++;
			else if (map->tab[i][j] != '0' && map->tab[i][j] != 'P'
					&& map->tab[i][j] != 'C' && map->tab[i][j] != 'E'
					&& map->tab[i][j] != '1')
				free_map(map);
			j++;
		}
		i++;
	}
}

void	check_map(t_tools *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->tab[map->line - 1][map->length] != '\0')
		map->length++;
	map_checker(map, i, j);
	map->coin_checker = map->coin;
	if (map->player != 1 || map->coin < 1 || map->exit != 1)
		free_map(map);
	if (!valid_path(map, map->y, map->x))
		free_map(map);
}
