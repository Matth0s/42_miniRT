SRC		=	./sources/miniRT.c \
			\
			./sources/make_mundo/make_mundo.c \
			./sources/make_mundo/set_elem_I.c \
			./sources/make_mundo/set_elem_II.c \
			./sources/make_mundo/make_mundo_utils.c \
			\
			./sources/check_mundo/check_mundo.c \
			./sources/check_mundo/check_elem_I.c \
			./sources/check_mundo/check_elem_II.c \
			\
			./sources/init_render/init_render.c \
			./sources/init_render/make_image.c \
			./sources/init_render/ray_tracer.c \
			./sources/init_render/intersect_elem/set_intersect.c \
			./sources/init_render/intersect_elem/pl_intersect.c \
			./sources/init_render/intersect_elem/sp_intersect.c \
			./sources/init_render/intersect_elem/sq_intersect.c \
			./sources/init_render/intersect_elem/tr_intersect.c \
			./sources/init_render/intersect_elem/cy_intersect.c \
			./sources/init_render/phong_ilum.c \
			./sources/init_render/windows_control.c \
			./sources/init_render/bitmap_control.c \
			\
			./sources/vector_oper/vector_oper_I.c \
			./sources/vector_oper/vector_oper_II.c \
			./sources/vector_oper/vector_oper_III.c \

OBJ		=	${SRC:.c=.o}
#--------------------------------------//---------------------------------------

NAME		=	miniRT

INCLUDE		=	-I includes -I libft

MODULE		=	./libft/libft.a

FLAGS		=	-Wall -Wextra -Werror

MLX_FLAGS	=	-lbsd -lmlx -lXext -lX11 -lm

CC			=	clang
#--------------------------------------//---------------------------------------
.c.o:
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o}
	@echo "  Criando .o de "$<
#--------------------------------------//---------------------------------------
all:		$(NAME)

$(MODULE):
	@make -C libft

$(NAME):	$(MODULE) $(OBJ)
	@$(CC) $(OBJ) $(FLAGS) $(INCLUDE) $(MODULE) $(MLX_FLAGS) -o $(NAME)
	@echo ""
	@echo "/ ************************************ \\"
	@echo "|             miniRT criado            |"
	@echo "\\ ************************************ /"
	@echo ""
#--------------------------------------//---------------------------------------
clean:
	@rm -rf $(OBJ)
	@make clean -C libft
	@echo ""
	@echo "/ ************************************ \\"
	@echo "|         Arquivos .o deletados        |"
	@echo "\\ ************************************ /"
	@echo ""

fclean:		clean
	@rm -rf $(NAME)
	@make aclean -C libft
	@echo ""
	@echo "/ ************************************ \\"
	@echo "|            miniRT deletado           |"
	@echo "\\ ************************************ /"
	@echo ""
#--------------------------------------//---------------------------------------

re:			fclean all

git:
	git add .
	git status
	git commit -m "$m"
	git push

.PHONY:		all clean fclean re git
