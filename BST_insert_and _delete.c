//INSERTION AND DELETION IN BINARY SEARCH TREE 

#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data ;
    struct node *left ;
    struct node *right ;
};

void inorder (struct node *);

struct node * minValueNode(struct node* node)
{
struct node* current = node;
while (current->left != NULL)
current = current->left;
return current;
}

struct node *delete_node (struct node*root , int data)
{
    if (root == NULL)
    {
    return root ;
    }
    
    if (data < root->data)
    {
        root->left = delete_node(root->left , data);
    }
    
    else if(data > root->data )
    {
        root->right = delete_node(root->right , data);
    }
    
    else
    {
        if(root->left == NULL)
        {
            struct node * temp = root -> right ;
            free(root);
            return temp;
        }
        
        else if(root -> right == NULL)
        {
            struct node *temp = root -> left ;
            free (root);
            return temp ;
        }
        
        struct node *temp = minValueNode (root->right);
        root->data = temp ->data ;
        root -> right = delete_node(root->right , temp->data);
    }
        return root ;
}


struct node *create ()
{
    int x ;
    struct node *newnode ;
    newnode = (struct node* )malloc(sizeof(struct node));
    printf("Enter data(-1 fo no node) : "); 
    scanf("%d",&x);
    
    if(x == -1)
    {
        return 0 ;
    }
    newnode -> data = x ;
    printf("Enter left child of %d\n",x);
    newnode -> left = create ();
    
    printf("Enter right child of %d\n",x);
    newnode->right = create ();
    return newnode ;
}

int main ()
{   int del_ele ;
    struct node * root ;
    root = 0 ;
    root = create () ;
    
    printf("\nInorder is : ");
    inorder (root);
    
    printf("\nEnter the node value you want to delete : ");
    scanf("%d",&del_ele);
    delete_node(root,del_ele);
    
    printf("\nInorder after del;etion : ");
    inorder (root);
}


void inorder (struct node *root)
{
    if(root == NULL)
    {
        return ;
    }
    inorder (root -> left);
    printf("%d ",root->data);
    inorder (root -> right);
}


