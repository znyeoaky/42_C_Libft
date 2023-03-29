### gcc -L. -lft *.c ###
### ./a.out ###

// gcc: the command to invoke the GNU Compiler Collection, which is used to compile C code.
// -L.: tells the linker to search for libraries in the current directory (represented by the .).
// -lft: tells the linker to look for a library called libft.a. 
//       (By convention, library names usually start with lib and end with .a for static libraries, or .so for shared libraries.)
// *.c: file name

### What is size_t? When should I use size_t in C? ###

// 1. The size_t data type in C is an unsigned integer type 
// used to represent the size of objects in bytes.

// 2. size_t is commonly used for array indexing and loop counting. 
// Programs that use other types, such as unsigned int, 
// for array indexing may fail on, e.g. 64-bit systems 
// when the index exceeds UINT_MAX or if it relies on 32-bit modular arithmetic.

### "What is malloc 3?" ###
// The malloc() function allocates size bytes and returns a pointer to the allocated memory. 
// The memory is not initialized. If size is 0, then malloc() returns either NULL, 
// or a unique pointer value that can later be successfully passed to free().

### "what difference between char * and char const * in C" ###
// In C, both char * and char const * are pointers to a sequence of characters (a string). 
// However, there is an important difference between them:

// ! char * is a pointer to a mutable (modifiable) sequence of characters. 
// This means that the characters in the string can be changed through the pointer.

// ! char const * is a pointer to an immutable (non-modifiable) sequence of characters. 
// This means that the characters in the string cannot be changed through the pointer.

// Here's an example to illustrate the difference:
    char str1[] = "Hello, world!"; // a mutable string
    char const str2[] = "Hello, world!"; // an immutable string

    char *p1 = str1; // pointer to a mutable string
    p1[0] = 'h'; // change the first character to 'h'
    printf("%s\n", p1); // prints "hello, world!"

    char const *p2 = str2; // pointer to an immutable string
    p2[0] = 'h'; // error: cannot modify an immutable string
    printf("%s\n", p2); // prints "Hello, world!"


###
###