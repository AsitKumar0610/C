//Circular Queue

#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int front = -1 ;
int rear = -1 ;
void enqueue (int item);
void dequeue ();
void show ();
int arr[MAX];
int main ()
{
    int choice, item ;
    do
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d",&item);
            enqueue(item);
            break ;
        
        case 2:
            dequeue();
            break ;
            
        case 3:
            show ();
            break;
            
        case 4:
            exit (0);
            
        default:
            printf("Enter a valid otpion: ");
    }
    }while(choice != 4);
    return 0 ;
    


}

void enqueue (int item)
{
    if((front == 0 && rear == MAX - 1)||(front == rear + 1))
        {
        printf("Queue is full\n");
        }
    if ( front == -1 )
        {
            front = 0;
            rear = 0 ;
        }
    else 
        {
            if(rear == MAX - 1)
            rear = 0 ;
            else
            rear = rear + 1 ;
        }
            arr[rear] = item ;
        }
        
void dequeue ()
{
        if(front == -1)
        {
            printf("Queue is empty");
        }
            printf("Element deleted from the queue is : %d\n",arr[front]); 
            if(front == rear)
            {
                front = -1 ;
                rear = -1 ;
            }
            else
            {
                if(front == MAX - 1)
                front = 0 ;
                else 
                front = front + 1 ;
            }
}
    
void show ()
{
    int front_pos = front, rear_pos = rear ;
    if(front == -1)
    {
        printf("Queue is empty");
    }
    printf("Queue elements are:  \n");
    if(front_pos <= rear_pos)
    while(front_pos <= rear_pos)
    {
        printf("%d ",arr[front_pos]);
        front_pos++;
    }
    else
    {
        while(front_pos <= MAX-1)
        {
            printf("%d",arr[front_pos]);
            front_pos++;
        }
        front_pos = 0;
        while(front_pos <= rear_pos)
        {
            printf("%d ",arr[front_pos]);
            front_pos++;
        }
    }
    printf("\n");
} 
