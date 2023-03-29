#include "libft.h"

char *ft_strchr(const char *s, int c)
{
     int i;
     int n = ft_strlen(s);
     
     if (!s)
		return (NULL);

     i = 0;
     while(i <= n){
          if(s[i] == (char)c)
               return (char *)(s+i);
          i++;
     }
    return (NULL);  
}


int main(void) {
     // EXAMPLE-ZERO
     char str0[] = "HelloWorld";
     char str0_ft[] = "HelloWorld";

     char *p0 = strchr(str0, 'o');
     char *p0_ft = ft_strchr(str0_ft, 'o');

     printf("str0 on strchr: %ld\n", p0 - str0);
     printf("str0_ft on ft_strchr: %ld\n", p0_ft - str0_ft);

     // EXAMPLE-ONE: null character at end of string
     char str[] = "HelloWorld";
     char str_ft[] = "HelloWorld";

     char *p = strchr(str, '\0');
     char *p_ft = ft_strchr(str_ft, '\0');

     printf("str on strchr: %ld\n", p - str);
     printf("str_ft on ft_strchr: %ld\n", p_ft - str_ft);

     // EXAMPLE-TWO: null character at middle of string
     char str2[] = "Hello\0World";
     char str2_ft[] = "Hello\0World";

     char *p2 = strchr(str2, '\0');
     char *p2_ft = ft_strchr(str2_ft, '\0');

     printf("str2 on strchr: %ld\n", p2 - str2);
     printf("str2_ft on ft_strchr: %ld\n", p2_ft - str2_ft);

     return 0;
}


/*
DESCRIPTION
	The strchr() function locates the first occurrence of c (converted to a
     char) in the string pointed to by s.  The terminating null character is
     considered to be part of the string; therefore if c is `\0', the func-
     tions locate the terminating `\0'.

     The functions strchr() and strrchr() return a pointer to the located
     character, or NULL if the character does not appear in the string.
*/

/*
NOTE
DIFF"memchr vs strchr"
     memchr and strchr are two functions that are used to search for a character in a string.

     STRCHR function searches for the first occurrence of a specified character in a null-terminated string. 
     It returns a pointer to the location of the character in the string, 
     or a null pointer if the character is not found. 
     
     EXAMPLE:
     char *str = "Hello, world!";
     char *p = strchr(str, 'o');

     In this example, strchr is used to search for the first occurrence of the character 'o' in the string "Hello, world!". 
     It returns a pointer to the location of the first 'o' character in the string.

     MEMCHR function, on the other hand, searches for the first occurrence of a specified byte in a block of memory. 
     It takes an additional argument that specifies the maximum number of bytes to search. 
     
     EXAMPLE:
     char block[] = { 0x01, 0x02, 0x03, 0x04 };
     char *p = memchr(block, 0x03, sizeof(block));

     In this example, memchr is used to search for the first occurrence of the byte 0x03 in the memory block { 0x01, 0x02, 0x03, 0x04 }. 
     It returns a pointer to the location of the byte in the block.

     In summary, the main difference between memchr and strchr is that strchr is used to search for a character in a null-terminated string, 
     while memchr is used to search for a byte in a block of memory. 
     Additionally, memchr takes an extra argument that specifies the maximum number of bytes to search.

EXAMPLE-TWO"search '\0'"
     EXAMPLE-CODE:
     int main(void) {
          char str[] = "Hello\0World";
          char *p = strchr(str, '\0');
          printf("Position of null characters using strchr: %ld\n", p - str);

          char str_m[] = "Hello\0World";
          char *p_m = memchr(str_m, '\0', sizeof(str_m));
          printf("Position of null characters using ft_memchr: %ld\n", p_m - str_m);
          return 0;
     }
     EXAMPLE-OUTPUT:
          Position of null character using strchr: 5
          Position of null character using ft_memchr: -140732709673660
     
     This example demonstrates that while strchr is designed to work with null-terminated strings 
     and can correctly handle null characters in the string, 
     memchr may not work as expected when searching for null characters in a string.


*/