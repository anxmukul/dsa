#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next;
};
node *head = NULL;
void insert_in_list(int n){
	node *temp = new node();
	temp->data = n;
	temp->next = NULL;
	if(head == NULL){
		head = temp;
	}
	else{
		node *temp1 = head;
		while(temp1 -> next != NULL){
			temp1 = temp1->next;
		}
		temp1->next = temp;
	}
}
void printList(){
	node *temp = head;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}
int main(){
	int total;
	cout<<"Enter number of list\n";
	cin>>total;
	cout<<"Enter each element in next line\n";
	for(int i=0; i<total; i++){
		int x;
		cin>>x;
		insert_in_list(x);
	}
	printList();
}
