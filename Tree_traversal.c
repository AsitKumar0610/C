#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data ;
    struct node *left ;
    struct node *right ;
};

void preorder (struct node *);
int inorder (struct node *);
void postorder(struct node *);

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
{   
    struct node * root ;
    root = 0 ;
    root = create () ;
    printf("Preorder is : ");
    preorder (root);
    printf("\nInorder is : ");
    inorder (root);
    printf("\nPostorder is :");
    postorder(root);
}

void preorder (struct node *root)
{
    if (root == 0)
    {
        return ;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

int inorder (struct node *root)
{
    if(root == NULL)
    {
        return 0 ;
    }
    inorder (root -> left);
    printf("%d ",root->data);
    inorder (root -> right);
}

void postorder(struct node *root)
{
    if ( root == NULL)
    {
        return ;
    }
    postorder(root -> left);
    postorder(root -> right);
    printf("%d ",root->data);
}
