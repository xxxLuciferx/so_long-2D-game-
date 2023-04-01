# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 14:59:32 by khaimer           #+#    #+#              #
#    Updated: 2023/04/01 21:11:27 by khaimer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror 



make: 
		$(CC) $(CFLAGS) get_next_line.c get_next_line_utils.c so_long.c ft_split.c map.c -o so_long