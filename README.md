# CS332HWB Annalisa Smith alenores
I created a c file called shelly.c which makes a basic shell. This shell supports 5 commands:
- list: lists all files in current directory
- cd <directory>: change current directory to specified directory
- help: display supported commands
- quit: quit shell program
- hello: runs hello world program (hello.c)
- fibonacci: runs fibonacci program and prints specified number of elements of fibonacci sequence (fibonacci.c)
The hello and fibonacci commands run the programs hello.c and fibonacci.c, respectively, which I also wrote.
To compile: gcc -o uab_sh shelly.c
To run: ./uab_sh
I also created I Makefile that will compile shelly with the command "make" and run the executable uab_sh with the command "make run".
  
Here is a sample of running the program:
  
******************
******************
BonusHW CS332
alenores
******************
******************
uab_sh > fibonacci
How many elements do you want to display: 14
The first 14 values: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233
uab_sh > fibonacci
How many elements do you want to display: 7
The first 7 values: 0, 1, 1, 2, 3, 5, 8
uab_sh > hello
Hello World!
uab_sh > list
. | .. | fibonacci | fibonacci.c | fibonacci.o | hello | hello.c | hello.o | Makefile | shelly | shelly.c | shelly.o | uab_sh |
uab_sh > cd ..
uab_sh > list
. | .. | HW1 | HW2 | HW3 | HWB | Lab01 | Lab02 | Lab04 | Lab05 | Lab09 | Lab10 | Lab12 |
uab_sh > help

******************
******************
****HELP****
Suppored Commands:
- list: lists all files in current directory
- cd <directory>: change current directory to specified directory
- help: display supported commands
- quit: quit shell program
- hello: runs hello world program
- fibonacci: runs fibonacci program and prints specified number of elements of fibonacci sequence
******************
******************

uab_sh > quit
  
Here is another sample:
  
******************
******************
BonusHW CS332
alenores
******************
******************
uab_sh > fibonacci
How many elements do you want to display: 19
The first 19 values: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584
uab_sh > fibonacci 3
The first 3 values: 0, 1, 1
uab_sh > hello
Hello World!
uab_sh > list
. | .. | fibonacci | fibonacci.c | fibonacci.o | hell0.c | hello | hello.c | hello.o | Makefile | shelly | shelly.c | shelly.o | uab_sh |
uab_sh > quit
