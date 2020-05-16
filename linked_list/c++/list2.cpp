// Linked list: Inserting a node at beginning.
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next; // Pointer variable storing address of next node.
};
Node* head; // Global variable store address of first node, can be accessed anywhere.
void Insert(int x){
        Node* temp = new Node();    // Creating a new node.
        temp -> data = x;           // storing the data.
        temp -> next = NULL;        // pointer variable next pointing nowhere.
        if(head != NULL){              
            temp -> next = head;
        }
        head = temp;
}
void Print(){
        Node* temp = head;      // local variable storing address of the head node initially.
        cout<<"List is: ";
        while (temp != NULL)    // traversing to next node
        {
            cout<<temp->data<<" ";
            temp = temp -> next;    // next node
        }
        cout<<"\n";      
}
int main(){
    head = NULL;    // Empty list, pointer variable point no where.
    cout<<"How many numbers?: \n";
    int n, i, x;
    cin>>n;
    cout<<"Enter the numbers: \n";
    for ( i = 0; i < n; i++)
    {
        cin>>x;
        Insert(x);
        Print();
    }
       

    return 0;
}
