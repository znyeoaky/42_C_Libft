#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h> //write
#include <stdio.h> //printf
#include <stdlib.h> //malloc
#include <stddef.h> //size_t
#include <string.h> //sizeof

size_t			ft_strlen(const char *s);

char    *ft_substr(char const *s, unsigned int start, size_t len);

int	ft_atoi(char *str);

#endif
