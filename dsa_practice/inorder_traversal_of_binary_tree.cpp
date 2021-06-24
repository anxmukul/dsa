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
void inorderItterative(node *root){
	if(root == NULL){
		return ;
	}
	stack <node *> s;
	node *cur = root, *temp;
	while (cur != NULL)
	{
		s.push(cur);
		cur = cur->left;
	}
	
	while(!s.empty()){
		temp = s.top();
		s.pop();
		cout<<temp->data<<" ";
		temp = temp->right;
		while (temp != NULL)			// we are doing same thing which we have done from line 26-30;
		{
			s.push(temp);
			temp = temp->left;
		}
	}
}
void inorderRecursive(node *r)
{
    if (r != NULL)
    {
		inorderRecursive(r->left);
        printf("%d ", r->data);
        inorderRecursive(r->right);
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
    inorderRecursive(root);
	cout<<endl;
	inorderItterative(root);
	cout<<"\n";
}

