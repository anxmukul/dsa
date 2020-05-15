#include <bits/stdc++.h>
using namespace std;
struct Node{
int data;
Node* link;
};
int main(){
    cout<<"Lets start Linked list\n";
    Node* A;    // 
    A = NULL;   //Empty list 
    Node* temp = new Node();
    temp -> data = 2;
    temp -> link = NULL;
    A = temp;
    cout<<temp -> data<<"\n";
    cout<<A<<"\n";
    return 0;
}