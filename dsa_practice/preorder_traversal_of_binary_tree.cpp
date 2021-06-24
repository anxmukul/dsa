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
void preorderItterative(node *root){
	if(root == NULL){
		return ;
	}
	stack <node *> s;
	s.push(root);
	node *temp;
	while(!s.empty()){
		temp = s.top();
		cout<<temp->data<<" ";
		s.pop();
		if(temp -> right != NULL){
			s.push(temp->right);
		}
		if(temp -> left != NULL){
			s.push(temp->left);
		}
	}
}
void preorderRecursive(node *r)
{
    if (r != NULL)
    {
        printf("%d ", r->data);
        preorderRecursive(r->left);
        preorderRecursive(r->right);
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
    preorderRecursive(root);
	cout<<endl;
	preorderItterative(root);
	cout<<"\n";
}

