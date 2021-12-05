SRCS	=  main.c printf_char.c printf_hexa.c printf_int.c printf_percentage.c printf_pointer.c \
printf_str.c printf_uns_int.c \
./libft2/ft_putstr_fd.c ./libft2/ft_putnbr_base_uns.c ./libft2/ft_putnbr_fd.c ./libft2/ft_putnbr_uns_fd.c ./libft2/ft_strlen.c  ./libft2/ft_putchar_fd.c\

SRCSBONUS	=  main_bonus.c printf_char_bonus.c printf_int_bonus.c printf_percentage_bonus.c printf_pointer_bonus.c \
printf_str_bonus.c prefix_router_bonus.c parse_options_bonus.c\

HEADERS	= ft_printf.h ./libft.h

BONUSHEADERS = ./bonus/ft_printf.h

OBJS	= ${SRCS:.c=.o}

BONUSOBJS	= ${SRCS:.c=.o}

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
				@${LIBC} ${NAME} ${OBJS} ./libft/libft.a && printf "${CYAN}\t\t\t==>[Compiling binaries...]<=="
				@printf "${GREEN}\n\t\t✔️✔️✔️ ${NAME} compiled succcessfully ✔️✔️✔️${NC}\n"

all:		${NAME}
				cd libft && make re
				@make bonus
				@printf "${GREEN}✔️✔️✔️[ALL] -  Printf has been created!✔️✔️✔️${NC}"

bonus:	${BONUSOBJS}
				@${LIBC} ${NAME} ${BONUSOBJS}
				@printf "${GREEN}\n\t\t✔️✔️✔️[BONUS] - Bonus has been created!✔️✔️✔️${NC}"

clean:
				@${RM} ${OBJS} && printf "${RED}deleting binaries (${OBJS})...${NC}\n"
				@printf "${GREEN}✔️✔️✔️[clean] - binaries as been deleted!✔️✔️✔️\n${NC}"

fclean:		clean
					@${RM} ${NAME} && printf "${RED}deleting ${NAME}...\n${NC}"
					@printf "${GREEN}✔️✔️✔️[fclean] - folder is now clean!✔️✔️✔️${NC}"

re:				fclean all

PHONY:		all clean fclean re