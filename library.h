/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 02:40:19 by khaimer           #+#    #+#             */
/*   Updated: 2023/04/10 20:44:41 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif


#define KEY_UP 126
#define KEY_DOWN 125
#define KEY_RIGHT 124
#define KEY_LEFT 123

typedef struct s_tools
{
	int x;
	int y;
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

//GET_NEX_LINE
char	*get_next_line(int fd);
char	*get_last(char *static_string);
char	*get_first(char *static_string);
int		ft_strchr(char *string, char c);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*invalid_fd(char *string, char **static_string);

//SPLIT
char	**ft_split(char const *s, char c);

int		valid_path(t_tools *map, int y, int x);
void	valid_path_recursive(t_tools *map, int y, int x);
void	valid_map_name(int argc, char **argv);
void	free_map(t_tools *map);


#endif