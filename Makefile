# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 05:44:49 by mmoreira          #+#    #+#              #
#    Updated: 2022/02/17 10:52:05 by mmoreira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------------------------//---------------------------------------
SRC_DIR	=	./sources \
			./sources/make_mundo \
			./sources/check_mundo \
			./sources/init_render \
			./sources/init_render/intersect_elem \
			./sources/vector_oper

SRC		=	miniRT.c \
			\
			make_mundo.c \
			set_elem_I.c \
			set_elem_II.c \
			set_rotation.c \
			make_mundo_utils.c \
			\
			check_mundo.c \
			check_elem_I.c \
			check_elem_II.c \
			\
			init_render.c \
			make_image.c \
			ray_tracer.c \
			\
			set_intersect.c \
			pl_intersect.c \
			sp_intersect.c \
			sq_intersect.c \
			tr_intersect.c \
			cy_intersect.c \
			\
			phong_ilum.c \
			windows_control.c \
			bitmap_control.c \
			\
			vector_oper_I.c \
			vector_oper_II.c \
			vector_oper_III.c \

OBJ_DIR	=	./builds
OBJ		=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

INCD_DIR	=	-I ./includes \
				-I ./libft
INCD		=	miniRT.h \
				structs.h
#--------------------------------------//---------------------------------------
vpath %.c $(SRC_DIR)
vpath %.h $(INCD_DIR)

NAME		=	miniRT

MODULE		=	./libft/libft.a

FLAGS		=	-Wall -Wextra -Werror

MLX_FLAGS	=	-lbsd -lmlx -lXext -lX11 -lm

RM			=	rm -rf

CC			=	clang
#--------------------------------------//---------------------------------------
all:		$(NAME)


$(NAME):	$(MODULE) $(OBJ)
	$(CC) $(OBJ) $(FLAGS) $(INCD_DIR) $(MODULE) $(MLX_FLAGS) -o $(NAME)
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|             miniRT criado            |"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

$(MODULE):
	@make -C libft

$(OBJ_DIR)/%.o:	%.c $(INCD)
	mkdir -p $(OBJ_DIR)
	$(CC) -c -o $@ $(CFLAGS) $(INCD_DIR) $<
#--------------------------------------//---------------------------------------
clean:
	$(RM) $(OBJ)
	make clean -C libft
	@echo "\033[1;31m"
	@echo "/ ************************************ \\"
	@echo "|         Arquivos .o deletados        |"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

fclean:		clean
	$(RM) $(NAME)
	make aclean -C libft
	@echo "\033[1;31m"
	@echo "/ ************************************ \\"
	@echo "|            miniRT deletado           |"
	@echo "\\ ************************************ /"
	@echo "\033[0m"
#--------------------------------------//---------------------------------------

re:			fclean all

git:
	git add .
	git status
	git commit -m "$m"

.PHONY:		all clean fclean re git
