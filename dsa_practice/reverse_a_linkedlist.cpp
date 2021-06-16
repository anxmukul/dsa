#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *next;
};
struct node *head = NULL;
void createList(int n){
	struct node * cur = new node();
	cur->data = n;
	cur->next = NULL;
	if(head == NULL){
		head = cur;
		return;
	}
	else{
		struct node *temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp ->next = cur;
	}
}
void printList(struct node *temp){
	while(temp != NULL){
		cout<<temp->data<<"->";
		temp = temp->next;	
	}
	cout<<endl;
}
void reverseList(){
	struct node *cur, *prev, *far;
	cur = head;
	prev = NULL;
	while(cur != NULL){
		far = cur->next;
		cur->next = prev;
		prev = cur;
		cur = far;
	}
	head = prev;
}
int main(){
	int n,element;
	cout<<"Enter number of nodes\n";
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>element;
		createList(element);
	}
	printList(head);
	reverseList();
	printList(head);
}