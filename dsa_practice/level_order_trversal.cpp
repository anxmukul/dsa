#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left;
	node *right;
};
node * insert(node *r, int v){
	if(r == NULL){
		node *cur = new node();
		cur->data = v;
		cur->left = NULL;
		cur->right = NULL;
	}
	else if(r->data < v){
		r->right = insert(r->right, v);	
		return r;	
	}
	else if(r->data > v){
		r->left = insert(r->left, v);
		return r;
	}
}
void levelOrderTraversal(struct node *r)
{
	if(r == NULL){
		return;
	}
	queue <node *> addressQueue;
	addressQueue.push(r);
	while(!addressQueue.empty()){
		node *cur = addressQueue.front();
		cout<<cur->data<<" ";
		if(cur->left != NULL ){
			addressQueue.push(cur->left);
		}
		if(cur->right != NULL ){
			addressQueue.push(cur->right);
		}
		addressQueue.pop();
	}
}
int main(){
	node *root = NULL;
	int r;
	cout<<"Inter root node\n";
	cin>>r;
	root = insert(root, r);
	int n;
	cout<<"Enter Number of element in binary_search_tree\n";
	cin>>n;
	cout<<"Enter elements one by one\n";
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		root = insert(root, temp);
	}
	levelOrderTraversal(root);
	cout<<endl;
	return 0;

}