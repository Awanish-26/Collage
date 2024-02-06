// #include <stdio.h>
// #include <malloc.h>
// #define height 10 // for this algorithm always use even value for height macro

// typedef struct node
// {
//     int data;
//     struct node *left;
//     struct node *right;
// } S;

// void CreateBinaryTree();
// void LinkNode();
// void traverse(int root);

// int h = 0;
// S *ptr[height];

// int ch, d;

// int main()
// {
//     CreateBinaryTree();
//     printf("Thanks for executing my code :-)\n");

//     return 0;
// }

// void CreateBinaryTree()
// {
//     do
//     {
//         if (h == height)
//             printf("Your binary tree has reached its max height.\n");
//         else
//         {
//             h++;
//             ptr[h] = (S *)malloc(sizeof(S));
//             if (ptr[h] == NULL)
//             {
//                 printf("Memory not created\n");
//             }
//             else
//             {
//                 printf("Enter a digit: ");
//                 scanf("%d", &d);
//                 ptr[h]->data = d;
//                 ptr[h]->left = NULL;
//                 ptr[h]->right = NULL;
//             }
//         }
//     } while (h < height);
//     LinkNode();
//     traverse(1);
// }

// void LinkNode()
// {
//     int mid = height / 2;
//     for (int i = 1; i <= mid; ++i)
//     {

//         ptr[i]->left = ptr[i * 2];
//         if (i * 2 + 1 > height)
//         {
//             ptr[i]->right = NULL;
//         }
//         else
//         {
//             ptr[i]->right = ptr[i * 2 + 1];
//         }
//     }
// }

// void traverse(int root)
// {
//     if (h == 0)
//     {
//         printf("Please create a tree before displaying it.\n");
//     }
//     else
//     {
//         printf("Your Binary Tree is:\n");
//         if (root <= h && ptr[root] != NULL)
//         {
//             printf("%d ", ptr[root]->data);
//             traverse(2 * root);
//             traverse(2 * root + 1);
//         }
//         printf("\n");
//     }
// }

// Tree traversal in C

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int item;
    struct node *left;
    struct node *right;
};

// Inorder traversal
void inorderTraversal(struct node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->item);
    inorderTraversal(root->right);
}

// Preorder traversal
void preorderTraversal(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->item);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder traversal
void postorderTraversal(struct node *root)
{
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->item);
}

// Create a new Node
struct node *create(int value)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->item = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert on the left of the node
struct node *insertLeft(struct node *root, int value)
{
    root->left = create(value);
    return root->left;
}

// Insert on the right of the node
struct node *insertRight(struct node *root, int value)
{
    root->right = create(value);
    return root->right;
}

int main()
{
    struct node *root = create(1);
    insertLeft(root, 4);
    insertRight(root, 6);
    insertLeft(root->left, 42);
    insertRight(root->left, 3);
    insertLeft(root->right, 2);
    insertRight(root->right, 33);

    printf("Traversal of the inserted binary tree \n");
    printf("Inorder traversal \n");
    inorderTraversal(root);

    printf("\nPreorder traversal \n");
    preorderTraversal(root);
    printf("\nPostorder traversal \n");
    postorderTraversal(root);
}
