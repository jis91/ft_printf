*This project has been created as part of the 42 curriculum by jstrasse*

ft_printf | 42 Lausanne 
made by Jefferson Strasser (jstrasse@student.42lausanne.ch)


<ins>**Description**</ins>

What is printf and ft_printf ? And what is the goal of this project ?

The printf function can be found in stdio.h header (#include <stdio.h>). 
All the differents formats, flags and conversion specifier, and information on this function can be found in the man (man printf). 
This project consists of coding a library that contains a simplified version of the printf function : the ft_printf function.

My version will only work with the following conversion specifiers: 

<ins>%</ins>: prints the percent character.

<ins>c</ins>: prints a character.

<ins>s</ins>: prints a string (array of characters).

<ins>d</ins> or <ins>i</ins>: prints an integer, a short or a long.

<ins>p</ins>: prints a pointer adress in hexadecimal format (starting with 0x).

<ins>u</ins>: prints an unsigned integer.

<ins>x</ins>: prints an unsigned hexadecimal integer (lowercase a-f).

<ins>X</ins>: prints an unsigned hexadecimal integer (uppercase A-F).

You have to add the conversion specifier after the % character. (example : ft_printf("%%"), to print a % character).

<ins>**Instructions**</ins>

To compile the library you have to have gcc installed as a compiler (this is a C project).
To compile the library you can go to the library path and run : 'make'.

To use the library function just include its header in your code (#include "/path/to/library/ft_printf.h")

<ins>**Resources**</ins>

My first resource was of course the man page for printf (man printf). 
This being a complicated function I also had a look at different github guides (https://github.com/Surfi89/ft_printf), (https://42-cursus.gitbook.io/guide/1-rank-01/ft_printf), as well as comparing my code to fellow students here in 42 Lausanne.
I did not use AI to code or to explain any part of this project. 

<ins>**Difficulties**</ins>

The main difficulty I encountered in this project was the variadic functions which accepts a variable number of arguments. I had to read the man page for va_list, va_start, va_end as well as the github guides to understand how it works. 

I also had questions on the size of a pointer. Depending the system we use the size of a pointer will change. 
For this issue I chose to use the stdint.h header which include the uintptr_t data type. It is designed to be large enough to hold any pointer value making it an essential tool for portable and platform-independent pointer manipulation. I have seen some people using unsigned int instead which works perfectly fine on the school computers.

<ins>**Testing the function**</ins>

There is no main provided on this git. For 42 Lausanne evaluators I have a main.c function on my personal space on 42 computers that you can use (I can show you during evaluation it is in /home/Tests/printf/main.c).

If you want to test my function on yourself you just have to make a main.c file in the same folder and #include "ft_printf.h" to test. 
My version of main.c tests the different conversion specifiers on their own and in combination with others. It also prints out the normal printf function to compare.

You can also test the function with free testers you can find on the web such as printfTester (https://github.com/Tripouille/printfTester).

On the computers at school I have francinette installed. For evaluation you can also use francinette or paco in the repository as an alias to launch the tests. 

Thank you for reading I hope you enjoy work/code. Cheers ! Jefferson 