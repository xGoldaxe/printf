SRCS	=  main.c printf_char.c printf_hexa.c printf_int.c printf_percentage.c printf_pointer.c \
printf_str.c printf_uns_int.c \
./libft/ft_putstr_fd.c ./libft/ft_putnbr_base_uns.c ./libft/ft_putnbr_fd.c ./libft/ft_strlen.c  ./libft/ft_putchar_fd.c\
./libft/ft_putnbr_uns_fd.c


SRCSBONUS	=  ./bonus/main_bonus.c ./bonus/printf_char_bonus.c ./bonus/printf_int_bonus.c ./bonus/printf_percentage_bonus.c ./bonus/printf_pointer_bonus.c \
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

HEADERS	= ft_printf.h ./libft/libft.h

BONUSHEADERS = ./bonus/ft_printf_bonus.h ./bonus/libft/libft.h

OBJS	= ${SRCS:.c=.o}

BONUSOBJS	= ${SRCSBONUS:.c=.o}

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

${NAME}:	${OBJS}
				cd bonus/libft && make re
				@${LIBC} ${NAME} ${OBJS} ./libft/libft.a && printf "${CYAN}\t\t\t==>[Compiling binaries...]<=="
				@printf "${GREEN}\n\t\t✔️✔️✔️ ${NAME} compiled succcessfully ✔️✔️✔️${NC}\n"

all:		bonus
				@printf "${GREEN}✔️✔️✔️[ALL] -  Printf has been created!✔️✔️✔️${NC}"

bonus:	${BONUSOBJS}
				rm -f ${NAME}
				cd bonus/libft && make re
				@${LIBC} ${NAME} ${BONUSOBJS} ./bonus/libft/libft.a
				@printf "${GREEN}\n\t\t✔️✔️✔️[BONUS] - Bonus has been created!✔️✔️✔️${NC}"

clean:
				@${RM} ${OBJS} && printf "${RED}deleting binaries (${OBJS})...${NC}\n"
				@printf "${GREEN}✔️✔️✔️[clean] - binaries as been deleted!✔️✔️✔️\n${NC}"

fclean:		clean
					rm -f ./bonus/*.o
					cd bonus/libft && make fclean
					cd libft && make fclean
					@${RM} ${NAME} && printf "${RED}deleting ${NAME}...\n${NC}"
					@printf "${GREEN}✔️✔️✔️[fclean] - folder is now clean!✔️✔️✔️${NC}"

re:				fclean all

PHONY:		all clean fclean re