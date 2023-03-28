/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 02:35:38 by khaimer           #+#    #+#             */
/*   Updated: 2023/03/27 18:23:03 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	check_map(t_tools *tools)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tools->tab[i])
	{
			printf("%s\n",tools->tab[i]);
			i++;	
	}
		// while (tools->tab[i][j])
		// {
		// 	if(tools->tab[i][0] != '1')
		// 		ft_error(tools);
		// 	if(tools->tab[i][j] == 'C')
			
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
	map->counter = 0;
	fd = open("land.ber",O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if(!line)
			break;
		map->str = ft_strjoin(map->str, line);
		free(line);
		map->counter++;
	}
	printf("%d\n", map->counter);
	map->tab = ft_split(map->str, '\n');
	check_map(map);
	
	
}