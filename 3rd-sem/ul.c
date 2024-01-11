#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} S;

S *CreateNode(int d);
S *insert(S *root, int d);
void traverse(S *root);

int main()
{
    S *root = NULL;
    int size, d;
    printf("Enter the number of nodes you want: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter the data: ");
        scanf("%d", &d);
        root = insert(root, d);
    }
    printf("Your BST is:\n");
    traverse(root);
    printf("\nThanks for executing my code :-)\n");
    return 0;
}

S *CreateNode(int d)
{
    S *n;
    n = (S *)malloc(sizeof(S));
    if (n == NULL)
        printf("Memory not created\n");
    else
    {
        n->data = d;
        n->left = NULL;
        n->right = NULL;
        return n;
    }
}

S *insert(S *root, int d)
{
    if (root == NULL)
    {
        return CreateNode(d);
    }
    else
    {
        if (d > root->data)
            root->right = insert(root->right, d);
        if (d < root->data)
            root->left = insert(root->left, d);
        if (d == root->data)
        {
            printf("Duplicate value cannot be inserted!!\n");
            printf("Enter another data to insert: ");
            scanf("%d", &d);
            if (d > root->data)
                root->right = insert(root->right, d);
            if (d < root->data)
                root->left = insert(root->left, d);
        }
        return root;
    }
}

void traverse(S *root)
{
    if (root != NULL)
    {

        traverse(root->left);
        printf("%d ", root->data);
        traverse(root->right);
    }
}