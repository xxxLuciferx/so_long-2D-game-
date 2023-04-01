/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 02:40:19 by khaimer           #+#    #+#             */
/*   Updated: 2023/04/01 22:33:19 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_tools
{
	int x;
	int y;
	char	*str;
	char	**tab;
	int		line;
	int		length;
	int		coin;
	int		player;
	int		exit;	
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