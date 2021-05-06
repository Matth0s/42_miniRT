
SRC		=	./func_alloc/ft_calloc.c ./func_alloc/ft_itoa_base.c \
			./func_alloc/ft_itoa.c ./func_alloc/ft_split.c \
			./func_alloc/ft_strdup.c ./func_alloc/ft_strjoin.c \
			./func_alloc/ft_strmapi.c ./func_alloc/ft_strtrim.c \
			./func_alloc/ft_substr.c ./func_alloc/ft_utoa_base.c \
			./func_alloc/ft_utoa.c \
			\
			./func_char/ft_isalnum.c ./func_char/ft_isalpha.c \
			./func_char/ft_isascii.c ./func_char/ft_isdigit.c \
			./func_char/ft_isprint.c ./func_char/ft_isspace.c \
			./func_char/ft_tolower.c ./func_char/ft_toupper.c \
			\
			./func_mem/ft_memccpy.c ./func_mem/ft_memchr.c \
			./func_mem/ft_memcmp.c ./func_mem/ft_memcpy.c \
			./func_mem/ft_memmove.c ./func_mem/ft_memset.c \
			\
			./func_fd/ft_putchar_fd.c ./func_fd/ft_putendl_fd.c \
			./func_fd/ft_putnbr_fd.c ./func_fd/ft_putstr_fd.c \
			\
			./func_str/ft_atod.c ./func_str/ft_atoi.c \
			./func_str/ft_bzero.c ./func_str/ft_strchr.c \
			./func_str/ft_strlcat.c ./func_str/ft_strlcpy.c \
			./func_str/ft_strlen.c ./func_str/ft_strncmp.c \
			./func_str/ft_strnstr.c ./func_str/ft_strrchr.c \
			\
			./func_gnl/get_next_line_utils.c ./func_gnl/get_next_line.c \
			\
			./func_printf/check_flags.c ./func_printf/init_struct.c \
			./func_printf/print_type.c ./func_printf/ft_printf.c \
			./func_printf/print_address.c ./func_printf/print_char.c \
			./func_printf/print_hex.c ./func_printf/print_int.c \
			./func_printf/print_string.c ./func_printf/print_uint.c \
			./func_printf/while_print.c \
			\
			./func_outros/ft_numdigt.c ./func_outros/ft_check_base.c \
			./func_outros/ft_free_split.c\
			\
			./func_lst/ft_lstadd_back.c ./func_lst/ft_lstadd_front.c \
			./func_lst/ft_lstclear.c ./func_lst/ft_lstdelone.c \
			./func_lst/ft_lstfirst.c ./func_lst/ft_lstiter.c \
			./func_lst/ft_lstlast.c ./func_lst/ft_lstloop_start.c \
			./func_lst/ft_lstloop_stop.c ./func_lst/ft_lstmap.c \
			./func_lst/ft_lstnew.c ./func_lst/ft_lstsize.c \

OBJ		=	${SRC:.c=.o}
#--------------------------------------//---------------------------------------
NAME	=	libft.a

FLAGS	=	-Wall -Wextra -Werror

CC		=	clang
#--------------------------------------//---------------------------------------
.c.o:
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o}
	@echo "  Criando .o de "$<
#--------------------------------------//---------------------------------------
all:		$(NAME)

$(NAME):	$(OBJ) libft.h
	@ar -rcs $(NAME) $(OBJ)
	@echo ""
	@echo "/ ************************************ \\"
	@echo "|            libft.a criada            |"
	@echo "\\ ************************************ /"
	@echo ""
#--------------------------------------//---------------------------------------
clean:
	@rm -rf $(OBJ)
	@echo ""
	@echo "/ ************************************ \\"
	@echo "|      Arquivos libft .o deletados     |"
	@echo "\\ ************************************ /"
	@echo ""

aclean:
	@rm -rf $(NAME)
	@echo ""
	@echo "/ ************************************ \\"
	@echo "|           libft.a deletada           |"
	@echo "\\ ************************************ /"
	@echo ""

fclean:		clean aclean

#--------------------------------------//---------------------------------------

re:			fclean all

git:
	git add .
	git status
	git commit -m "$m"
	git push

.PHONY:		all clean aclean fclean re git
