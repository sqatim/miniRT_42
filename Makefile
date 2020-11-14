# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/30 04:53:16 by mac               #+#    #+#              #
#    Updated: 2020/11/14 13:49:40 by sqatim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = miniRT

MLX = -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

CFLAGE =  -g -Wall -Wextra -Werror

GREEN = \033[0;32m

DEFAULT = \033[0m

GNL = ./GNL/get_next_line.c ./GNL/get_next_line_utils.c

SRCS = main.c\
	minirt.c\
	shading.c\
	colour.c\
	hit_objet.c\
	phong.c\
	vector.c\
	vector2.c\
	tool.c\
	tool2.c\
	parcing.c\
	parcing_object.c\
	parcing_rcl.c\
	allocation_objet.c\
	allocation_objet2.c\
	calcul_p_n.c\
	allocation.c\
	check.c\
	check_tools.c\
	check_rcl.c\
	check_object.c\
	check_object2.c\
	check_w_wrong.c\
	print_error.c\
	camera.c\
	translation.c\
	translation1.c\
	rotation_bonus.c\
	ft_space_split.c\
	hit_function.c\
	bmp_function.c\
	rotation.c\
	$(GNL)

OBJ = $(SRCS:.c=.o)	   

	
all: $(NAME)

$(NAME): $(OBJ)
		@rm -rf miniRT
		@gcc $(CFLAGE)  $(OBJ) $(MLX) libft/libft.a -o miniRT
		@echo "			Made by : \033[1;91mSqatim\033[m"
		@echo "          _       _______ _____    "
		@echo "         (_)     (_) ___ \_   _|   "
		@echo "  _ __ ___  _ _ __  _| |_/ / | |   "
		@echo " | '_ ' _ \| | '_ \| |    /  | |   "
		@echo " | | | | | | | | | | | |\ \  | |   "
		@echo " |_| |_| |_|_|_| |_|_\_| \_| \_/   "
		@echo "Compilation of miniRT:  \033[1;32mOK\033[m"

%.o: %.c
	@$(CC) -o $@ -c $< -I header
	@echo "creating $@ $(GREEN){DONE} $(DEFAULT)"
	

clean:
		@rm -rf $(OBJ)
		@echo "miniRT : Removing Objs"

fclean: clean
		@rm -rf $(NAME)
		@echo "miniRT : Removing miniRT"

re: fclean all

