#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data ;
    struct node * next ;
};
struct node *head ;

void insert_beg();
void insert_end ();
void delete_beg();
void delete_end();
void search ();
void display ();

int main ()
{
    int choice ;
    while(choice != 7)
    {
    printf("*********MAIN MENU**********\n");
    printf("\nChoose one option from the given list:\n");
    printf("\n=============================\n");
    printf("\n1. Insert in begining\n2.Insert at last\n3.Delete from begining\n4.Delete from last\n5.Search for an element\n6.Display elements\n7.Exit\n");
    scanf("%d",&choice);
    
    switch(choice) 
    {
        case 1:
        {
            insert_beg ();
            break ;
        }
        
        case 2:
        {
            insert_end ();
            break ;
        }
        
        case 3:
        {
            delete_beg ();
            break ;
        }
        
        case 4:
        {
            delete_end ();
            break ;
        }
        
        case 5:
        {
            display () ;
            break ;
        }
        
        case 6:
        {
            search ();
            break ;
        }
        
        case 7:
        {
            exit(0);
            break ;
        }
        
        defaut :
        printf("Please enter a valid choice.");
        }
    }
}

void insert_beg()
{
    struct node *ptr , *temp ;
    int item ;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\nOverflow\n");
    }
    else
    {
        printf("\nEnter the data you want to enter: ");
        scanf("%d",&item);
        ptr -> data = item ;
        
        if(head == NULL)
        {
            head = ptr ;
            ptr -> next = head ;
        }
        else
        {
            temp = head ;
            while(temp->next != head)
            temp = temp->next ;
            ptr->next = head ;
            temp -> next = ptr ;
            head = ptr ;
        }
        printf("\nNode inserted successfully.....\n");
    }
}

void insert_end ()
{
    struct node *ptr , *temp ;
    int item ;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\nOverflow\n");
    }
    else
    {
        printf("\nEnter the data which you want to enter: \n");
        scanf("%d",&item);
        ptr -> data = item ;
        if(head == NULL)
        {
            head = ptr ;
            ptr -> next = head;
        }
        else
        {
            temp = head ;
            while(temp -> next != head)
            {
            (temp = temp->next);
            }
            temp -> next = ptr ;
            ptr -> next = head ;
        }
        printf("\nNode inserted successfully....\n");
    }
}

void delete_beg()
{
    struct node *ptr ;
    if(head == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else if(head->next == head)
    {
        head = NULL;
        free(head);
        printf("\nNode deleted successfully\n");
    }
    
    else
    {
        ptr = head ;
        while(ptr -> next != head)
        ptr = ptr -> next ;
        free(head);
        head = ptr->next ;
        printf("\nNode deleted\n");
    }
}

void delete_end()
{
    struct node*ptr , *preptr ;
    if(head == NULL)
    {
        printf("\nUnderflow\n");
    }
    else if(head -> next == head)
    {
        head = NULL ;
        free(head);
        printf("\nNode Deleted\n");
    }
    else
    {
        ptr = head ;
        while(ptr -> next != head)
        {
            preptr = ptr ;
            ptr = ptr->next ;
        }
        preptr->next = ptr->next ;
        free(ptr);
        printf("\nNode Deleted\n");
    }
}

void search ()
{
    struct node *ptr ;
    int item,i=0,flag=1 ;
    ptr = head ;
    if(ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter item which you want to search?\n");
        scanf("%d",&item);
        if(head -> data == item)
        {
            printf("\nItem found at location %d\n",i+1);
            flag = 0 ;
        }
        else
        {
            while(ptr->next != head)
            {
                if(ptr->data == item)
                {
                    printf("\nitem found at location %d",i+1);
                    flag = 0 ;
                    break ;
                }
                else
                {
                    flag = 1 ;
                }
                i++;
                ptr = ptr->next;
            }
        }
        if(flag != 0)
        {
            printf("\nItem not found\n");
        }
    }
}

void display ()
{
    struct node *ptr ;
    ptr = head ;
    if(head == NULL)
    {
        printf("\nNothing to print\n");
    }
    else
    {
        printf("\nprinting values....\n");
        
        while(ptr -> next != head)
        {
            printf("%d\n",ptr -> data);
            ptr = ptr -> next ;
        }
        printf("%d\n",ptr->data);
    }
}
