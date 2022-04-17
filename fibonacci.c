#include<stdio.h>
/*
Name: Annalisa Smith
BlazerID: alenores
To compile: gcc -o fibonacci fibonacci.c
To run: ./fibonacci
*/

int main(int argc, char **argv){
    int e1 = 0;
    int e2 = 1;
    int num;
    if(argc == 1){
        printf("How many elements do you want to display: ");
        scanf("%d", &num);
    }
    else
    {
        num = atoi(argv[1]);
    }
    printf("The first %d values: %d", num, e1);
    if(num >= 2)
    {
        printf(", %d", e2);
    }
    if(num > 2){
        int i, next;
        for(i = 3; i <= num; i++)
        {
            next = e1 + e2;
            e1 = e2;
            e2 = next;
            printf(", %d", next);
        }
    }
    printf("\n");
    return 0;
}
