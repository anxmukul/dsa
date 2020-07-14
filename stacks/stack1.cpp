#include <bits/stdc++.h>
using namespace std;
//#define max_size = 101
int a[10];
int top = -1;

void push(int x){
    if(top == 9){
        cout<<"Error: Stack Overflow";
        return;
    }
    top = top+1;
    a[top] = x;
}
void pop(){
    if(top == -1){
        cout<<"Stack is Empty.";
        return;
    }
    top = top-1;
}
int Top(){
    return a[top];
}
bool Isempty(){
    if(top == -1){
        cout<<"Empty -> ";
        return true;
    }
    else {
        cout<<"Empty -> ";
        return false;
    }
}
void Print(){
    int i=0;
    cout<<"Stack: ";
    for(i=0; i <= top; i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}
int main(){
    cout<<Isempty()<<"\n";
    push(2);
    Print();
    push(5);
    Print();
    push(15);
    Print();
    cout<<Isempty()<<"\n";
    pop();
    Print();
    push(55);
    Print();
    cout<<Top()<<"\n";
    return 0;
}



