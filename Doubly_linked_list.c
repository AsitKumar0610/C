#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev ;
    struct node *next ;
    int data ;
};
struct node *head ;

void insertion_beg();
void insertion_last();
void insertion_spec ();
void deletion_beg();
void deletion_last();
void deletion_spec();
void display ();
void search ();

int main ()
{
    int choice = 0;
    while(choice != 9)
    {
        printf("\n************Main Menu*************\n");
        printf("\n========================================================\n");
        printf("\n1.Insert in beginning\n2.Insert at last\n3.Insert at any random location\n4.Delete from the front\n5.Delete from the end\n6.Delete after the given node\n7.Search\n8.Show\n9.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
            insertion_beg();
            break ;
            
            case 2 :
            insertion_last();
            break ;
            
            case 3 :
            insertion_spec();
            break ;
            
            case 4:
            deletion_beg();
            break ;
            
            case 5:
            deletion_last();
            break ;
            
            case 6:
            deletion_spec();
            break ;
            
            case 7:
            search();
            break ;
            
            case 8:
            display();
            break ;
            
            case 9 :
            exit(0);
            break ;
            
            default:
            printf("Please enter valid choice!!\n");
        }
    }
}

void insertion_beg()
{
    struct node *ptr ;
    int item ;
    ptr = (struct node*)malloc(sizeof(struct node*));
    
    if (ptr == NULL)
    {
        printf("\noverflow...\n");
    }
    else
    {
        printf("\nEnter item value: \n");
        scanf("%d",&item);
        
        if(head==NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            ptr->data = item;
            head = ptr ;
        }
        else
        {
            ptr->data = item ;
            ptr->prev = NULL ;
            ptr->next = head ;
            head->prev = ptr ;
            head= ptr ;
        }
        printf("\nNode inserted successfully\n");
    }
}

void insertion_last()
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
void insertion_spec ()
{
    struct node *ptr , *temp ;
    int item , loc , i ;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\nOverflow...\n");
    }
    else{
        temp = head ;
        printf("\nEnter the location: ");
        scanf("%d",&loc);
        
        for(i=0 ; i < loc ; i++)
        {
            temp = temp->next ;
            if(temp == NULL)
            {
                printf("\n There are less than %d elements\n",loc);
                return ;
            }
        }
        
        printf("Enter value");
        scanf("%d",&item);
        ptr->data = item ;
        ptr->next = temp->next ;
        temp->next->prev = ptr ;
        ptr->prev = temp ;
        temp->next = ptr ;
        printf("\nNode inserted successfully....\n");
    }
}

void deletion_beg()
{
    struct node *ptr ;
    if(head == NULL)
    {
        printf("\nUnderflow....\n");
    }
    else if(head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nNode deleted successfully\n");
    }
    else
    {
        ptr = head ;
        head = head->next ;
        head ->prev = NULL ;
        free(ptr);
        printf("\nNode deleted successfully\n");
    }
}

void deletion_last()
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

void deletion_spec()
{
    struct node *ptr , *temp ;
    int val ;
    printf("\nEnter the data after which the node is to be deleted: ");
    scanf("%d",&val);
    ptr = head ;
    while(ptr -> data != val)
    ptr = ptr -> next ;
    if(ptr -> next == NULL)
    {
        printf("\nCan't delete\n");
    }
    else if(ptr -> next -> next == NULL)
    {
        ptr -> next = NULL ;
    }
    else
    {
        temp = ptr -> next ;
        ptr -> next = temp -> next ;
        temp -> next -> prev = ptr ;
        free(temp);
        printf("\nNode deleted successfully\n");
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

void search ()
{
    struct node *ptr ;
    int item, i =0 , flag ;
    
    if(ptr == NULL)
    {
        printf("\nList is empty\n");
    }
    
    else
    {
        printf("\nEnter value which you want to search?\n");
        scanf("%d",&item);
        while(ptr != NULL)
        {
            if(ptr->data == item)
            {
                printf("\nItem found at location %d",i+1);
                flag=0 ;
                break ;
            }
            else
            {
                flag = 1 ;
            }
            i++ ;
            ptr = ptr -> next ;
        }
        if(flag == 1)
        {
            printf("\nItem not found\n");
        }
    }
}

