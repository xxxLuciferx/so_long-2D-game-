/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 02:35:38 by khaimer           #+#    #+#             */
/*   Updated: 2023/04/14 20:37:43 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	s = (char *)malloc(count * size);
	if (!s)
		return (NULL);
	while (i < (count * size))
	{
		s[i] = 0;
		i++;
	}
	return (s);
}

int	math(int number)
{
	int	math;

	math = number * 60;
	return (math);
}

int	manage_keybord(int keycode, t_tools *map)
{
	int	print;

	print = 0;
	if (keycode == 53)
		exit(0);
	else if (keycode == KEY_UP || keycode == KEY_W)
		print = map_key_up(map);
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		print = map_key_down(map);
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		print = map_key_right(map);
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		print = map_key_left(map);
	if (print == 1)
	{
		map->mouvements = map->mouvements + 1;
		write(1, "Steps counter #", 15);
		ft_putnbr_fd(map->mouvements, 1);
		write(1, "\n", 1);
	}
	return (1);
}

void	graphic(t_tools *map)
{
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, \
	math(map->length), math(map->line), "so_long");
	map->img_coin = mlx_xpm_file_to_image(map->mlx, \
	"maps/coin.xpm", &map->img_width, &map->img_height);
	map->img_wall = mlx_xpm_file_to_image(map->mlx, \
	"maps/wall.xpm", &map->img_width, &map->img_height);
	map->img_exit = mlx_xpm_file_to_image(map->mlx, \
	"maps/exit.xpm", &map->img_width, &map->img_height);
	map->img_player = mlx_xpm_file_to_image(map->mlx, \
	"maps/player_right.xpm", &map->img_width, &map->img_height);
	put_game(map);
	mlx_key_hook(map->mlx_win, &manage_keybord, map);
	mlx_hook(map->mlx_win, 17, 0, &window_close, map);
	mlx_loop(map->mlx);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_tools	*map;
	char	*line;

	valid_map_name(argc, argv);
	map = ft_calloc(1, sizeof(t_tools));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || !map)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (line && (line[0] == '\0' || line[0] == '\n'))
			free_map(map);
		map->str = ft_strjoin(map->str, line);
		map->str = ft_strjoin(map->str, " ");
		if (!line)
			break ;
		free(line);
		map->line++;
	}
	map->tab = ft_split(map->str, ' ');
	map->land = ft_split(map->str, ' ');
	check_map(map);
	graphic(map);
}
