# Calculator

## Purpose
The program is a calculator that operates in Reverse Polish Notation. It computes different arithmetic operations, such as addition, subtraction, multiplication, division, absolute value, sine, cosine, and tangent. 
### Reverse Polish Notation
The calculator requires the user to input arithmetic equations using RPN:

1 + 2&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;1 2 +

The calculator can handle multiple operations in one line:

1 - (2 + 3)&emsp;&emsp;&emsp;&emsp;&emsp;1 2 3 + -

The symbols are as shown below:

Addition&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;+&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;Subtraction&emsp;&emsp;&emsp;&nbsp;&nbsp;&nbsp;-

Multiplication&emsp;&emsp;&emsp;*&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;Division&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;/

Sine&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;s&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;Cosine&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;&nbsp;c

Tangent&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;t&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;Absolute Value&emsp;&emsp;&nbsp;a
## How To Use
1. Clang Format
   - The code needs to be properly formatted to be readable
     - Ensure that the makefile has the following command:
       - format: clang-format -i -style=file *.[ch]
     - Run **make format** command to format the styling of all of the files

2. How to Compile the Program
   - Make sure that the format of the Makefile is correct
     - Make sure that the Makefile has its CC set to clang
     - Make sure all the CFLAGS are as follows
       - -Wall -Wextra -Wstrict-prototypes -Werror -pedantic
     - Make sure Makefile has LFLAGS -lm
     - Make sure the program is named calc
     - Make sure **calc:** contains **calc.o, stack.o, mathlib.o, operators.o**
   - Make sure all object files and binary files are removed using command **make clean**
   - run **make** to compile the program

3. How to Run the Program
   - Make sure the calc binary is in the same directory
   - This program does not expect any command-line arguments
   - Run the program using ./calc
   - type Ctrl-D to end the program
