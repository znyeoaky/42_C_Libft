#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    const char* str1 = s1;
    const char* str2 = s2;
    int res = 1;

    while(n){
        if(*(str1 + n) != *(str2 + n))
            res = 0;  
        n--;
    }
    
    return (res);
}

int main() {
    char str1[] = "Hello World!";
    char str2[] = "Hello World!";
    char str3[] = "Goodbye World!";

    // Compare str1 and str2
    int result1 = ft_memcmp(str1, str2, strlen(str1));
    if (result1 != 0) {
        printf("str1 and str2 are equal.\n");
    } else {
        printf("str1 and str2 are not equal.\n");
    }

    // Compare str1 and str3
    int result2 = ft_memcmp(str1, str3, strlen(str1));
    if (result2 != 0) {
        printf("str1 and str3 are equal.\n");
    } else {
        printf("str1 and str3 are not equal.\n");
    }

    return 0;
}



/*
DESCRIPTION
    The memcmp() function compares byte string s1 against byte string s2.  
    Both strings are assumed to be n bytes long.
*/

/*
NOTE
WHY"if(*(s1 + n) != *(s2 + n)) is wrong"
    Dereferencing a void* pointer directly is not allowed because the compiler doesn't know the size or type of the data being pointed to. 
    To access the data, the void* pointer must first be cast to a pointer of the appropriate type, and then dereferenced.
    
    if you want to compare the values of the memory blocks pointed to by s1 and s2 in a safe way, 
    you can cast the pointers to const char* (or another appropriate type) before dereferencing them, 
    LIKE THIS:
        if (*((const char*)s1 + n) != *((const char*)s2 + n))
    Here, we cast s1 and s2 to const char*, which allows us to access the individual bytes in the memory blocks.  



*/