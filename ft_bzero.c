#include <stddef.h>

void ft_bzero(void *s, size_t n)
{
	char *p = s;
	if(n > 0) //?
	{
		while (n--) 
				*p++ = 0;
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Example 1: Clearing a string using ft_bzero()
    char str[10] = "hello";
    printf("Before ft_bzero(): %s\n", str);
    ft_bzero(str, sizeof(str));
    printf("After ft_bzero(): %s\n", str);

/*
    // Example 2: Clearing a string using memset()
		char strstr[10] = "hello";
		memset(strstr, 0, strlen(strstr)); // Set all bytes of str to 0
		printf("Using memset: %s\n", strstr); // Output: an empty string
*/

    return 0;
}


/*
	bzero – write zeroes to a byte string
	The bzero() function erases the data in the n bytes of the memory starting at the location pointed to by s, by writing zeros (bytes containing '\0') to that area.	
	If n is zero, bzero() does nothing.
*/

/*
NOTE
	bzero() has been deprecated in favor of the safer memset() function in modern C standards. The memset() function can be used to set a block of memory to any arbitrary value, not just zero. 
		memset(str, 0, sizeof(str)); // Set all bytes of str to 0

*/