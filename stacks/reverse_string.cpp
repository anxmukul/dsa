//reversing string using array
#include <bits/stdc++.h>
#define MAX_SIZE 50
using namespace std;
class Stack{
    private:
    char c[MAX_SIZE];
    int top = -1;
    public:
    void push(char x){
        if(top == MAX_SIZE-1){
            cout<<"Error: Stack Overflow";
            return;
        }
        //cout<<"Push called\n";
        top = top+1;
        c[top] = x;
    }
    void pop(){
        top = top-1;
    }
    int Top(){
        return c[top];
    }
    //void reverse(char *arr, int s);
};
void reverse(char *arr, int s){
    Stack s1;
    //cout<<s<<endl;
    for(int i=0; i<s; i++){
       // cout<<arr[i];
        s1.push(arr[i]);
    }
    for(int i=0; i<s; i++){
        arr[i] = s1.Top();
        s1.pop();
    }
}
int main(){
    char arr[MAX_SIZE];
    cout<<"Enter any string: \n";
    cin.getline(arr, MAX_SIZE); 
    reverse(arr, strlen(arr));
    cout<<arr<<endl;
    return 0;
}