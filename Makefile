# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 14:59:32 by khaimer           #+#    #+#              #
#    Updated: 2023/04/13 01:44:10 by khaimer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = get_next_line.c get_next_line_utils.c so_long.c ft_split.c map.c tools.c key_codes.c

CFLAGS = -Wall -Wextra -Werror -Imlx

OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${SRC_BONUS:.c=.o}

all : $(NAME)


$(NAME): $(OBJ)
		$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
				cc $(CFLAGS) $^ -o $(NAME_BONUS)

clean : 
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -rf $(NAME) $(NAME_BONUS)

re : fclean all
