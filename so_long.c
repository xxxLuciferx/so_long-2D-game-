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


void	free_tab(t_tools *tools)
{
	int i;

	i = 0;
	while(tools->tab[i])
	{
		free(tools->tab[i]);
		i++;
	}
	free(tools->tab);
	printf("bzzz\n");
	exit(1);
}

// void	check_error_map(t_tools *tools)
// {
// 	int i;
// 	int j;
	
// 	i = 0;
// 	j = 0;
// 	while(tools->tab[i][j] != '\n')
// 	{
// 		if(tools->tab[i][j] != '1')
// 		{
// 			free_tab(tools);
// 			write(1, "Error in map\n", 13);
// 			exit (1);
// 		}
// 		j++;
// 	}
// 	tools->lenght_counter = j;
// 	j = -1;
// 	while(tools->tab[i][j] != '\n')
// 	{
// 		j = j + 1;
		
// 	}
// }

void	check_all_map(t_tools *map)
{
	int i;
	int j;
	
	i = 0;
	while (map->tab[i])
	{
		j = 0;
		while(map->tab[i][j] != '\0')
		{
			if(map->tab[0][j] != '1' || map->tab[i][0] != '1' || map->tab[map->line_counter - 1][j] != '1' || map->tab[map->line_counter - 1][i] != '1')
				free_tab(map);
			j++;
		}
		i++;
	}
	
	
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
	
	check_all_map(map);
	// check_error_map(map);

	
}