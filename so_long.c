/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 02:35:38 by khaimer           #+#    #+#             */
/*   Updated: 2023/04/08 00:42:25 by khaimer          ###   ########.fr       */
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
	// printf("NADY\n");
	// printf("player = %d, %d\n", map->x, map->y);
	// printf("player : %d | coin : %d | exit : %d\n", map->player, map->coin, map->exit);
	// printf("%d\n", map->length);
		
	// if(valid_path(map, map->y, map->x))
	// {
	// 	printf("nik\n");
	// }
}

int math(int number)
{
	int math;

	math = number * 60;
	// if(number > 2880)
	// {
	// 	write(1, "map too large\n", 14);
	// 	//FIX THIS
	// 	exit(1);
	// }
	return(math);
}


void	put_game(t_tools *map)
{
	int	i;
	int	j;
	
	j = 0;
	i = 0;
	while (map->land[i])
	{
		j = 0;
		while (map->land[i][j])
		{
			// if(map->land[i][j] == '0')
			// 	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img_test, (j * 60), (i * 60));
			if(map->land[i][j] == 'C')
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->img_coin, (j * 60), (i * 60));
			else if(map->land[i][j] == 'E')
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->img_exit, (j * 60), (i * 60));
			else if(map->land[i][j] == '1')
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->img_wall, (j * 60), (i * 60));
			else if(map->land[i][j] == 'P')
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->img_player, (j * 60), (i * 60));
			j++;
		}
		i++;
	}
}

void	free_tab(t_tools *map)
{
	// int i;

	// i = 0;
	free(map->str);
	// while (map->tab[i++])
	// 	free(map->tab[i]);
	// i = 0;
	// while (map->land[i++])
	// 	free(map->land[i]);
	while(1);
	exit(0);
}

int		left(int keycode, t_tools *map)
{
	if(keycode == 53)
		free_tab(map);
	
	// if(keycode == KEY_UP)
	// {
		
	// }
	return 0;
}

void graphic(t_tools *map)
{
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, math(map->length), math(map->line), "so_long");
	map->img_coin = mlx_xpm_file_to_image(map->mlx, "coin.xpm", &map->img_width, &map->img_height);
	map->img_wall = mlx_xpm_file_to_image(map->mlx, "walll.xpm", &map->img_width, &map->img_height);
	map->img_exit = mlx_xpm_file_to_image(map->mlx, "exit.xpm", &map->img_width, &map->img_height);
	map->img_player = mlx_xpm_file_to_image(map->mlx, "player.xpm", &map->img_width, &map->img_height);
	put_game(map);
}



void	mouvements(t_tools *map)
{
	// mlx_hook(map->mlx_win, 2, 0, &left, map->mlx);
	// mlx_key_hook(map->mlx_win, &left, NULL);
	mlx_key_hook(map->mlx_win, &left, &map);

	
	mlx_loop(map->mlx);

	// mlx_mouse_hook(vars.win, mouse_hook, &vars);
}

int main(int argc, char **argv)
{
	int	fd;
	t_tools *map;
	char *line;

	map = calloc(1, sizeof(t_tools));
	// map->line = 0;
	// map->coin = 0;
	// map->exit = 0;
	// map->player = 0;
	// map->length = 0;
	// map->land = NULL;
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
	map->land = ft_split(map->str, ' ');
	check_map(map);
	graphic(map);
	mouvements(map);
	// mlx_key_hook(map->mlx_win, &left, NULL);
	
}
	
