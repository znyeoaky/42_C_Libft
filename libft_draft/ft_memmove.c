#include <stddef.h>
#include <stdio.h>

void *ft_memmove(void *dst, const void *src, size_t len)
{
	char *pdst = dst;
	char const *psrc = src;

	if (pdst == NULL && psrc == NULL)
		return (NULL);

	if (pdst < psrc) {
		// Destination comes before source in memory, can copy forwards
		while (len--) 
				*pdst++ = *psrc++;
	} else {
		// Destination comes after source in memory, must copy backwards
		pdst += len - 1;
		psrc += len - 1;
		while (len--)
			*pdst-- = *psrc--;
	}

	return (dst);
}

#include <string.h>

int main()
{
	/* EXAMPLE-ONE: dst < src
		char src[] = "abcdefg";//when src defined before dst
		char dst[] = "9876543";
		printf("#EXAMPLE-ONE: dst < src#\nSRC: %p\nDST: %p\nDST-SRC: %ld\n\n", src, dst, dst - src);

		printf("Before:\nsrc: %s\ndst: %s\n", src, dst);
		ft_memmove(dst, src, 2);
		printf("After:\ndst: %s\n\n", dst);
	*/

	/* EXAMPLE-TWO: dst > src
		char dst2[] = "9876543";//when dst defined before src
		char src2[] = "abcdefg";
		printf("#EXAMPLE-TWO: dst > src#\nSRC: %p\nDST: %p\nDST-SRC: %ld\n\n", src2, dst2, dst2 - src2);
	*/

	// EXAMPLE-THREE: dst > src
	char src3[50] = "I am going from CQ to AU";
	char src4[50] = "I am going from CQ to AU";

	//Use of memmove
	memmove( src3 + 5, src3, 19 );
	printf( "memmove Result:\n%s\n\n", src3 );
	
	//Use of ft_memmove
	ft_memmove( src4 + 5, src4, 19 );
	printf( "ft_memmove Result:\n%s\n\n", src4 );
	
	return 0;
}

/*
	The memmove() function copies len bytes from string src to string dst.  
	memmove() is similar to memcpy() as it also copies data from a source to destination. 
	memcpy() leads to problems when source and destination addresses overlap as memcpy() simply copies data one by one from one location to another. 

*/

/*
NOTE
ABT"Which memory block has a higher starting address, src or dst?"
	The starting address of src and dst depends on the order in which they are defined in main(). 
	If src is defined before dst, then the starting address of src will be greater than the starting address of dst. 
	CHECK: EXAMPLE-ONE & EXAMPLE-TWO
TEST"What kind of issues can occur if we don't consider the case where pdst >= psrc 
		and allow the memory blocks to overlap?"
	CHECK: EXAMPLE-THREE(Comment The 'else' part of 'ft_memmove', then compare the ouput)
*/
