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
int height(node *root){
	if(root == NULL){
		return 0;
	}
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	if(leftHeight >= rightHeight){
		return leftHeight+1;
	}
	else{
		return rightHeight+1;
	}
}
int diameter(node *root){
	if(!root){
		return 0;
	}
	int lHeight = height(root->left);
	int rHeight = height(root->right);
	int lDiameter = diameter(root->left);
	int rDiameter = diameter(root->right);
	return max(lHeight+rHeight+1, max(lDiameter, rDiameter));	

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
	cout<<diameter(root)<<"\n";
}

// To concept ye h ki agar height jayada ho raha h diameter se to height aage badha de rahe h 
// taki ye pata chale ki idhar se koi leaf node uthawoge to wo jayada distance pe h 
