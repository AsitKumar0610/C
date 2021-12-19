#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int key ;
    struct node *left ;
    struct node *right ;
};

struct node *newNode (int item)
{
    struct node*temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item ;
    temp->left = NULL ;
    temp->right = NULL ;
    return temp ;
}

struct node *insert(struct node* node , int item)
{
    if(node == NULL)
    return newNode(item) ;
    
    else if(item < node->key)
    {
        node -> left = insert (node->left , item);
    }
    else
    {
        node -> right = insert (node -> right , item);
    }
    return node ;
}

unsigned int getLeafCount(struct node* node)
{
  if(node == NULL)      
    return 0;
  if(node->left == NULL && node->right==NULL)     
    return 1;           
  else
    return getLeafCount(node->left)+
           getLeafCount(node->right);
}

int main() {
    
    struct node *root = NULL ;
    
    int key , x , i , n , ch  ;
    while(ch != 4)
    {
    printf("Enter your choice : \n");
    printf("1.Insert\n");
    printf("2.No. of leaf nodes : \n");
    printf("3.Exit\n");
    
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        printf("Enter the key to insert: \n");
        scanf("%d",&key);
        root = insert(root, key);
        break ;
        
        case 2:
        printf("No. of leaf nodes :  \n");
        x = getLeafCount(root) ;
        printf("%d\n",x);
        break ;
        
        case 3:
        exit(0);
        break ;
        
        default :
        printf("Enter a valid choice !\n");
    }
  }
}
