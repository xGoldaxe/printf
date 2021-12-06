SRCS	=  ft_isalpha.c ft_memchr.c  ft_memmove.c ft_strlcpy.c \
ft_bzero.c   ft_isascii.c ft_isprint.c ft_memcmp.c  ft_memset.c  ft_strlen.c \
ft_isalnum.c ft_isdigit.c ft_memcpy.c  ft_strlcat.c \
ft_tolower.c ft_toupper.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c \
ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c \
ft_putnbr_base.c ft_putnbr_base_uns.c \
ft_putnbr_uns_fd.c \

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


%.o:		%.c	
				${CC} ${CFLAGS} -I. -o $@ -c $? 

${NAME}:	${OBJS}
				${LIBC} ${NAME} ${OBJS}
				@echo 'Libft compiled succcessfully'

bonus:	${BONUSOBJS}
				${LIBC} ${NAME} ${BONUSOBJS}
				@echo 'Bonus well added'

all:		${NAME}
				make bonus
				@echo '✔️✔️✔️[ALL] - libft with bonus has been created!✔️✔️✔️'

clean:
				${RM} ${OBJS} ${BONUSOBJS}
				@echo '✔️✔️✔️[clean] - folder is now clean!✔️✔️✔️'

fclean:		clean
					${RM} ${NAME}
					
					@echo '✔️✔️✔️[fclean] - folder is now clean!✔️✔️✔️'

re:				fclean all

PHONY:		all clean fclean re