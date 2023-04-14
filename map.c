/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:10:06 by khaimer           #+#    #+#             */
/*   Updated: 2023/04/14 18:52:41 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	valid_map_name(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		write(1, "incorrect arguments\n", 19);
		exit(1);
	}
	while (argv[1][i])
		i++;
	if (argv[1][i - 1] != 'r' || argv[1][i - 2] != 'e' || argv[1][i - 3] != 'b'
		|| argv[1][i - 4] != '.')
	{
		write(1, "incorrect map\n", 14);
		exit(1);
	}
}

void	free_map(t_tools *map)
{
	(void)map;
	write(1, "Error in map\n", 13);
	exit(1);
}

void	valid_path_recursive(t_tools *map, int y, int x)
{
	valid_path(map, y, x - 1);
	valid_path(map, y, x + 1);
	valid_path(map, y + 1, x);
	valid_path(map, y - 1, x);
}

int	valid_path(t_tools *map, int y, int x)
{
	if (map->tab[y][x] == 'P')
	{
		map->tab[y][x] = '1';
		valid_path_recursive(map, y, x);
	}
	if (map->tab[y][x] == 'E')
		map->exit--;
	else if (map->tab[y][x] == '0')
	{
		map->tab[y][x] = '1';
		valid_path_recursive(map, y, x);
	}
	else if (map->tab[y][x] == 'C')
	{
		map->coin--;
		map->tab[y][x] = '1';
		valid_path_recursive(map, y, x);
	}
	if (map->coin == 0 && map->exit == 0) //
		return (1);
	return (0);
}

void	check_map(t_tools *map)
{
	int i;
	int j;

	i = 0;
	while (map->tab[map->line - 1][map->length] != '\0')
		map->length++;
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[i][j] != '\n' && map->tab[i][j] != '\0')
		{
			if (map->tab[0][j] != '1' || map->tab[i][0] != '1'
				|| map->tab[map->line - 1][j] != '1' || map->tab[i][map->length
				- 1] != '1')
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
	map->coin_checker = map->coin;
	if (map->player != 1 || map->coin < 1 || map->exit != 1)
		free_map(map);
	if (!valid_path(map, map->y, map->x))
		free_map(map);
}