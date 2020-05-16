// Linked list: Passing element and inserting in list.
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int value;
    Node* link;
};
Node* head;
int m;
void Insert(int x){
    //m = m+1;
    //cout<<m<<"\n";
    Node* temp = new Node();
    temp -> value = x;
    temp -> link = NULL;
    if(head == NULL){
        head = temp;
    }
    Node * temp1 = head;
    while(temp1 -> link != NULL){
         temp1 = temp1 -> link;
    }
    temp1  = temp;
}
void Print(){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp -> value<<" ";
        temp = temp -> link;
    }
    cout<<"\n";
}
int main(){
    head = NULL;
    cout<<"How many numbers?: \n";
    int n, i, x;
    cin>>n;
    cout<<"Enter the numbers: \n";
    for ( i = 0; i < n; i++)
    {
        cin>>x;
        Insert(x);
    }
    Print();
}