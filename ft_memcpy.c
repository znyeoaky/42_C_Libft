#include <stddef.h>
#include <stdio.h>

void *ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char *pdst;
	char const *psrc;
	size_t i;

	pdst = (char *)dst;
	psrc = (const char *)src;

	if (pdst == NULL && psrc == NULL)
		return (NULL);

	i = 0;
	while (i < n)
	{
		pdst[i] = psrc[i];
		i++;
	}
	return (pdst);
}

#include <string.h>

int main() {
    char src[] = "Hello, world!"; // Create a source string
    char dest[20]; // Create a destination string

    // Copy the source string to the destination string
    ft_memcpy(dest, src, 10);

    // Print the contents of the destination string
    printf("The dest is: %s\n", dest);

    return 0;
}

/*
	memcpy – copy memory area
	The memcpy() function copies n bytes from memory area src to memory area dst.  If
     dst and src overlap, behavior is undefined.  Applications in which dst and src
     might overlap should use memmove(3) instead.

*/

/*
NOTE
WHY"void* have return"
	The function is declared to return a void* pointer, which is a generic pointer type that can be used to point to any data type.
DIFF"restrict vs const"
	restrict and const are both type qualifiers in C and C++, but they have different meanings and purposes.

	The const qualifier is used to indicate that a variable's value should not be modified after it has been initialized. For example, if a function takes a pointer to a const variable as an argument, it promises not to modify the value of the variable through that pointer. This can help improve code safety and readability by making it clear which variables are intended to be read-only.

	The restrict qualifier, on the other hand, is used to indicate that a pointer is the only way to access a particular region of memory.

	In short, const is used to make variables read-only, while restrict is used to optimize access to memory by specifying that a pointer is the only way to access it. 
*/