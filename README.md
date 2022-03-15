# my_printf
Implementation of my_printf

The **my_printf()** function writes output to stdout, the standard output stream.

The format string is composed of zero or more directives: ordinary characters (not %), which are copied unchanged to the output stream; and conversion specifications, each of which results in fetching zero or more subsequent arguments.

Each conversion specification is introduced by the % character. The arguments must correspond properly (after type promotion) with the conversion specifier. After the %, the following appear in sequence:

The int (or appropriate variant) argument is converted to signed decimal (d). unsigned octal (o), unsigned decimal (u), unsigned hexadecimal (x).

c is converted to an unsigned char, and the resulting character is written.

s The char* argument is expected to be a pointer to an array of character type (pointer to a string). Characters from the array are written up to (but not including) a terminating NULL character.

p The void * pointer argument is printed in hexadecimal.

Note: For the format specifier %p, I added an alternative implementation of MemCpy (my_MemCpy) to be able to copy the pointer's adress, as using any functions other than **write**, **malloc**, **free**, **va_start**, **va_arg**, **va_copy** or **va_end** was not allowed.
