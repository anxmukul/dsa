#include <bits/stdc++.h>
using namespace std;
struct Node{
int data;
Node* link;
};
int main(){
    cout<<"Lets start Linked list\n";
    Node* A;    // pointer variable
    A = NULL;   //Empty list 
    Node* temp = new Node();    //creating new node in list
    temp -> data = 2;           // adding intiger in the list
    temp -> link = NULL;        // at this time as this the first and last node so link to next node contain null
    A = temp;                      //providing address of head node to the pointer variable A
    cout<<temp -> data<<"\n";
    //cout<<A<<"\n";
    //Adding 1 more node in list

    temp = new Node();          //creating a new node 2
    temp -> data = 4;
    temp -> link = NULL;        //initial address stored is null
    Node * temp1  = A;
    while(temp1 -> link != NULL){
        temp1 = temp1 -> link;
    }
    temp1 -> link = temp;       //link for temp1 stored in node 1
    cout<<temp -> data<<"\n"; 
    cout<<A<<"\n";
    cout<<temp -> link<<"\n";
    cout<<temp1 -> link<<"\n";

    // Adding 1 more node in list
    
    temp = new Node();
    temp -> data = 6;
    temp -> link = NULL;
    Node* temp2 = A;
    while (temp2 -> link != NULL)
    {
        temp2 = temp2 -> link;
    }
    temp2 -> link =  temp;
    cout<<temp -> data<<"\n";
    cout<<temp2 -> link<<"\n";

    return 0;
}