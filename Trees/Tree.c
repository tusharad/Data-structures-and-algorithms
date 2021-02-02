#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *right;
    struct node *left;
} node;

node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d-> ", root->data);
    inorder(root->right);
}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d-> ", root->data);
    inorder(root->left);
    inorder(root->right);
}

void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    inorder(root->right);
    printf("%d-> ", root->data);
}

int isFullBinaryTree(node *root)
{
    if (root == NULL)
        return 1;
    if (root->left == NULL && root->right == NULL)
        return 1;
    if ((root->left) && (root->right))
        return (isFullBinaryTree(root->right) && isFullBinaryTree(root->left));
    return 0;
}

void main()
{
    node *root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(5);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    if (isFullBinaryTree(root))
        printf("It is full binary tree\n");
    else
        printf("It is not full binary tree\n");
}