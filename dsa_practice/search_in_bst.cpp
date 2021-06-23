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
int searchNumber(node *root, int target){
	if(root == NULL){
		return 0;
	}
	if(root->data == target){
		return 1;
	}
	else if(root->data < target){
		return searchNumber(root->right, target);
	}
	else if(root->data > target){
		return searchNumber(root->left, target);
	}
	return 0;
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
	int target;
	cout<<"Enter target element\n";
	cin>>target;
	cout<<searchNumber(root, target)<<endl;;
	return 0;

}