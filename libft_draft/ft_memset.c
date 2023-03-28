#include "libft.h"

// #include <stddef.h>

void *ft_memset(void *str, int c, size_t n)
{
    unsigned char *p = str;
    unsigned char value = (unsigned char)c;
    size_t i;

    i = 0;
    while(i < n)
    {
        p[i] = value;
        i++;
    }

    return (str);
}
/*
OPTIMIZATION：
void *memset(void *s, int c, size_t n) {
    unsigned char *p = s;
    while (n--) {
        *p++ = (unsigned char)c;
    }
    return s;
}
*/
// #include <stdio.h>
// #include <string.h>

int main() {
    /*test00*/
    char str[50] = "Hello, world!";
    printf("Before memset: %s\n", str);

    ft_memset(str + 7, '*', 5); 
    // set 5 characters starting from index 7 to '*'
    printf("After memset: %s\n", str);

    /*test01*/
    int dest[4] = {0};
    int value = 0x12345678;
    for (int i = 0; i < 4; i++) {
        printf("%08X ", dest[i]);
    }
    printf("\n");
    memset(dest, value, sizeof(dest));
    
    for (int i = 0; i < 4; i++) {
        printf("%08X ", dest[i]);
    }
    printf("\n");
    return (0);
}

/*
DESCRIPTION
    The C library function void *memset(void *str, int c, size_t n) copies the character c (an unsigned char) to the first n characters of the string pointed to, by the argument str.
    The memset is a C library function that allows you to set a block of memory to a particular value. The name "memset" stands for "memory set".

Parameters
    #str − This is a pointer to the block of memory to fill.
    #c − This is the value to be set. The value is passed as an int, but the function fills the block of memory using the unsigned char conversion of this value.
    #n − This is the number of bytes to be set to the value.

Return Value
    This function returns a pointer to the memory area str.
*/

/*
NOTE:
WHY "unsigned char *p = str;"
    Using pointer arithmetic with "*p++ = value;" can be more efficient than array indexing with str[i] in C. It also allows us to modify the pointer value without changing the original str pointer. However, for memset, either method should result in similar performance.

WHY"2nd parameter is int"
    The second parameter of memset is usually a char value, but this implementation uses an int to allow it to work with values outside the range of a char. Passing an int sets every byte in the memory region to the value of the least significant byte of the int.

ABT"test01"
    0x12345678 is a hexadecimal integer literal that represents the value 305419896 in decimal. In C, hexadecimal integer literals are written with a leading 0x followed by the hexadecimal digits.

    %08X is a format specifier used with the printf function to print an integer value in hexadecimal format with leading zeros. The 0 in %08X specifies that leading zeros should be used to pad the output to 8 digits. The 8 in %08X specifies that the output should be 8 characters wide, and the X specifies that the output should be in uppercase hexadecimal format.

ABT"test01" - WHY"1st byte is 0x78 not 0x12"
    The reason the first byte of value being used to fill the memory region is 0x78 instead of 0x12 is because of the endianness of the machine. Assuming a little-endian machine (where the least significant byte of an integer is stored at the lowest memory address), the byte order of the int value 0x12345678 would be:
    | 0x78 | 0x56 | 0x34 | 0x12 |
    So, when memset(dest, value, sizeof(dest)) is called, the value of 0x78 is used to fill the memory region, because it is the least significant byte of the int value. The other three bytes are not used for the memory fill operation.

WHAT"The least significant byte"
    The least significant byte is the byte that holds the least significant (or least important) bits of an integer. In a little-endian machine, this byte is stored at the lowest memory address of the integer, while in a big-endian machine, it is stored at the highest memory address.

    For example, consider the int value 0x12345678. In a little-endian machine, the least significant byte is 0x78, which is stored at the lowest memory address. In a big-endian machine, the most significant byte would be stored at the lowest memory address, so the least significant byte would be 0x12.

DIFF"big-endian and little-endian"
    Most modern processors, including those from Intel, AMD, ARM, and many others, use the little-endian byte ordering. This is because little-endian byte ordering simplifies certain operations, such as arithmetic operations and memory addressing.

    However, some older processors, such as those from Motorola and Sun Microsystems, used big-endian byte ordering. Additionally, some network protocols, such as the Internet Protocol (IP), use big-endian byte ordering for their headers.

    Overall, the choice between big-endian and little-endian is determined by the architecture of the processor and the requirements of the applications and protocols that run on it. While little-endian is more popular in modern systems, big-endian is still used in some contexts.
*/