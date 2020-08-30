// Creating stack using linked list
#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
};
struct node *top = NULL;
void push(int x){
    node *temp = new node();
    if(top == NULL){
        temp->data = x;
        top = temp;
        return;
    }
    temp->data = x;
    temp ->next = top;
    top = temp;
    //display();
}
void pop(){
    if(top == NULL){
        cout<<"Empty stack\n";
        return;
    }
    node *ptr;
    ptr = top;
    top = top->next;
    free(ptr);
    //display();
}
void top_element(){
    if(top == NULL){
        cout<<"Empty Stack\n";
    }
    cout<<"Top element is:-\n";
    cout<<top->data<<endl;
}
void length_of_the_stack(){
    node *ptr;
    int i = 0;
    for(ptr = top; ptr != NULL; ptr = ptr->next){
        i++;
    }
    cout<<"Length of the string is\t"<<i<<endl;
}
void display(){
    node *ptr = top;
    cout<<"Stack is: ";
    if(ptr == NULL){
        cout<<"Empty stack\n";
    }else if(ptr->next == NULL){
        cout<<ptr->data;
        //cout<<"\n";
    }else{
        for(ptr = top; ptr != NULL; ptr = ptr->next){
            cout<<ptr->data<<" ";
        }
    }
    cout<<endl;
}
int main(){
    push(4);
    display();
    push(6);
    display();
    push(9);
    display();
    pop();
    display();
    push(0);
    display();
    top_element();
    display();
    length_of_the_stack();
    return 0;
}