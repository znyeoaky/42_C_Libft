#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    const char* str1 = s1;
    const char* str2 = s2;

    while(n){
        if(*str1 != *str2)
        {
            // printf("%c && %c\n", *str1, *str2);
            return (*str1 - *str2);
        }
        str1++;
        str2++;
        n--;
    }
    
    return (0);
}

int main() {

    // TEST-ONE: same content but different sizes
    /*
        The first block contains the string "123" followed by 16 null bytes, 
        while the second block contains the same string followed by 18 null bytes.
    */
    char block1[] = "123\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    char block2[] = "123\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";

    // Compare the two blocks using ft_memcmp and memcmp
    int result1 = ft_memcmp(block1, block2, sizeof(block1));
    int result2 = memcmp(block1, block2, sizeof(block1));

    // Print the results
    printf("\nft_memcmp result: %d\n", result1);
    printf("memcmp result: %d\n\n", result2);

    // TEST-TWO:
    char str2[] = "Hello World!";
    char str3[] = "Hello MY World!";

    int result11 = ft_memcmp(str2, str3, strlen(str2));
    int result22 = memcmp(str2, str3, strlen(str2));

    printf("ft_memcmp result: %d\n", result11);
    printf("memcmp result: %d\n\n", result22);

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

DIFF"memcmp vs strcmp"
    memcmp and strcmp are both string comparison functions in C, but they work in different ways.

    STRCMP compares two null-terminated strings character by character, starting from the first character, 
    until it finds a difference or reaches the end of one of the strings. 
    It returns a value that is:
        Less than 0 if the first string is less than the second string (according to ASCII or Unicode ordering).
        Greater than 0 if the first string is greater than the second string.
        Equal to 0 if the two strings are identical.
        (For example, if we compare "apple" and "banana" using strcmp, the function would return a negative value, 
        because "apple" comes before "banana" in alphabetical order.)

    MEMCMP, on the other hand, compares two memory blocks of a specified size byte by byte, starting from the first byte, 
    until it finds a difference or reaches the end of one of the blocks. 
    It returns a value that is:
        Less than 0 if the first block is less than the second block (according to a binary comparison of the bytes).
        Greater than 0 if the first block is greater than the second block.
        Equal to 0 if the two blocks are identical.

    memcmp doesn't require null-terminated strings and can compare any arbitrary blocks of memory. 
    For example, we could compare the first 5 bytes of "apple" and "banana" using memcmp, 
    and the function would return a negative value because "a" has a lower ASCII value than "b".

    In summary, strcmp is used for comparing strings, while memcmp is used for comparing arbitrary memory blocks.

*/