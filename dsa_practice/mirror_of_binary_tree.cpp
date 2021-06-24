#include <bits/stdc++.h>
using namespace std;
struct node
{
    node *left;
    int data;
    node *right;
};
node *create_node(int v)
{
    node *cur = new node();
    if (cur != NULL)
    {
        cur->left = cur->right = NULL;
        cur->data = v;
    }
    return cur;
}
node * mirrorOfBinaryTree(node *root){
	node *temp;
	if(root){
		mirrorOfBinaryTree(root->left);
		mirrorOfBinaryTree(root->right);
		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
	return root;
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
    node *root = NULL;
    root = create_node(4);
    root->left = create_node(9);
    root->left->right = create_node(2);
    root->left->left = create_node(3);
    root->left->left->right = create_node(1);
    root->right = create_node(8);
    root->right->left = create_node(7);
    root->right->right = create_node(6);
	root->right->right->left = create_node(45);
	display_preorder(root);
	cout<<"\n";
    node *res = mirrorOfBinaryTree(root);
	display_preorder(res);
	cout<<"\n";
}

