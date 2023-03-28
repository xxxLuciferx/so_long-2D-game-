# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 14:59:32 by khaimer           #+#    #+#              #
#    Updated: 2023/03/27 18:11:34 by khaimer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g


make: 
		$(CC) $(CFLAGS) get_next_line.c get_next_line_utils.c so_long.c ft_split.c -o so_long