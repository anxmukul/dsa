//finding max and minimum element in BST
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
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
struct node * find_min(struct node *r){
       if(r == NULL){
        return r;
    }
    else if(r->left != NULL){
        return find_min(r->left);
    }
    else{
        return r;
    }
}
struct node * find_max(struct node *r){
    if(r == NULL){
        return r;
    }
    else if(r->right != NULL){
        return find_max(r->right);
    }
    else{
        return r;
    }
}
int main(){
    struct node *root = NULL;
    root = create_node(35);
    root->right = create_node(70);
    root->right->right = create_node(71);
    root->right->left = create_node(45);
    root->right->left->right = create_node(63);
    root->right->left->right->left = create_node(50);
    root->right->left->right->left->right = create_node(54);
    root->left = create_node(20);
    root->left->left = create_node(10);
    root->left->right = create_node(29);
    root->left->right->right = create_node(31);
    root->left->right->right->left = create_node(30);
   // Inorder(root);
    struct node *max = find_max(root);
    struct node *min = find_min(root);
    printf("Largest number in tree\t%d\n", max->data); 
    printf("Smallest number in tree\t%d\n", min->data);   
}