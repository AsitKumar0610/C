//Stack using linked list

#include<stdio.h>
#include<stdlib.h>


struct node 
{
    int data;
    struct node * link;
};
struct node * top=0;


void push(int x)
{
    struct node * newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->link=top;
    top=newnode;
}


void pop()
{
    struct node * temp;
    temp=top;
    if(top==0)
    {
        printf("underflow");
    }
    else
    {8
        printf("Deleted Element is: %d\n",top->data);
        top=top->link;
        free(temp);
    }
}


void peek()
{
    if(top==0)
    {
        printf("underflow");
    }
    else
    {
        printf("\nTop Element is: %d\n",top->data);
    }
}


void display()
{
    struct node * temp;
    temp=top;
    if(top==0)
    {
        printf("underflow");
    }
    else
    {
        while(temp!=0)
        {
            printf("%d\n",temp->data);
            temp=temp->link;
        }
    }
}


int main ()
{
    int choice, num ;
    while(choice!=5)
    {
        printf("1.Push an element\n");
        printf("2.Pop an element\n");
        printf("3.Display the elements\n");
        printf("4.Peek\n");
        printf("5.Stop\n");
        printf("Enter your choice :");
        scanf("%d",&choice);
        
        switch(choice)
        {
            
         case(1):
        {
         printf("Enter the element you want to push: ");
         scanf("%d",&num);
         push(num);
         break ;
        }
         
         case(2):
        {
         pop();
         break;
        }
         
         case(3):
        {
         display();
         break ;
        }
         
         case(4):
        {
         peek();
         break ;
        }
         
         case (5):
        {
         printf("Exiting......");
         break ;
        }
        }
    }
}

