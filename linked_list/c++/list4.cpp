//Linked list: Deleting a node at nth position.
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* head;
void Print(){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<"\n";
}

void Insert(int x, int n){
    Node* temp1 = new Node();   // creating a new node with variable name temp1
    temp1 -> data = x;
    temp1 -> next = NULL;       // initially pointing to nowhere.
    if(n == 1){
        temp1 -> next = head;   // actually this is indication null at this time head is also indicating to null.
        head = temp1;           // head store link for first node
        return;                 // return to main function;
    }
    Node* temp2 = head;
    for(int i=0; i< n-2; i++){
        temp2 = temp2 -> next;  // traversing to n-1th node to insert the data
    }
    temp1 -> next = temp2 -> next;  // linking one node to another
    temp2 -> next = temp1;
    
}
void Delete(int n){
    Node* temp1 = head;
    if(n == 1){
        head = temp1 -> next;
        free(temp1);
        return;
    }
    for(int i=0; i<n-2; i++){
        temp1 = temp1 -> next;  // points to n-1th node
        Node* temp2 = temp1 -> next;    //nth node
        temp1 -> next = temp2 -> next;
        free(temp2);
    }
}
int main(){
    head = NULL;
    Insert(2,1);
    Insert(4,2);
    Insert(16,3);
    Insert(76,4);
    Insert(29,5);
    Print();
    Delete(3);
    Print();
}