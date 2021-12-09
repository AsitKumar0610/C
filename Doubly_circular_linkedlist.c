#include<stdio.h>
#include<stdlib.h>

struct node 
{
    struct node *prev ;
    struct node *next ;
    int data ; 
};
struct node *head ;

void insert_beg ();
void insert_end ();
void delete_beg ();
void delete_end ();
void display ();
void search ();

int main ()
{
    int choice ; 
    while(choice != 7)
    {
    printf("**********Main Menu**********");
    printf("\nChoose any one option from the following list\n");
    printf("\n=============================================\n");
    printf("\nEnter your choice?\n");
    printf("\n1.Insert in the begining");
    printf("\n2.Insert in the end");
    printf("\n3.Delete from front");
    printf("\n4.Delete from end");
    printf("\n5.Display");
    printf("\n6.Search");
    printf("\n7.Exit\n");
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
            display ();
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
        default:
        printf("\nEnter a valid choice: \n");
    }
    }
}

void insert_beg ()
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
        printf("\nEnter the value which you want to enter : \n");
        scanf("%d",&item);
        ptr->data = item ;
        if(head == NULL)
        {
            head = ptr ;
            ptr -> next = head ;
            ptr -> prev = head ;
        }
        else
        {
            temp = head ;
            while(temp -> next != head)
            {
                temp = temp->next ;
            }
            temp -> next = ptr ;
            ptr -> prev = temp ;
            head ->prev =  ptr ;
            ptr -> next = head ;
            head = ptr ;
        }
    }
}

void insert_end ()
{
    struct node *ptr, *temp ;
    int item ;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\nOverflow\n");
    }
    else
    {
        printf("\nEnter value : ");
        scanf("%d",&item);
        ptr->data = item ;
        if(head == NULL)
        {
            head = ptr ;
            ptr -> next = head ;
            ptr -> prev = head ;
        }
    }
}

void delete_beg ()
{
    struct node *temp ;
    if(head == NULL)
    {
        printf("\nUnderflow\n");
    }
    else if(head->next == head)
    {
        head = NULL ;
        free(head);
        printf("\nNode Deleted\n");
    }
    else
    {
        temp = head ;
        while(temp -> next != head)
        {
            temp = temp -> next ;
        }
        temp -> next = head -> next ;
        head -> next -> prev = temp ;
        free(head);
        head = temp -> next ;
    }
}

void delete_end ()
{
    struct node *ptr ;
    if(head == NULL)
    {
        printf("\n UNDERFLOW\n");
    }
    else if(head -> next == head)
    {
        head = NULL ;
        free(head);
        printf("\nNode Deleted successfully\n");
    }
    else
    {
        ptr = head ;
        if(ptr -> next != head)
        {
        ptr = ptr -> next ;
        }
        ptr -> prev -> next = head ;
        head -> prev = ptr -> prev ;
        free(ptr);
        printf("\nnode deleted\n");
    }
}

void display ()
{
    struct node *ptr ;
    ptr = head ;
    if(head == NULL)
    {
        printf("Nothing to print\n");
    }
    else
    {
        printf("\n Printing values...\n");
        while(ptr -> next != head)
        ptr = ptr -> next ;
    }
    printf("%d",ptr -> data);

}

void search ()
{
    struct node *ptr ;
    int item,i=0,flag=1;
    ptr = head ;
    if(ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter item which you want to seach?\n");
        scanf("%d",&item);
        if(head->data == item)
        {
            printf("Item found at locaton %d\n",i+1);
            flag = 0 ;
        }
        else
        {
        while(ptr -> data != item)
        {
            if(ptr -> data == item)
            {
                printf("Item found at location %d\n",i+1);
                flag=0;
                break ;
            }
            else
            {
                flag = 1 ;
            }
            i++ ;
            ptr = ptr -> next ;
        }
        }
        if(flag != 0)
        {
            printf("\nItem not found\n");
        }
    }
}
