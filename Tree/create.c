//Tree creation
#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
struct node *create_node(int v)
{
    struct node *cur;
    cur = (struct node *)malloc(sizeof(struct node));
    if (cur != NULL)
    {
        cur->left = cur->right = NULL;
        cur->data = v;
    }
    return cur;
}
void display_preorder(struct node *r)
{
    if (r != NULL)
    {
        printf("%d ", r->data);
        display_preorder(r->left);
        display_preorder(r->right);
    }
}
int main()
{
    struct node *root = NULL;
    root = create_node(4);
    root->left = create_node(9);
    root->left->right = create_node(2);
    root->left->left = create_node(3);
    root->left->left->right = create_node(1);
    root->right = create_node(8);
    root->right->left = create_node(7);
    root->right->right = create_node(6);
    display_preorder(root);
}