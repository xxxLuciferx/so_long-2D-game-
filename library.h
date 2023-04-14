/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 02:40:19 by khaimer           #+#    #+#             */
/*   Updated: 2023/04/14 20:43:55 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_H
# define LIBRARY_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123

# define KEY_A 0
# define KEY_D 2
# define KEY_S 1
# define KEY_W 13

typedef struct s_tools
{
	int		x;
	int		y;
	int		mouvements;
	char	*str;
	char	**tab;
	char	**land;
	int		line;
	int		length;
	int		player;
	int		coin_checker;
	int		coin;
	int		exit;	
	void	*mlx;
	void	*mlx_win;
	void	*img_wall;
	void	*img_coin;
	void	*img_player;
	void	*img_exit;
	int		img_width;
	int		img_height;
}t_tools;

char	*get_next_line(int fd);
char	*get_last(char *static_string);
char	*get_first(char *static_string);
int		ft_strchr(char *string, char c);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*invalid_fd(char *string, char **static_string);
char	**ft_split(char const *s, char c);
void	ft_putnbr_fd(int n, int fd);
int		valid_path(t_tools *map, int y, int x);
void	valid_path_recursive(t_tools *map, int y, int x);
void	valid_map_name(int argc, char **argv);
void	free_map(t_tools *map);
void	check_map(t_tools *map);
void	free_tab(t_tools *map);
void	game_finish(void);
int		window_close(t_tools *map);
void	put_game(t_tools *map);
int		map_key_up(t_tools *map);
int		map_key_down(t_tools *map);
int		map_key_left(t_tools *map);
int		map_key_right(t_tools *map);

#endif