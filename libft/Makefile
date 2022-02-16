# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/20 09:50:28 by mmoreira          #+#    #+#              #
#    Updated: 2021/09/27 01:00:43 by mmoreira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR	=	./func_alloc \
			./func_char \
			./func_fd \
			./func_gnl \
			./func_lst \
			./func_mem \
			./func_outros \
			./func_printf \
			./func_str \

SRC		=	ft_addchar.c ft_calloc.c ft_itoa_base.c ft_itoa.c ft_split.c \
			ft_strdup.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_substr.c \
			ft_utoa_base.c ft_utoa.c \
			\
			ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			ft_isspace.c ft_tolower.c ft_toupper.c \
			\
			ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
			\
			get_next_line_utils.c get_next_line.c \
			\
			ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
			ft_lstfirst.c ft_lstiter.c ft_lstlast.c ft_lstloop_start.c \
			ft_lstloop_stop.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
			\
			ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
			ft_memset.c \
			\
			ft_check_base.c ft_free_split.c ft_numlen.c ft_splitlen.c \
			\
			check_flags.c init_struct.c print_type.c ft_printf.c \
			print_address.c print_char.c print_hex.c print_int.c \
			print_string.c print_uint.c while_print.c \
			\
			ft_atod.c ft_atoi.c ft_bzero.c ft_strchr.c ft_strcmp.c \
			ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
			ft_strrchr.c

OBJ_DIR	=	./builds
OBJ		=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))


INCD	=	libft.h
#--------------------------------------//---------------------------------------
vpath %.c $(SRC_DIR)

NAME	=	libft.a

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -rf

CC		=	clang
#--------------------------------------//---------------------------------------
all:		$(NAME)

$(NAME):	$(OBJ) $(INCD)
	ar -rcs $(NAME) $(OBJ)
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|            libft.a criada            |"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

$(OBJ_DIR)/%.o:	%.c $(INCD)
	mkdir -p $(OBJ_DIR)
	$(CC) -c -o $@ $(CFLAGS) -I ./ $<
#--------------------------------------//---------------------------------------
clean:
	$(RM) $(OBJ_DIR)
	@echo "\033[1;31m"
	@echo "/ ************************************ \\"
	@echo "|      Arquivos libft .o deletados     |"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

aclean:
	$(RM) $(NAME)
	@echo "\033[1;31m"
	@echo "/ ************************************ \\"
	@echo "|           libft.a deletada           |"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

fclean:		clean aclean
#--------------------------------------//---------------------------------------

re:			fclean all

git:
	@git add .
	@git status
	@git commit -m "$m"

.PHONY:		all clean aclean fclean re git
