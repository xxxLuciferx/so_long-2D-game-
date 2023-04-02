/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 02:35:38 by khaimer           #+#    #+#             */
/*   Updated: 2023/04/02 17:23:38 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"


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
	if(!valid_path(map, map->y, map->x))
		free_map(map);
	printf("NADY\n");
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

	map = calloc(1, sizeof(t_tools));
	map->line = 0;
	map->coin = 0;
	map->exit = 0;
	map->player = 0;
	map->length = 0;
	valid_map_name(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if(fd < 0)
		exit(1);
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
	// printf("line: %d\n", map->line);
	map->tab = ft_split(map->str, ' ');
	check_map(map);
	// int j;
	// int i = 0;
	// while (map->tab[i])
	// {
	// 	j = 0;
	// 	while (map->tab[i][j] != '\0')
	// 	{
	// 		printf("%c", map->tab[i][j]);
	// 		j++;
	// 	}
	// 	i++;
	// }
}
	
