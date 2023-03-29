#include "libft.h"

char *	ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	if(!*needle)
		return ((char*)haystack);
	
	i = 0;
	while(haystack[i]){
		j = 0;
		while(needle[j] == haystack[i + j] && haystack[i + j] != '\0'){
			j++;
		}
		if(needle[j] == '\0')
			return ((char *)(haystack + i));
		i++;
	}

	return (NULL);
}

// int main() {
// 	const char *haystack = "lask askdfal eak asd asdfeae aoo";
// 	const char *needle = "aoo";

// 	const char *haystack1 = "lask askdfal eak asd asdfeae aoo";
// 	const char *needle1 = "aoo";

// 	char *result = strnstr(haystack, needle, strlen(haystack));
// 	printf("strnstr:	'%s' at %ld\n", result, result - haystack);

// 	char *result1 = ft_strnstr(haystack1, needle1, strlen(haystack1));
// 	printf("ft_strnstr:	'%s' at %ld\n", result1, result1 - haystack1);

// 	return 0;
// }


/*
	#include <string.h>
DESCRIPTION
	The strstr() function locates the first occurrence of the null-terminated string needle in the
	null-terminated string haystack.

	The strnstr() function locates the first occurrence of the null-terminated string needle in the
	string haystack, where not more than len characters are searched.  Characters that appear after a
	`\0' character are not searched.  Since the strnstr() function is a FreeBSD specific API, it
	should only be used when portability is not a concern.

RETURN VALUES
	If needle is an empty string, haystack is returned; 
	if needle occurs nowhere in haystack, NULL is returned; 
	otherwise a pointer to the first character of the first occurrence of needle is	returned.
*/

/*
NOTE
WHY"are they same? 
		#while(needle[j] == haystack[i + j] && haystack[i + j] != '\0') 
		and #while(needle[j] == haystack[i + j] && needle[j] != '\0')
	"
	TEST:


*/


int main() {
    const char *needle = "ab";
    const char *haystack = "abababab";
    int i = 0, j = 0;

    // First condition: checks both the end of the haystack and the needle
    while(needle[j] == haystack[i + j] && haystack[i + j] != '\0') {
        j++;
        if(needle[j] == '\0') {
            printf("1Found the substring at index %d\n", i);
            break;
        }
    }

    // Second condition: checks only the end of the needle
    while(needle[j] == haystack[i + j] && needle[j] != '\0') {
        j++;
        if(needle[j] == '\0') {
            printf("2Found the substring at index %d\n", i);
            break;
        }
    }

    return 0;
}

