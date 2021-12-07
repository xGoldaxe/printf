SRCS	=  ./srcs/main_bonus.c ./srcs/printf_char_bonus.c ./srcs/printf_int_bonus.c ./srcs/printf_percentage_bonus.c ./srcs/printf_pointer_bonus.c \
./srcs/printf_str_bonus.c ./srcs/prefix_router_bonus.c ./srcs/parse_options_bonus.c ./srcs/ft_realloc_l_cat.c ./srcs/ft_realloc_merge.c ./srcs/ft_strldup.c\
./srcs/ft_strfill.c ./srcs/add_ternary.c ./srcs/free_all.c \
./srcs/libft/ft_strlcpy.c \
./srcs/libft/ft_strlen.c \
./srcs/libft/ft_isdigit.c\
./srcs/libft/ft_atoi.c \
./srcs/libft/ft_strdup.c\
./srcs/libft/ft_itoa.c \
./srcs/libft/ft_putstr_fd.c \
./srcs/ft_realloc_cat.c \
./srcs/ft_realloc_char.c \
./srcs/ft_itoa_uns.c \
./srcs/ft_itoa_base_uns.c \
./srcs/ft_arrinclude.c \

HEADERS = ./srcs/ft_printf_bonus.h ./srcs/libft/libft.h

OBJS	= ${SRCS:.c=.o}

LIBFT = cd srcs/libft && make all

NAME	= libftprintf.a

CC		= gcc

LIBC	= ar -rc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

#=====color=======
RED=\033[0;31m
NC=\033[0m # No Color
GREEN=\033[0;32m
LIGHTCYAN=\033[0;36m
CYAN=\033[1;36m
#=================

%.o:		%.c	
				@${CC} ${CFLAGS} -I. -o $@ -c $? && printf "${LIGHTCYAN}Creating $@${NC}\n"

${NAME}:	bonus

all:		${NAME}

bonus:	${OBJS}
				${LIBFT}
				${LIBC} ${NAME} ${OBJS} ./srcs/libft/libft.a

clean:
				${RM} ${OBJS}

fclean:		clean
					rm -f ./srcs/*.o
					cd srcs/libft && make fclean

re:				fclean all

PHONY:		all clean fclean re bonus