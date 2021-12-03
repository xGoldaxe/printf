SRCS	=  main_bonus.c printf_char_bonus.c printf_int_bonus.c printf_percentage_bonus.c printf_pointer_bonus.c \
printf_str_bonus.c prefix_router_bonus.c parse_options_bonus.c\
#./libft/ft_realloc_trunc.c \
#./libft/ft_strlcpy.c \
#./libft/ft_strlen.c \
#./libft/ft_isdigit.c\
#./libft/ft_atoi.c ./libft/ft_strdup.c\
#./libft/ft_itoa.c \
#./libft/ft_putstr_fd.c \
#./libft/ft_realloc_cat.c ./libft/ft_realloc_char.c ./libft/ft_itoa_uns.c \
#./libft/ft_itoa_base_uns.c ./libft/ft_arrinclude.c \

HEADERS	= ft_printf_bonus.h ./libft/libft.h

OBJS	= ${SRCS:.c=.o}

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
				@${LIBC} ${NAME} ${OBJS} ${HEADERS} ./libft/libft.a && printf "${CYAN}\t\t\t==>[Compiling binaries...]<=="
				@printf "${GREEN}\n\t\t✔️✔️✔️ ${NAME} compiled succcessfully ✔️✔️✔️${NC}\n"

all:		${NAME}
				@printf "${CYAN}\n\n\t{================>>>COMPILLING LIBFT<<<================}}\n\n\n${NC}"	
				@cd libft && make re
				@printf "${GREEN}✔️✔️✔️[ALL] -  Printf has been created!✔️✔️✔️${NC}"

bonus: 
				make all

clean:
				@${RM} ${OBJS} && printf "${RED}deleting binaries (${OBJS})...${NC}\n"
				@printf "${GREEN}✔️✔️✔️[clean] - binaries as been deleted!✔️✔️✔️\n${NC}"

fclean:		clean
					@${RM} ${NAME} && printf "${RED}deleting ${NAME}...\n${NC}"
					@printf "${GREEN}✔️✔️✔️[fclean] - folder is now clean!✔️✔️✔️${NC}"

re:				fclean all

PHONY:		all clean fclean re