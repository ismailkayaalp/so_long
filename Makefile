# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikayaalp <ikayaalp@student.42kocaeli.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 21:25:00 by ikayaalp          #+#    #+#              #
#    Updated: 2022/08/11 21:25:00 by ikayaalp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -framework OpenGL -framework AppKit -L./minilibx -lmlx

all:
	$(CC) $(FLAGS) *.c -o solong
fclean:
	rm -rf a.out solong
