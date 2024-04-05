#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];

int top = -1;

void push(char data)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Overflow stack!\n");
        return;
    }
    top++;
    stack[top] = data;
}

char pop()
{
    if (top == -1)
    {
        printf("Empty Stack!\n");
        return '\0';
    }
    char data = stack[top];
    top--;
    return data;
}

int main()
{
    char input[MAX_SIZE];
    printf("Input a string: ");
    fgets(input, MAX_SIZE, stdin);
    input[strcspn(input, "\n")] = '\0';
    int len = strlen(input);
    for (int i = 0; i < len; i++)
    {
        push(input[i]);
    }
    for (int i = 0; i < len; i++)
    {
        input[i] = pop();
    }
    printf("Reversed string using a stack is: %s\n",input);
    return 0;
}