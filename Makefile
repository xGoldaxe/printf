SRCS	=  ./bonus/main_bonus.c ./bonus/printf_char_bonus.c ./bonus/printf_int_bonus.c ./bonus/printf_percentage_bonus.c ./bonus/printf_pointer_bonus.c \
./bonus/printf_str_bonus.c ./bonus/prefix_router_bonus.c ./bonus/parse_options_bonus.c ./bonus/ft_realloc_l_cat.c ./bonus/ft_realloc_merge.c ./bonus/ft_strldup.c\
./bonus/ft_strfill.c ./bonus/add_ternary.c ./bonus/free_all.c \
./bonus/libft/ft_strlcpy.c \
./bonus/libft/ft_strlen.c \
./bonus/libft/ft_isdigit.c\
./bonus/libft/ft_atoi.c \
./bonus/libft/ft_strdup.c\
./bonus/libft/ft_itoa.c \
./bonus/libft/ft_putstr_fd.c \
./bonus/ft_realloc_cat.c \
./bonus/ft_realloc_char.c \
./bonus/ft_itoa_uns.c \
./bonus/ft_itoa_base_uns.c \
./bonus/ft_arrinclude.c \

HEADERS = ./bonus/ft_printf_bonus.h ./bonus/libft/libft.h

OBJS	= ${SRCS:.c=.o}

LIBFT = cd bonus/libft && make all

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
				${LIBC} ${NAME} ${OBJS} ./bonus/libft/libft.a

clean:
				${RM} ${OBJS}

fclean:		clean
					rm -f ./bonus/*.o
					cd bonus/libft && make fclean

re:				fclean all

PHONY:		all clean fclean re bonus