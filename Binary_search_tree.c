#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *left, *right;
};

struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);

    printf("%d -> ", root->key);

    inorder(root->right);
  }
}

struct node *insert(struct node *node, int key) {
  if (node == NULL) return newNode(key);

  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

struct node *minValueNode(struct node *node) {
  struct node *current = node;

  while (current && current->left != NULL)
    current = current->left;

  return current;
}

struct node *deleteNode(struct node *root, int key) {
  if (root == NULL) return root;

  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    struct node *temp = minValueNode(root->right);

    root->key = temp->key;

    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

int main() {
    
    struct node *root = NULL ;
    
    int key , i , n , ch ;
    while(ch != 4)
    {
    printf("Enter your choice : \n");
    printf("1.Insert\n");
    printf("2.Delete\n");
    printf("3.Display\n");
    printf("4.Exit\n");
    
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        printf("Enter the key to insert: \n");
        scanf("%d",&key);
        root = insert(root, key);
        break ;
        
        case 2:
        printf("Enter the key to delete :  \n");
        scanf("%d",&key);
        root = deleteNode(root , key);
        printf("Key deleted successfully !\n");
        break ;
        
        case 3 :
        printf("Inorder traversal .....\n");
        inorder(root);
        break ;
        
        case 4:
        exit(0);
        break ;
    }
  }
}
