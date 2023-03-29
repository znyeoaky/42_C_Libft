#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    // printf("'%c' vs '%c'\n", *s1, *s2);
    if(!*s1 && !*s2)
        return (0);


    i = 0;
    while(i < n){
        if(s1[i] != s2[i])
            return (int)(s1[i] - s2[i]);
        i++;
    }
    
    return (0);
}

int main() {
    char str1[] = "Hello world";
    char str2[] = "Hello there";
    char str3[] = "Hello";
    int size = 6;

    // using ft_strncmp()
    if (ft_strncmp(str1, str2, size) == 0) {
        printf("The first %d characters are EQUAL\n", size);
    } else {
        printf("%d\n", ft_strncmp(str1, str2, size));
        printf("The first %d characters are NOT EQUAL\n", size);
    }

    if (ft_strncmp(str1, str2, size) == 0) {
        printf("The first %d characters are EQUAL\n", size);
    } else {
        printf("%d\n", ft_strncmp(str1, str2, size));
        printf("The first %d characters are NOT EQUAL\n", size);
    }

    // test 3: compare entire string of str2 and str3
    int result3 = ft_strncmp(str2, str3, strlen(str2));
    if (result3 == 0) {
        printf("RESULT3: str2 and str3 are EQUAL\n");
    } else {
        printf("RESULT3: str2 and str3 are NOT EQUAL\n");
    }

    // using strncmp()
    if (strncmp(str1, str2, size) == 0) {
        printf("BUILDIN:The first %d characters are EQUAL\n", size);
    } else {
        printf("BUILDIN: The first %d characters are NOT EQUAL\n", size);
    }

    /*
        // using strcmp()
        if (strcmp(str1, str2) == 0) {
            printf("The strings are EQUAL\n");
        } else {
            printf("The strings are NOT EQUAL\n");
        }
    */

    return 0;
}


/*
    #include <string.h>
DESCRIPTION
    The strcmp() and strncmp() functions lexicographically compare the null-terminated strings s1 and
    s2.
    The strncmp() function compares not more than n characters.  Because strncmp() is designed for
    comparing strings rather than binary data, characters that appear after a `\0' character are not
    compared.

RETURN VALUES
    The strcmp() and strncmp() functions return an integer greater than, equal to, or less than 0,
    according as the string s1 is greater than, equal to, or less than the string s2.  
    The comparison is done using unsigned characters, so that `\200' is greater than `\0'.
*/
