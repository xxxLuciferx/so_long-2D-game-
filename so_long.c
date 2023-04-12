/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 02:35:38 by khaimer           #+#    #+#             */
/*   Updated: 2023/04/12 18:21:53 by khaimer          ###   ########.fr       */
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
	
	map->coin_checker = map->coin;
	if(map->player != 1 || map->coin < 1 || map->exit != 1)
		free_map(map);
	if(!valid_path(map, map->y, map->x))
		free_map(map);
}

int math(int number)
{
	int math;

	math = number * 60;
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
	(void)map;
	// i = 0;
	// free(map->str);
	// while (map->tab[i++])
	// 	free(map->tab[i]);
	// i = 0;
	// while (map->land[i++])
	// 	free(map->land[i]);
	// while(1);
	exit(0);
}

void	map_key_up(t_tools *map)
{
	if(map->land[map->y - 1][map->x] != '1' && map->land[map->y - 1][map->x] != 'E')
	{
		if(map->land[map->y - 1][map->x] == 'C')
			map->coin_checker--;
		map->land[map->y][map->x] = '0';
		map->land[map->y - 1][map->x] = 'P';
		map->y--;
		mlx_clear_window(map->mlx, map->mlx_win);
		put_game(map);
	}
	if (map->land[map->y - 1][map->x] == 'E')
		if(map->coin_checker == 0)
			exit(0);
		// else
		// {
		// 	map->land[map->y][map->x] = '0';
			
		// 	map->land[map->y - 1][map->x] = 'P';
			
			
		// }
}

void	map_key_down(t_tools *map)
{
	if(map->land[map->y + 1][map->x] != '1' && map->land[map->y + 1][map->x] != 'E')
	{
		if(map->land[map->y + 1][map->x] == 'C')
			map->coin_checker--;
		map->land[map->y][map->x] = '0';
		map->land[map->y + 1][map->x] = 'P';
		map->y++;
		mlx_clear_window(map->mlx, map->mlx_win);
		put_game(map);
	}
	if (map->land[map->y + 1][map->x] == 'E')
		if(map->coin_checker == 0)
			exit(0);
}

void	map_key_left(t_tools *map)
{
	if(map->land[map->y][map->x - 1] != '1' && map->land[map->y][map->x - 1] != 'E')
	{
		if(map->land[map->y][map->x - 1] == 'C')
			map->coin_checker--;
		map->img_player = mlx_xpm_file_to_image(map->mlx, "player_left.xpm", &map->img_width, &map->img_height);
		map->land[map->y][map->x] = '0';
		map->land[map->y][map->x - 1] = 'P';
		map->x--;
		mlx_clear_window(map->mlx, map->mlx_win);
		put_game(map);
	}
	if (map->land[map->y][map->x - 1] == 'E')
	{
		
	}
		if(map->coin_checker == 0)
			exit(0);
}

void	map_key_right(t_tools *map)
{
	if(map->land[map->y][map->x + 1] != '1' && map->land[map->y][map->x + 1] != 'E')
	{
		if(map->land[map->y][map->x + 1] == 'C')
			map->coin_checker--;
		map->img_player = mlx_xpm_file_to_image(map->mlx, "player_right.xpm", &map->img_width, &map->img_height);
		map->land[map->y][map->x] = '0';
		map->land[map->y][map->x + 1] = 'P';
		map->x++;
		mlx_clear_window(map->mlx, map->mlx_win);
		put_game(map);
	}
	if (map->land[map->y][map->x + 1] == 'E')
	{
		if(map->coin_checker == 0)
			exit(0);
	}
}
int		manage_keybord(int keycode, t_tools *map)
{
	if(keycode == 53)
		exit(0);
	else if(keycode == KEY_UP)
		map_key_up(map);
	else if(keycode == KEY_DOWN)
		map_key_down(map);
	else if(keycode == KEY_RIGHT)
		map_key_right(map);
	else if(keycode == KEY_LEFT)
		map_key_left(map);
	printf("%d\n", map->coin_checker);
	return 1;
}

void graphic(t_tools *map)
{
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, math(map->length), math(map->line), "so_long");
	map->img_coin = mlx_xpm_file_to_image(map->mlx, "coin.xpm", &map->img_width, &map->img_height);
	map->img_wall = mlx_xpm_file_to_image(map->mlx, "wall.xpm", &map->img_width, &map->img_height);
	map->img_exit = mlx_xpm_file_to_image(map->mlx, "exit.xpm", &map->img_width, &map->img_height);
	map->img_player = mlx_xpm_file_to_image(map->mlx, "player_right.xpm", &map->img_width, &map->img_height);
	put_game(map);
	mlx_key_hook(map->mlx_win, &manage_keybord, map);
	mlx_loop(map->mlx);
}

int main(int argc, char **argv)
{
	int	fd;
	t_tools *map;
	char *line;

	map = calloc(1, sizeof(t_tools));
	valid_map_name(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if(fd < 0 || !map)
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
	map->tab = ft_split(map->str, ' ');
	map->land = ft_split(map->str, ' ');	
	check_map(map);
	// printf("%d\n", map->coin_checker);
	graphic(map);
}
	
