#include <stddef.h>
#include <stdio.h>

void *ft_memmove(void *dst, const void *src, size_t len)
{
	char *pdst = dst;
	char const *psrc = src;

	if (pdst == NULL && psrc == NULL)
		return (NULL);

	printf("pdst: %p & psrc: %p = %ld\n\n", pdst, psrc, pdst - psrc);
	if (pdst < psrc) {
			// Destination comes before source in memory, can copy forwards
			while (len--) {
					*pdst++ = *psrc++;
			}
	} else {
			// Destination comes after source in memory, must copy backwards
			pdst += len - 1;
			psrc += len - 1;
			while (len--) {
					*pdst-- = *psrc--;
			}
	}

	return (dst);
}

#include <string.h>

int main()
{
	char str1[50] = "I am going from CQ to AU";
	char str2[50] = "I am going from CQ to AU";
	
	//Use of memmove
	printf( "\nDestination: %s\n", str1 + 11 );
	memmove( str1 + 11, str1, 19 );
	printf( "memmove Result: %s\n", str1 );
	
	//Use of ft_memmove
	printf( "\nDestination: %s\n", str2 + 11 );
	ft_memmove( str2 + 11, str2, 19 );
	printf( "ft_memmove Result: %s\n", str2 );
	
	return 0;
}

/*
	The memmove() function copies len bytes from string src to string dst.  
	memmove() is similar to memcpy() as it also copies data from a source to destination. memcpy() leads to problems when source and destination addresses overlap as memcpy() simply copies data one by one from one location to another. 

*/

/*
NOTE

*/
