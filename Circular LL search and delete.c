#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data ;
    struct node *next ;
};
struct node *head ;

void insert ();
void search ();
void display ();

int main ()
{
    int n , choice ;
    
    while(choice != 4)
    {
        printf("Enter you choice : ");
        printf("\n1. INSERT\n2. SEARCH AND DELETE\n3. DISPLAY\n4. EXIT\n");
        scanf("%d",&choice);
    
    switch (choice) 
    {
        case 1:
        {
            insert ();
            break ;
        }
        
        case 2:
        {
            search ();
            break ;
        }
        
        case 3:
        {
            display ();
            break ;
        }
        
        case 4:
        {
            exit (0);
        }
    }
}
}

void insert ()
{
    int item ;
  struct node * ptr , * temp ;
  ptr = (struct node *)malloc(sizeof(struct node));
  if(ptr == NULL)
  {
      printf("Overflow\n");
  }
  else
  {
      printf("Enter the node value: ");
      scanf("%d",&item);
      
      ptr->data = item ; 
        
      if (head == NULL)
      {
          head = ptr ;
          ptr -> next = head ;
      }
      
      else
      {
          temp = head;
          while(temp->next != head)
          {
              temp = temp->next ;
          }
          
          temp -> next = ptr ;
          ptr -> next = head ;
      }
  }
}

void search ()
{
    int s , flag = 0;
    
    struct node *temp , *ptr ;
    
    temp = head  ;
    ptr = head ;
    
    printf("Enter the value you want to search and delete : ");
    scanf("%d",&s);

    while(temp->next != head)
    {
        if (s == temp->data)
        {
            if(temp == head)
            {   
                while (ptr->next != head)
                {
                ptr = ptr->next ;
                }
                head = temp -> next ;
               // ptr->next = head ;
                flag = 0 ;
                break ;
            }
            
            else
            {
                ptr = head ;
                while(ptr->next != temp)
                {
                    ptr= ptr -> next ;
                }
                ptr->next = temp->next ;
                flag = 0 ;
                break ;
            }
            
        }
            
        else
        {
         flag = 1 ;
        }
        temp = temp->next ;

    }
            
    if( temp->next == head )
            {
                while(ptr->next != temp)
                {
                    ptr = ptr->next ;
                }
                ptr->next = head ; 
                flag = 0 ;
            }
    
    
    
    if(flag == 1)
    {
        printf("Desired value is not present in the list !\n");
    }
    
    else
    {
        free(temp);
        printf("Node deleted successfully!!!!");
    }
}

void display ()
{
    struct node *temp , *ptr;
    temp = head ;
    
    while(temp->next != head)
    {
        printf("%d ",temp->data);
        temp = temp->next ;
    }
    printf("%d",temp->data);
    printf("\n");
}


