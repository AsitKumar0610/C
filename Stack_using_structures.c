//Stack using structures

#include<stdio.h>
#define MAXSIZE 5

struct stack
{
    int stk[MAXSIZE];
    int top;
};
typedef struct stack STACK;
STACK s;

void push (void);
int pop(void);
void display(void);

void main ()
{
    int choice ;
    int option = -1 ;
    s.top = -1 ;
    
    printf("STACK OPERATION\n");
    while(choice != 4)
    {
        printf("___________________________________________\n");
        printf("1 --> PUSH\n");
        printf("2 --> POP\n");
        printf("3 --> DISPLAY\n");
        printf("4 --> EXIT\n");
        printf("___________________________________________\n");
        printf("Enter your choice!\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: 
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return;
        }
    }
}
void push()
{
    int num;
    if(s.top == (MAXSIZE - 1))
    {
        printf("Stack is Full\n");
    }
    else
    {
        printf("Enter the element to be pushed\n");
        scanf("%d",&num);
        s.top = s.top + 1;
        s.stk[s.top] = num;
    }
}
int pop ()
{
    int num ;
    if(s.top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        num = s.stk[s.top];
        printf("Popped element is = %d\n", s.stk[s.top]);
        s.top = s.top - 1 ;
    }
}
void display ()
{
    int i ;
    if(s.top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("The status of the stack is \n");
        for(i = s.top ; i >= 0 ; i--)
        {
            printf("%d ",s.stk[i]);
        }
    }
    printf("\n");
}

