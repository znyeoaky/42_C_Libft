#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    const unsigned char *str = s;
    unsigned char ch = c;
    size_t i = 0;

    while(i < n){
        if(*(str + i) == ch)
            return (void*)(str + i);
        i++;
    }
    return (NULL);    
}

int main() {
    char str[] = "This is a test string";
    char ch = 'i';
    char *result;

    result = ft_memchr(str, ch, strlen(str));

    if (result == NULL) {
        printf("'%c' not found in string\n", ch);
    } else {
        printf("'%c' found at position %ld\n", ch, result - str);
    }

    return 0;
}

/*
DESCRIPTION
    The memchr() function locates the first occurrence of c (converted to an
    unsigned char) in string s.
    The memchr() function returns a pointer to the byte located, or NULL if
    no such byte exists within n bytes.
*/
/*
NOTE
WHY"if(((unsigned char*)s)[i] == (unsigned char)c)"
    the expression is a common technique in C/C++ programming for comparing individual characters in a string or array of bytes, 
    and it helps to ensure that the comparison is done in a safe and consistent way.
*/