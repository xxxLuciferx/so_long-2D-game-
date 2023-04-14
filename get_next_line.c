/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:33:33 by khaimer           #+#    #+#             */
/*   Updated: 2023/03/27 16:33:36 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

char	*invalid_fd(char *string, char **static_string)
{
	free(string);
	free(*static_string);
	*static_string = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	int			read_char;
	char		*string;
	char		*pointer;
	static char	*static_string;

	read_char = 1;
	string = malloc(BUFFER_SIZE + 1);
	while (read_char != 0)
	{
		read_char = read(fd, string, BUFFER_SIZE);
		if (read_char < 0)
			return (invalid_fd(string, &static_string));
		string[read_char] = '\0';
		static_string = ft_strjoin(static_string, string);
		if (ft_strchr(string, '\n'))
			break ;
	}
	free(string);
	string = get_first(static_string);
	pointer = static_string;
	static_string = get_last(static_string);
	free(pointer);
	return (string);
}
