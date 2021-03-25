NAME= miniRT

SRC_PATH= src
SRC_B_PATH= bonus_src
HDR_PATH= headers
HDR_B_PATH= bonus_headers
OBJ_PATH= obj
LIB_PATH= libft
OGL_PATH= ./minilibx_opengl_20191021
MMS_PATH= ./minilibx_mms_20200219

SRC_NAME=main.c\
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
	ft_space_split.c\
	hit_function.c\
	bmp_function.c\
	rotation.c\
	get_next_line.c\
	get_next_line_utils.c

SRC_B_NAME= allocation_bonus.c\
	allocation_objet2_bonus.c\
	allocation_objet_bonus.c\
	bmp_function_bonus.c\
	calcul_p_n_bonus.c\
	camera_bonus.c\
	check_bonus.c\
	check_object2_bonus.c\
	check_object_bonus.c\
	check_rcl_bonus.c\
	check_tools_bonus.c\
	check_w_wrong_bonus.c\
	colour_bonus.c\
	ft_space_split_bonus.c\
	get_next_line_bonus.c\
	get_next_line_utils_bonus.c\
	hit_function_bonus.c\
	hit_objet_bonus.c\
	key_hook_bonus.c\
	key_hook2_bonus.c\
	main_bonus.c\
	minirt_bonus.c\
	parcing_bonus.c\
	parcing_object_bonus.c\
	parcing_rcl_bonus.c\
	phong_bonus.c\
	print_error_bonus.c\
	rotation_bonus.c\
	rotation_key_bonus.c\
	shading_bonus.c\
	tool2_bonus.c\
	tool3_bonus.c\
	tool_bonus.c\
	translation1_bonus.c\
	translation_bonus.c\
	vector2_bonus.c\
	vector_bonus.c

HDR_NAME= calcul.h \
	check.h \
	get_next_line.h \
	minirt.h \
	parcing.h \
	structures.h \
	tool.h \

HDR_B_NAME= calcul_bonus.h\
	check_bonus.h\
	get_next_line_bonus.h\
	minirt_bonus.h\
	parcing_bonus.h\
	structures_bonus.h\
	tool_bonus.h\
	transformation_bonus.h

OBJ_NAME= $(SRC_NAME:.c=.o)
OBJ_B_NAME= $(SRC_B_NAME:.c=.o)

OBJ= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJ_B= $(addprefix $(OBJ_PATH)/,$(OBJ_B_NAME))
SRC= $(addprefix $(SRC_PATH)/,$(SRC_NAME))
SRC_B= $(addprefix $(SRC_B_PATH)/,$(SRC_B_NAME))
HDR= $(addprefix $(HDR_PATH)/,$(HDR_NAME))
HDR_B= $(addprefix $(HDR_B_PATH)/,$(HDR_B_NAME))
HDR_B= $(addprefix $(HDR_B_PATH)/,$(HDR_B_NAME))

LIB= libft.a
FLAGS= -Wall -Wextra -Werror
LLIB_FLAG= -L$(LIB_PATH) libft/libft.a
LMLX_FLAG= -L ./minilibx_opengl_20191021 libmlx.a -L ./minilibx_mms_20200219 libmlx.dylib -framework OpenGL -framework AppKit
IMLX_FLAG= -I /usr/local/include
H_FLAG= -I headers
H_B_FLAG= -I bonus_headers
#***************************************************************************** #

COMP= gcc

all: lib ogl mms $(NAME) 

$(NAME) : $(LIB_PATH)/$(LIB) $(OBJ) 
	@cp ./minilibx_opengl_20191021/libmlx.a .
	@cp ./minilibx_mms_20200219/libmlx.dylib .
	@$(COMP) $(H_FLAG) $(LLIB_FLAG) $(LMLX_FLAG) $(IMLX_FLAG)  $(OBJ) -o $@
	@clear
	@echo "			Made by : \033[1;91mSqatim\033[m"
	@echo "          _       _______ _____    "
	@echo "         (_)     (_) ___ \_   _|   "
	@echo "  _ __ ___  _ _ __  _| |_/ / | |   "
	@echo " | '_ ' _ \| | '_ \| |    /  | |   "
	@echo " | | | | | | | | | | | |\ \  | |   "
	@echo " |_| |_| |_|_|_| |_|_\_| \_| \_/   "
	@echo "Compilation of $(NAME):  \033[1;32mOK\033[m"


bonus : lib ogl mms $(LIB_PATH)/$(LIB) $(OBJ_B) $(OGL) $(MMS)
	@cp ./minilibx_opengl_20191021/libmlx.a .
	@cp ./minilibx_mms_20200219/libmlx.dylib .
	@$(COMP) $(H_B_FLAG) $(LLIB_FLAG) $(LMLX_FLAG) $(IMLX_FLAG)  $(OBJ_B) -o $(NAME)
	@clear
	@echo "			Made by : \033[1;91mSqatim\033[m"
	@echo "          _       _______ _____    "
	@echo "         (_)     (_) ___ \_   _|   "
	@echo "  _ __ ___  _ _ __  _| |_/ / | |   "
	@echo " | '_ ' _ \| | '_ \| |    /  | |   "
	@echo " | | | | | | | | | | | |\ \  | |   "
	@echo " |_| |_| |_|_|_| |_|_\_| \_| \_/   "
	@echo "Compilation of $(NAME):  \033[1;32mOK\033[m"

lib:
	@make -sC $(LIB_PATH)

ogl:
	@make -sC $(OGL_PATH)

mms:
	@make -sC $(MMS_PATH)

$(OBJ_PATH)/%.o:  $(SRC_PATH)/%.c $(HDR)
	@mkdir -p $(OBJ_PATH) 
	@$(COMP) $(FLAGS) $(H_FLAG)  -o $@ -c $<

$(OBJ_PATH)/%.o:  $(SRC_B_PATH)/%.c $(HDR_B) 
	@mkdir -p $(OBJ_PATH) 
	@$(COMP) $(FLAGS) $(H_B_FLAG)  -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LIB_PATH)
	@echo "\033[1;33m>> all objects files are deleted.\033[0m" 

fclean: clean
	@rm -rf $(NAME)
	@rm -rf libmlx.a
	@rm -rf libmlx.dylib
	@make fclean -C $(LIB_PATH)
	@make clean -sC $(OGL_PATH)
	@make clean -sC $(MMS_PATH)
	@echo "\033[0;31m>> $(NAME) && all obbjects are deleted.\033[0m" 

re : fclean all