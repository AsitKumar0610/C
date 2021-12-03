#include<stdio.h>
#include<stdlib.h>

struct node 
{
    struct node* prev ;
    int data ; 
    struct node* next ;
};

void insert ();
void search ();
void display ();

struct node *head ;

int main ()
{
    int n , choice ;
while (choice != 5)
{
    printf("Enter your choice : ");
    printf("\n1.INSERT \n2.SEARCH AND DELETE \n3.DISPLAY\n4.EXIT\n");
    scanf("%d",&choice);
    switch(choice)
    {
        
    case 1:
    {
        insert ();
        break ;
    }
    
    case 2:
    {
        search();
        break ;
    }
    
    case 3:
    {
        display();
        break ;
    }
    
    case 4:
    {
        exit(0);
        break ;
    }
    
    default:
    printf("\nEnter a valid choice\n");
    }
}
}
void insert ()
{
    int item ;
    struct node *temp , *ptr ;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("Overflow");
    }
    
    else 
    {
        printf("Enter the node value: ");
        scanf("%d",&item);
        if(head == NULL)
        {
            ptr->data = item ;
            ptr->prev = NULL ;
            ptr->next = NULL ;
            head = ptr ;
        }
        
        else
        {
            ptr->data = item ;
            ptr->next = head ;
            ptr->prev = NULL ;
            head->prev = ptr ;
            head = ptr ;
        }
    }
}

void search ()
{
    int s;
    struct node *ptr ;
    struct node *temp ;
    ptr = (struct node*)malloc(sizeof(struct node));
    int flag = 0 ;
    
    printf("Enter the node value you want to search and delete : ");
    scanf("%d",&s);
    
    temp = ptr = head ;
    
    while(temp != NULL)
    {
    if(s == temp->data)
    {
        if(temp == head)
        {
            head = temp->next;
            temp->next = NULL ;
            flag = 0 ;
            break ;
        }
        
        else if(temp->next == NULL)
        {
            ptr = temp->prev ;
            ptr -> next = NULL ;
            flag = 0 ;
            break ;
        }
        
        else 
        {
            ptr = temp->prev ;
            ptr->next = temp->next ;
            flag = 0;
            break ;
        }
    }
    
    else
    {
        flag = 1 ;
    }
    temp = temp->next ;
}
    
if(flag == 1)
{   
    printf("Value not found ! Please try again !\n") ;
}
else
{
    free(temp);
    printf("Searched node is deleted\n");
}

}

/*void display ()
{
    struct node *temp ;
    temp = head ;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next ;
    }
    printf("\n");
}*/

void display ()
{
    struct node *temp ;
    temp = head ;
    
    while(temp->next != NULL)
    {
        temp = temp->next ;
    }
    
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->prev ;
    }
    printf("\n");
}

