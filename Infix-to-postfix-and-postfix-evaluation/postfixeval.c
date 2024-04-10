#include<stdio.h>
int stack[20];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

void main()
{
    char px[20];
    int n1,n2,n3,num,i=0;
    printf("Enter the expression : ");
    scanf("%s",px);
    while(px[i] != '\0')
    {
        if(isdigit(px[i]))
        {
            num = px[i] - 48;
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch(px[i])
            {
                case '+':
                {
                    n3 = n1 + n2;
                    break;
                }
                    
                case '-':
                {
                    n3 = n2 - n1;
                    break;
                }
                    
                case '*':
                {
                    n3 = n1 * n2;
                    break;
                }
                    
                case '/':
                {
                    n3 = n2 / n1;
                    break;
                }
           }
           push(n3);
        }
        i++;
    }
    printf("\nThe result of the expression %s  =  %d\n\n",px,pop());
}
