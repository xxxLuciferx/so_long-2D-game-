/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 02:35:38 by khaimer           #+#    #+#             */
/*   Updated: 2023/03/30 21:35:48 by khaimer          ###   ########.fr       */
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
	if(map->tab[x][y] == 'E')
		return 1;
	if((map->tab[y - 1][x] == '0' || map->tab[y - 1][x] == 'C') && map->tab[y - 1][x] != '\0')
		valid_path(map, y - 1, x);
	if((map->tab[y + 1][x] == '0' || map->tab[y + 1][x] == 'C') && map->tab[y + 1][x] != '\0')
		valid_path(map, y + 1, x);
	if((map->tab[y][x - 1] == '0' || map->tab[y][x - 1] == 'C') && map->tab[y][x - 1] != '\0')
		valid_path(map, y, x - 1);
	if((map->tab[y][x + 1] == '0' || map->tab[y][x + 1] == 'C') && map->tab[y][x + 1] != '\0')
		valid_path(map, y, x + 1);
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
	while (map->tab[i])
	{
		j = 0;
		while(map->tab[i][j] != '\0')
		{
			if(map->tab[0][j] != '1' || map->tab[i][0] != '1' || map->tab[map->line_counter - 1][j] != '1' || map->tab[map->line_counter - 1][i] != '1')
				free_map(map);
			j++;
			if(map->tab[i][j] == 'C')
				map->coin++;
			if(map->tab[i][j] == 'P')
			{
				map->y = i;
				map->x = j;
				map->player++;
			}
			if(map->tab[i][j] == 'E')
				map->exit++;
		}
		i++;
	}
	if(map->player != 1 || map->coin < 1 || map->exit != 1)
		free_map(map);
	printf("%d, %d", map->x, map->y);
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
	map->line_counter = 0;
	fd = open("land.ber",O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if(!line)
			break;
		map->str = ft_strjoin(map->str, line);
		free(line);
		map->line_counter++;
	}
	map->tab = ft_split(map->str, '\n');
	
	check_map(map);
	// printf("player : %d | coin : %d | exit : %d", map->player, map->coin, map->exit);


	
}
	// check_error_map(map);
	// int i = 0;
	// int j;
	// while (map->tab[i])
	// {
	// 	j = 0;
	// 	while (map->tab[i][j])
	// 	{
	// 		printf("%c", map->tab[i][j]);
	// 		j++;
	// 	}
	// 	// printf("\n");
	// 	i++;
	// }