//Implementation of Singly Linked List

#include<stdio.h>
#include<malloc.h>

void display ();
void insert(int);
int delete();

struct node
{
 int info ;
 struct node *next ;
};
typedef struct node node;
node *head = NULL ;
int main ()
{
    int choice,n ;

    while(choice!=4)
    {
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        
        printf("Enter your choice here: ");
        scanf("%d",&choice);
        
        switch (choice)
        {
            case 1:
            {
            printf("Enter the element to be inserted: ");
            scanf("%d",&n);
            insert(n);
            break ;
            }
            
            case 2:
            {
                printf("%d \n",delete());
                break ;
            }
            
            case 3:
            {
                display();
                break ;
            }
            
            case 4:
            {
            break ;
            }
        }
    }
}

void insert(int n)
{
    node *temp = head ;
    temp = (node*)malloc(sizeof(node));
    temp->info = n ;
    temp->next = NULL ;
    
    if(head==NULL)
    {
        head = temp ;
    }
    
    else
    {
        temp->next = head ;
        head = temp ;
    }
}

void display()
{
    node *temp = head ;
    while (temp!=NULL)
    {
        printf("%d \n",temp->info);
        temp=temp->next;
    }
}

int delete ()
{
    node *temp=head;
    temp->next=NULL;
    int a=temp->info ;
    free(temp);
    return a ;
}
