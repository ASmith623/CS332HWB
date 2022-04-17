#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#define _GNU_SOURCE
#include<sys/types.h>
#include<sys/wait.h>
#include <dirent.h>
/*
Name: Annalisa Smith
BlazerID: alenores
Project: Bonus HW
To compile: gcc -o uab_sh shelly.c
To run: ./uab_sh
*/

/*References:
https://stackoverflow.com/questions/59014090/warning-implicit-declaration-of-function-getline
https://www.geeksforgeeks.org/c-program-list-files-sub-directories-directory/
https://cboard.cprogramming.com/c-programming/70320-how-remove-newline-string.html
https://www.programiz.com/c-programming/library-function/string.h/strcmp
https://stackoverflow.com/questions/15178522/tokenizing-input-from-getline
https://www.programiz.com/c-programming/examples/fibonacci-series
https://stackoverflow.com/questions/8257714/how-to-convert-an-int-to-string-in-c
https://stackoverflow.com/questions/8107826/proper-way-to-empty-a-c-string
https://www.geeksforgeeks.org/exec-family-of-functions-in-c/
*/

void initialize()
{
    printf("\n******************\n******************\n");
    printf("BonusHW CS332\n");
    printf("alenores");
    printf("\n******************\n******************\n");
}

void help()
{
    printf("\n******************\n******************\n");
    printf("****HELP****\n");
    printf("Suppored Commands:\n");
    printf("- list: lists all files in current directory\n");
    printf("- cd <directory>: change current directory to specified directory\n");
    printf("- help: display supported commands\n");
    printf("- quit: quit shell program\n");
    printf("- hello: runs hello world program\n");
    printf("- fibonacci: runs fibonacci program and prints specified number of elements of fibonacci sequence");
    printf("\n******************\n******************\n\n");
}

char* input()
{
    char *buffer;
    size_t bufsize = 32;
    size_t in;
    buffer = (char*)malloc(bufsize*sizeof(char));
    if(!buffer)
    {
        printf("error with malloc");
        exit(-1);
    }

    printf("uab_sh > ");
    in = getline(&buffer, &bufsize, stdin);
    int len = strlen(buffer);
    if(buffer[len-1] == '\n'){
        buffer[len-1] = 0;
    }
    //printf("%zu characters were read.\n", in);
    //printf("You typed: '%s'\n",buffer);
    return buffer;
}

void dirCmd(char *to)
{
    chdir(to);
}

void helloCmd(){
    pid_t pid;
    int status;
    char *args[] = {"./hello", NULL};
    pid = fork();
    if (pid == 0) { /* this is child process */
        execvp(args[0], args);
        printf("If you see this statement then execl failed ;-(\n");
	exit(-1);
    } else if (pid > 0) { /* this is the parent process */
        wait(&status); /* wait for the child process to terminate */
    } else { /* we have an error */
        perror("fork"); /* use perror to print the system error message */
        exit(-1);
    }
}

void listCmd()
{
    struct dirent* dir;
    DIR *dirent = opendir(".");

    if(dirent == NULL){
        printf ("Error opening directory\n");
        exit (-1);
    }

    while((dir = readdir(dirent)) != NULL){
        printf("%s | ", dir->d_name);
    }
    printf("\n");
    closedir(dirent);
}

void fibCmd(int num)
{
    pid_t pid;
    int status;
    if(num <= 0)
    {
        char *args[] = {"./fibonacci", NULL};
        pid = fork();
        if (pid == 0) { /* this is child process */
            execvp(args[0], args);
            printf("If you see this statement then execl failed ;-(\n");
	        exit(-1);
        } else if (pid > 0) { /* this is the parent process */
            wait(&status); /* wait for the child process to terminate */
        } else { /* we have an error */
            perror("fork"); /* use perror to print the system error message */
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        int len = snprintf(NULL, 0, "%d", num);
        char* buf = malloc(len + 1);
        snprintf(buf, len + 1, "%d", num);
        char *args[] = {"./fibonacci", buf, NULL};
        pid = fork();
        if (pid == 0) { /* this is child process */
            execvp(args[0], args);
            printf("If you see this statement then execl failed ;-(\n");
	        exit(-1);
        } else if (pid > 0) { /* this is the parent process */
            wait(&status); /* wait for the child process to terminate */
        } else { /* we have an error */
            perror("fork"); /* use perror to print the system error message */
            exit(EXIT_FAILURE);
        }
        free(buf);
    }
}

void parse(char* in){
    char cmds[6][32];
    strcpy(cmds[0], "list");
    strcpy(cmds[1], "cd");
    strcpy(cmds[2], "help");
    strcpy(cmds[3], "quit");
    strcpy(cmds[4], "hello");
    strcpy(cmds[5], "fibonacci");
    char* tok;
    char hold[32];
    int comp;
    int a;
    int cmdI;
    tok = strtok(in, " ");    // Tokenize input
    if (tok != NULL) 
    {
        while(tok != NULL) 
        {
            for(a = 0; a < 6; a++){
                comp = strcmp(cmds[a], tok);
                if(comp == 0){
                    cmdI = a;
                    break;
                }
            }
            //printf("%s, index %d, comp %d\n", tok, a, comp);
            if(a >= 6){
                strcpy(hold, tok);
            }
            //printf("\n%s\n", hold);
            tok = strtok(NULL, " ");
        }
    }
    if(cmdI == 0){
        //printf("list\n");
        listCmd();
    }
    else if (cmdI == 1)
    {
        //printf("cd\n");
        dirCmd(hold);
    }
    else if (cmdI == 2)
    {
        //printf("help\n");
        help();
    }
    else if (cmdI == 3)
    {
        //printf("quit\n");
        exit(-1);
    }
    else if (cmdI == 4)
    {
        //printf("hello\n");
        helloCmd();
    }
    else if (cmdI == 5)
    {
        //printf("fibonacci\n");
        if(strlen(hold) == 0)
        {
            fibCmd(-1);
        }
        else
        {
            fibCmd(atoi(hold));
        }
    }
    else{
        printf("Input not reconized. Type help to view supported commands.\n");
    }
    cmdI = -1;
    strcpy(hold, "");
}

int main(int argc, char **argv){
    initialize();
    char* in;
    for(;;)
    {
        in = input();
	parse(in);
    }
    return 0;
}

