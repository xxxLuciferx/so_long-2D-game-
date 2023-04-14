/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_codes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 01:42:20 by khaimer           #+#    #+#             */
/*   Updated: 2023/04/14 18:44:40 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	put_game(t_tools *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->land[i])
	{
		j = 0;
		while (map->land[i][j])
		{
			if (map->land[i][j] == 'C')
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->img_coin, \
				(j * 60), (i * 60));
			else if (map->land[i][j] == 'E')
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->img_exit, \
				(j * 60), (i * 60));
			else if (map->land[i][j] == '1')
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->img_wall, \
				(j * 60), (i * 60));
			else if (map->land[i][j] == 'P')
				mlx_put_image_to_window(map->mlx, map->mlx_win, \
				map->img_player, (j * 60), (i * 60));
			j++;
		}
		i++;
	}
}

int	map_key_up(t_tools *map)
{
	if (map->land[map->y - 1][map->x] != '1' && map->land[map->y
		- 1][map->x] != 'E')
	{
		if (map->land[map->y - 1][map->x] == 'C')
			map->coin_checker--;
		map->land[map->y][map->x] = '0';
		map->land[map->y - 1][map->x] = 'P';
		map->y--;
		mlx_clear_window(map->mlx, map->mlx_win);
		put_game(map);
		return (1);
	}
	if (map->land[map->y - 1][map->x] == 'E' && map->coin_checker == 0)
		game_finish();
	return (0);
}

int	map_key_down(t_tools *map)
{
	if (map->land[map->y + 1][map->x] != '1' && map->land[map->y
		+ 1][map->x] != 'E')
	{
		if (map->land[map->y + 1][map->x] == 'C')
			map->coin_checker--;
		map->land[map->y][map->x] = '0';
		map->land[map->y + 1][map->x] = 'P';
		map->y++;
		mlx_clear_window(map->mlx, map->mlx_win);
		put_game(map);
		return (1);
	}
	if (map->land[map->y + 1][map->x] == 'E' && map->coin_checker == 0)
		game_finish();
	return (0);
}

int	map_key_left(t_tools *map)
{
	if (map->land[map->y][map->x - 1] != '1' && map->land[map->y][map->x
		- 1] != 'E')
	{
		if (map->land[map->y][map->x - 1] == 'C')
			map->coin_checker--;
		map->img_player = mlx_xpm_file_to_image(map->mlx,
				"maps/player_left.xpm", &map->img_width, &map->img_height);
		map->land[map->y][map->x] = '0';
		map->land[map->y][map->x - 1] = 'P';
		map->x--;
		mlx_clear_window(map->mlx, map->mlx_win);
		put_game(map);
		return (1);
	}
	if (map->land[map->y][map->x - 1] == 'E' && map->coin_checker == 0)
		game_finish();
	return (0);
}

int	map_key_right(t_tools *map)
{
	if (map->land[map->y][map->x + 1] != '1' && map->land[map->y][map->x
		+ 1] != 'E')
	{
		if (map->land[map->y][map->x + 1] == 'C')
			map->coin_checker--;
		map->img_player = mlx_xpm_file_to_image(map->mlx,
				"maps/player_right.xpm", &map->img_width, &map->img_height);
		map->land[map->y][map->x] = '0';
		map->land[map->y][map->x + 1] = 'P';
		map->x++;
		mlx_clear_window(map->mlx, map->mlx_win);
		put_game(map);
		return (1);
	}
	if (map->land[map->y][map->x + 1] == 'E' && map->coin_checker == 0)
		game_finish();
	return (0);
}
