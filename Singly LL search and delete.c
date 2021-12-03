#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
}*start;


void create()
{
  int n;
  start=NULL;
  struct node *newnode,*temp;
  printf("\nEnter number of element you want to enter:");
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(start==NULL)
    {
      start=temp=newnode;
    }
    else
    {
      temp->next=newnode;
      temp=newnode;
    }
  }
}


void display()
{
  struct node *temp;
  temp=start;
  printf("\nThe elements are:");
  while(temp!=NULL)
  {
    printf("%d ",temp->data);
    temp=temp->next;
  }
}


void keyvalue()
{
  int f=0;
  struct node *prev,*temp;
  int keyv;
  printf("\nEnter the key value:");
  scanf("%d",&keyv);
  temp=start;
  while(temp!=NULL)
  {
    
    if(keyv==temp->data)
    {
      if(temp==start)
      {
        temp=prev=start;
        printf("Key Value Found.");
        start=start->next;
      }
      else if(temp->next==NULL)
      {
        printf("\nKey Value Found.");
        prev->next=0;
      }
      else
      {
        printf("\nKey Value Found.");
        prev->next=temp->next;
      }
      free(temp);    
      f=1;
      break;
    }
    else
    {
      prev=temp;
      temp=temp->next;
    }
  }
  if(f==0)
  {
    printf("\nKey Value Not Found.");
  }
  display();
}


int main()
{
        create();
        display();
        keyvalue();   
        printf("\n\nEXITING...\n\n");
        exit(0);
}
