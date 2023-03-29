#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
     int i;
     int n = ft_strlen(s);
     
     if (!s)
		return (NULL);

     i = n;
     while(i >= 0){
          if(s[i] == (char)c)
               return (char *)(s+i);
          i--;
     }
    return (NULL);  
}


int main(void) {
     // EXAMPLE-ZERO
     char str0[] = "HelloWorld";
     char str0_ft[] = "HelloWorld";

     char *p0 = strrchr(str0, 'o');
     char *p0_ft = ft_strrchr(str0_ft, 'o');

     printf("str0 on strrchr: %ld\n", p0 - str0);
     printf("str0_ft on ft_strrchr: %ld\n", p0_ft - str0_ft);

     // EXAMPLE-ONE: null character at end of string
     char str[] = "HelloWorld";
     char str_ft[] = "HelloWorld";

     char *p = strrchr(str, '\0');
     char *p_ft = ft_strrchr(str_ft, '\0');

     printf("str on strrchr: %ld\n", p - str);
     printf("str_ft on ft_strrchr: %ld\n", p_ft - str_ft);

     // EXAMPLE-TWO: null character at middle of string
     char str2[] = "Hello\0World";
     char str2_ft[] = "Hello\0World";

     char *p2 = strrchr(str2, '\0');
     char *p2_ft = ft_strrchr(str2_ft, '\0');

     printf("str2 on strrchr: %ld\n", p2 - str2);
     printf("str2_ft on ft_strrchr: %ld\n", p2_ft - str2_ft);

     return 0;
}



/*
DESCRIPTION
	The strrchr() function is identical to strrchr(), except it locates the
     last occurrence of c.

     The functions strchr() and strrchr() return a pointer to the located character, 
     or NULL if the character does not appear in the string.
*/
