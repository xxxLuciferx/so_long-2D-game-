/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 02:40:19 by khaimer           #+#    #+#             */
/*   Updated: 2023/03/27 18:17:21 by khaimer          ###   ########.fr       */
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
	int		counter;
	char	**tab;
	char	*str;
	
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




#endif