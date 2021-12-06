SRCS	=  ft_isalpha.c ft_memchr.c  ft_memmove.c ft_strlcpy.c \
ft_bzero.c   ft_isascii.c ft_isprint.c ft_memcmp.c  ft_memset.c  ft_strlen.c \
ft_isalnum.c ft_isdigit.c ft_memcpy.c  ft_strlcat.c \
ft_tolower.c ft_toupper.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c \
ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c \

BONUSSRCS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
ft_lstclear.c ft_lstiter.c ft_lstmap.c

HEADERS	= libft.h 

OBJS	= ${SRCS:.c=.o}

BONUSOBJS	= ${BONUSSRCS:.c=.o}

NAME	= libft.a

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
				@${LIBC} ${NAME} ${OBJS} && printf "${CYAN}\t\t\t==>[Compiling binaries...]<=="
				@printf "${GREEN}\n\t\t✔️✔️✔️ ${NAME} compiled succcessfully ✔️✔️✔️${NC}\n"

bonus:	${BONUSOBJS}
				@${LIBC} ${NAME} ${BONUSOBJS}
				@printf "${GREEN}\n\t\t✔️✔️✔️[BONUS] - Bonus has been created!✔️✔️✔️${NC}"

all:		${NAME}
				@make bonus
				@printf "${GREEN}\n\t\t✔️✔️✔️[ALL] - ${NAME} has been created!✔️✔️✔️${NC}"

clean:
				@${RM} ${OBJS} ${BONUSOBJS} && printf "${RED}deleting binaries (${OBJS}, ${BONUSOBJS})...${NC}\n"
				@printf "${GREEN}✔️✔️✔️[clean] - binaries as been deleted!✔️✔️✔️\n${NC}"

fclean:		clean
					@${RM} ${NAME} && printf "${RED}deleting ${NAME}...\n${NC}"
					@printf "${GREEN}✔️✔️✔️[fclean] - folder is now clean!✔️✔️✔️\n${NC}"

re:				fclean all

PHONY:		all clean fclean re