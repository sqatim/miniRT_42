NAME= miniRT

SRC_PATH= src
SRC_NAME= main.c\
	minirt.c\
	shading.c\
	colour.c\
	hit_objet.c\
	phong.c\
	vector.c\
	vector2.c\
	tool.c\
	tool2.c\
	tool3.c\
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
	key_hook.c\
	translation.c\
	translation1.c\
	rotation_bonus.c\
	ft_space_split.c\
	hit_function.c\
	bmp_function.c\
	rotation.c\
	get_next_line.c\
	get_next_line_utils.c

HDR_PATH= headers
HDR_NAME= allocation.h \
	allocation_objet.h \
	bmp_function.h \
	calcul_p_n.h \
	camera.h \
	check_orcl.h \
	check_tools.h \
	check_w_wrong.h \
	colour.h \
	get_next_line.h \
	hit_function.h \
	hit_objet.h \
	key_hook.h \
	minirt.h \
	parcing.h \
	parcing_object.h \
	parcing_rcl.h \
	phong.h \
	print_error.h \
	rotation.h \
	rotation_bonus.h \
	structures.h \
	tool.h \
	translation.h \
	vector.h

OBJ_PATH= obj
OBJ_NAME= $(SRC_NAME:.c=.o)

OBJ= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
SRC= $(addprefix $(SRC_PATH)/,$(SRC_NAME))
HDR= $(addprefix $(HDR_PATH)/,$(HDR_NAME))

LIB_PATH= libft
LIB= libft.a

# **************************************************************************** #

COMP= gcc
CFLAGES= -Wall -Wextra -Werror 


# -L /usr/local/lib/
LD_FLAGS= -L$(LIB_PATH)  -lmlx -framework OpenGL -framework AppKit
LD_LIBS= -l$(patsubst lib%.a,%, $(LIB))

# /usr/local/include 
HDR_FLAGS= -I headers 

# **************************************************************************** #

all: lib $(NAME)

$(NAME): $(LIB_PATH)/$(LIB) $(OBJ)
	@$(COMP) $(LD_FLAGS) $(LD_LIBS) $(OBJ) -o $@
	@ echo "\033[1;32m>> $(NAME) binary is ready ;)\033[0m"

lib:
	@make -sC $(LIB_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HDR)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(COMP) $(CFLAGES) $(HDR_FLAGS) -o $@ -c $<

clean:
	@rm -fr $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@make -C $(LIB_PATH) clean
	@echo "\033[1;33m>> $(NAME) object files deleted.\033[0m" 

fclean: clean
	@rm -fr $(NAME)
	@make -C $(LIB_PATH) fclean
	@echo "\033[0;31m>> $(NAME) all resources deleted.\033[0m" 

re: fclean all
