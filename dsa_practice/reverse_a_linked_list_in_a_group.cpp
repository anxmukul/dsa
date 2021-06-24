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
node * reverseListIngroupOf(node * head, int k){
	if(head == 	NULL) return head;
	node *cur = head, *far = NULL, *prev= NULL;
	int count =0;
	while (cur != NULL && count < k) {
        far = cur->next;
        cur->next = prev;
        prev = cur;
        cur = far;
        count++;
    } 
	if (far != NULL)
        head->next = reverseListIngroupOf(far, k);
	return prev;
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
	int k;
	cout<<"enter value of k\n";
	cin>>k;
	struct node *rev = reverseListIngroupOf(head, k);
	printList(rev);
}