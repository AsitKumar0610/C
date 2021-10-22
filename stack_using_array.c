//Stack using array.

#include<stdio.h>
int stack[100],i,j,choice=0,n,top=-1;
void push();
void pop();
void peek();
void show();
void exiting();
void main ()
{
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("\n\n....STACK IMPLIMENTATION USING ARRAYS....\n\n");
    while(choice != 5)
    {   printf("\n");
        printf("Choose one from the below options!\n");
        printf("1. Pushing\n");
        printf("2. Popping\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exitng\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case(1):
            {
                push();
                break ;
            }
            case(2):
            {
                pop();
                break;
            }
            case(3):
            {
                peek();
                break;
            }
            case(4):
            {
                show();
                break;
            }
            case(5):
            {
                printf("Exiting.....");
                break;
            }
            default:
            {
                printf("Enter a valid choice.....");
            }
            
        };
    }
}
void push()
{
    int val ;
    if(top == n)
        printf("Stack is full");
    else
        printf("Enter the value: ");
        scanf("%d",&val);
        top = top + 1;
        stack[top] = val;
}
void pop()
{
    if(top == -1)
    printf("Stack is empty.");
    else
    printf("popped element is: %d\n",stack[top]);
    top = top - 1 ;
}
void peek()
{
    printf("%d\n",stack[top]);
}
void show()
{
    for(i = top ; i >= 0 ; i--)
    {
    printf("%d ",stack[i]);
    }
    if(top == -1)
    {
    printf("Stack is empty.");
    }
}

#include<stdio.h>
int stack[100],i,j,choice=0,n,top=-1;
void push();
void pop();
void peek();
void show();
void exiting();
void main ()
{
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("\n\n....STACK IMPLIMENTATION USING ARRAYS....\n\n");
    while(choice != 5)
    {   printf("\n");
        printf("Choose one from the below options!\n");
        printf("1. Pushing\n");
        printf("2. Popping\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exitng\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case(1):
            {
                push();
                break ;
            }
            case(2):
            {
                pop();
                break;
            }
            case(3):
            {
                peek();
                break;
            }
            case(4):
            {
                show();
                break;
            }
            case(5):
            {
                printf("Exiting.....");
                break;
            }
            default:
            {
                printf("Enter a valid choice.....");
            }
            
        };
    }
}
void push()
{
    int val ;
    if(top == n)
        printf("Stack is full");
    else
        printf("Enter the value: ");
        scanf("%d",&val);
        top = top + 1;
        stack[top] = val;
}
void pop()
{
    if(top == -1)
    printf("Stack is empty.");
    else
    printf("popped element is: %d\n",stack[top]);
    top = top - 1 ;
}
void peek()
{
    printf("%d\n",stack[top]);
}
void show()
{
    for(i = top ; i >= 0 ; i--)
    {
    printf("%d ",stack[i]);
    }
    if(top == -1)
    {
    printf("Stack is empty.");
    }
}

