#include<stdio.h>
#include<ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int precedence(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

void main()
{
    char in[100],x;
    int i=0;
    printf("Enter the expression : ");
    scanf("%s",in);
    printf("\n");
    while(in[i]!='\0')
    {
        if(isalnum(in[i]))
            printf("%c ",in[i]);
        else if(in[i] == '(')
            push(in[i]);
        else if(in[i] == ')')
        {
            while((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while(precedence(stack[top]) >= precedence(in[i]))
                printf("%c ",pop());
            push(in[i]);
        }
        i++;
    }
    while(top != -1)
    {
        printf("%c ",pop());
    }
    printf("\n");
}

