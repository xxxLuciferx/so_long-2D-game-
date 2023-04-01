/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 02:35:38 by khaimer           #+#    #+#             */
/*   Updated: 2023/04/01 17:32:57 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"


void	free_map(t_tools *map)
{
	int i;

	i = 0;
	while(map->tab[i])
	{
		free(map->tab[i]);
		i++;
	}
	free(map->tab);
	write(1, "Error in map\n", 13);
	exit(1);
}

int	valid_path(t_tools *map, int y, int x)
{
	if((map->tab[y - 1][x] != '1'))
	{
		map->tab[y - 1][x] = '1';
		valid_path(map, y - 1, x);
	}
	if(map->tab[y + 1][x] != '1')
	{
		map->tab[y + 1][x] = '1';
		valid_path(map, y + 1, x);
	}
	if(map->tab[y][x - 1] != '1')
	{
		map->tab[y][x - 1] = '1';
		valid_path(map, y, x - 1);
	}
	if(map->tab[y][x + 1] != '1')
	{
		map->tab[y][x + 1] = '1';
		valid_path(map, y, x + 1);
	}
	printf("coin = %d, exit = %d\n",map->coin,map->exit);
	return 0;
}

void	check_map(t_tools *map)
{
	int i;
	int j;
	
	i = 0;
	map->coin = 0;
	map->exit = 0;
	map->player = 0;
	map->length = 0;
	while (map->tab[map->line - 1][map->length] != '\0')
		map->length++;
	while (map->tab[i])
	{
		j = 0;
		while(map->tab[i][j] != '\n' && map->tab[i][j] != '\0')
		{
			if(map->tab[0][j] != '1' || map->tab[i][0] != '1' || map->tab[map->line - 1][j] != '1' || map->tab[i][map->length - 1] != '1')
				free_map(map);
			if(map->tab[i][j] == 'C')
				map->coin++;
			else if(map->tab[i][j] == 'P')
			{
				map->y = i;
				map->x = j;
				map->player++;
			}
			else if(map->tab[i][j] == 'E')
				map->exit++;
			else if(map->tab[i][j] != '0' && map->tab[i][j] != 'P' && map->tab[i][j] != 'C' && map->tab[i][j] != 'E' && map->tab[i][j] != '1')
				free_map(map);
			j++;
		}
		i++;
	}
	if(map->player != 1 || map->coin < 1 || map->exit != 1)
		free_map(map);
	if(valid_path(map, map->y, map->x) == 1)
		printf("ok\n");
	// printf("player = %d, %d\n", map->x, map->y);
	// printf("player : %d | coin : %d | exit : %d\n", map->player, map->coin, map->exit);
	// printf("%d\n", map->length);
		
	// if(valid_path(map, map->y, map->x))
	// {
	// 	printf("nik\n");
	// }
}

int main(int argc, char **argv)
{
	int	fd;
	t_tools *map;
	char *line;

	(void)argv;
	(void)argc;
	map = calloc(1, sizeof(t_tools));
	map->line = 0;
	fd = open("land.ber",O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if(line && (line[0] == '\0' || line[0] == '\n'))
		{
			printf("ERROR\n");
			exit(1);
		}
		map->str = ft_strjoin(map->str, line);
		map->str = ft_strjoin(map->str, " ");
		free(line);
		if(!line)
			break;
		map->line++;	
	}
	printf("line: %d\n", map->line);
	map->tab = ft_split(map->str, ' ');
	check_map(map);
	int j;
	int i = 0;
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[i][j] != '\0')
		{
			printf("%c", map->tab[i][j]);
			j++;
		}
		i++;
	}
}
	
