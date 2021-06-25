// Left view of binay tree is set of nodes visible when tree os visited from left side
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
int max_level = -1;
void leftViewUsingRecursion(node * root, int level){
	if (root == NULL) return;
 
    if (max_level < level)
    {
        cout << root->data << " ";
        max_level = level;
    }

    leftViewUsingRecursion(root->left, level + 1);
    leftViewUsingRecursion(root->right, level + 1);
}
vector <int> leftView(node *root){
	vector <int> lview;
	if(root == NULL){
		return lview;
	}
	vector <node *> temp;
	queue <node *> addressQueue;
	addressQueue.push(root);
	addressQueue.push(NULL);
	lview.push_back(root->data);
	while(!addressQueue.empty()){
		node *cur = addressQueue.front();
		addressQueue.pop();
		if(cur == NULL){
			if(temp.size()){						
				lview.push_back(temp.front()->data);
			}
			addressQueue.push(NULL);
			temp.clear();
			if(addressQueue.front() == NULL){
				break;
			}
			else{
				continue;
			}
			
		}
		if(cur->left != NULL ){
			addressQueue.push(cur->left);
			temp.push_back(cur->left);
		}
		if(cur->right != NULL ){
			addressQueue.push(cur->right);
			temp.push_back(cur->right);
		}
	}
	return lview;
}
int main()
{
    node *root = NULL;
    root = create_node(1);
    root->left = create_node(2);
    root->left->right = create_node(5);
    root->left->left = create_node(4);
    root->left->left->right = create_node(8);
    root->right = create_node(3);
    root->right->left = create_node(6);
    root->right->right = create_node(7);
    vector <int> left_view = leftView(root);
	for(auto i=left_view.begin(); i<left_view.end(); i++){
		cout<<*i<<" ";
	}
	cout<<"\n";
	leftViewUsingRecursion(root, 0);
	cout<<"\n";
}

