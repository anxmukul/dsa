// Linked list: Inserting node at nth position
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;     // Pointer variable storing address of next node
};
Node* head;           // Global variable store address of first node, can be accessed anywhere.

void Insert(int data, int n){
    Node* temp1 = new Node();   // creating a new node with variable name temp1
    temp1 -> data = data;
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
void Print(){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<"\n";
}
int main(){
    head = NULL;    // Empty list, pointer variable point no where.
    Insert(5,1);    // calling insert function
    Insert(25,2);
    Insert(125,3);
    Insert(625,4);
    Insert(3125,3);
    Print();
    return 0;
    // you can change the position in insert argument and parameters as you even not serially.
}