#include<stdio.h>
#include<stdlib.h>
#define MAX  100

struct node 
{
    int data ;
    struct node *next ;
    struct node *prev ;
};
struct node *head ;

void palindrome ();
void display ();
void delete ();
void insert ();

int main ()
{
    int choice = 0;
    while(choice != 5)
    {
        printf("\n************Main Menu*************\n");
        printf("\n========================================================\n");
        printf("\n1.Insert\n2.Delete\n3.Show\n4.Palindrome Check\n5.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
            insert();
            break ;
            
            case 2:
            delete();
            break ;
            
            case 3:
            display();
            break ;
            
            case 4 :
            palindrome();
            
            case 5 :
            exit(0);
            break ;
            
            default:
            printf("Please enter valid choice!!\n");
        }
    }
}
void insert()
{
    struct node*ptr,*temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\nOverflow...\n");
    }
    else{
        printf("\nEnter value: ");
        scanf("%d",&item);
        ptr->data = item;
        
        if(head == NULL)
        {
            ptr->next = NULL ;
            ptr->prev = NULL ;
            head = ptr ;
        }
        else
        {
           temp = head ;
           while(temp->next != NULL)
           {
               temp = temp->next ;
           }
           temp->next = ptr ;
           ptr->prev = temp ;
           ptr->next = NULL ;
        }
    }
    printf("\nNode inserted successsfully\n");
}

void delete()
{
    struct node* ptr ;
    if(head == NULL)
    {
        printf("\nUnderflow\n");
    }
    else if(head->next == NULL)
    {
        head = NULL ;
        free(head);
        printf("\nNode deleted successfully\n");
    }
    else
    {
        ptr = head ;
        if(ptr->next != NULL)
        {
            ptr = ptr -> next ;
        }
        ptr -> prev -> next = NULL ;
        free(ptr);
        printf("\nNode deleted\n");
    }
}

void display ()
{
    struct node *ptr ;
    printf("\nPrinting values....\n");
    ptr = head ;
    
    while(ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}

void palindrome ()
{   
    int i = 0 , v = 0 , arr[MAX] , flag = 0 ;
    struct node *ptr , *temp ;
    temp = head ;
    ptr = head ;
    while(ptr->next != NULL)
    {
        ptr= ptr->next ;
    }
    
    while(temp -> next != NULL)
    {
        arr[i] = temp->data ;
        i++ ;
        temp = temp -> next ;
    }
    i++ ;
    arr[i] = temp -> data ;
    
    while(ptr -> prev != head )
    {
        arr[v] = ptr->data ;
        v++ ;
        ptr = ptr -> prev ;
    }
    v++ ;
    arr[v] = ptr->data ;
    
    for(i=0; i < v ; i++ )
    {
        if (arr[i] != arr[v])
        flag = 1;
        break ;
    }
    if (flag == 1)
    {
        printf("Linked list is not a palindrome");
    }
    else
    {
        printf("Linked list is a palindrome");
    }
}
