CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM				= rm -f

SRCS = ft_strlen.c \
			ft_bzero.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
			ft_strchr.c ft_strrchr.c
# SRCS = ft_strlen.c ft_substr.c ft_atoi.c
# SRCS =	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c  ft_isalpha.c \
					ft_itoa.c   ft_putendl_fd.c   ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c    ft_isascii.c ft_memccpy.c \
					 ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c     \
					ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c
OBJS = $(SRCS:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# $(EXEC): myprogram.c $(NAME)
# 	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS) -I. -L. -lft

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all