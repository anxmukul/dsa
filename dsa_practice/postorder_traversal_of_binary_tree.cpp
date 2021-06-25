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
void postorderItterative(node *root){
	  stack<node*> s;
    s.push(root);
 
    // create another stack to store postorder traversal
    stack<int> out;
 
    // loop till stack is empty
    while (!s.empty())
    {
        // pop a node from the stack and push the data into the output stack
        node* curr = s.top();
        s.pop();
 
        out.push(curr->data);
 
        // push the left and right child of the popped node into the stack
        if (curr->left) {
            s.push(curr->left);
        }
 
        if (curr->right) {
            s.push(curr->right);
        }
    }
 
    // print postorder traversal
    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
	}
    
}
void postorderRecursive(node *r)
{
    if (r != NULL)
    {
		postorderRecursive(r->left);
        postorderRecursive(r->right);
		printf("%d ", r->data);
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
    postorderRecursive(root);
	cout<<endl;
	postorderItterative(root);
	cout<<"\n";
}

