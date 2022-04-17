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
I upload 2 pictures that show sample runs of the program.
