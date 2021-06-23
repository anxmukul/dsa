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
int BTheight(node *root){
	if(root == NULL){
		return 0;
	}
	int leftHeight = BTheight(root->left);
	int rightHeight = BTheight(root->right);
	if(leftHeight >= rightHeight){
		return leftHeight+1;
	}
	else{
		return rightHeight+1;
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
    cout<<BTheight(root)<<endl;
}

