//reversing a sting using stack imolemented throiugh linked list.
#include <bits/stdc++.h>
#define MAX_SIZE 50
using namespace std;
struct node{
    char data;
    node *next;
};
struct node *head = NULL;
class Stack{
    private:
    struct node *arr[MAX_SIZE];
    int top = -1;
    public:
    void push(struct node *c){
        if(top == MAX_SIZE-1){
            cout<<"Error: Stack Overflow";
            return;
        }
        //cout<<c<<endl;
        top = top+1;
        arr[top] = c;
    }
    void pop(){
        top = top-1;
    }
    node *Top(){
        return arr[top];
    }
    bool empty(){
        if(head == NULL){
            return true;
        }
    }
};
void create_linked_list(char *c, int n){
    struct node* cur, *ptr;
    for(int i=0; i<n; i++){
        cur = (struct node*)malloc(sizeof(struct node));
        cur->data = c[i];
        cur->next = NULL;
        if(head == NULL){
            head = ptr = cur;
        }else{
            ptr->next = cur;
            ptr = cur;
        }
    }
}
void reverse(){
    Stack s;
    struct node *temp = head;
    while(temp != NULL){
        s.push(temp);
        temp = temp->next;
    }
    temp = s.Top();
    head = temp;
    s.pop();
    while(!s.empty()){
        temp->next = s.Top();
        cout<<temp->next;
        s.pop();
        temp = temp->next;
    }
}
void display_string(){
    struct node* p;
    printf("String is:-\n");
    for(p = head; p != NULL; p = p->next){
        printf("%c", p->data);
    }
    cout<<endl;
}
int main(){
    char arr[MAX_SIZE];
    cout<<"Enter any string: \n";
    cin.getline(arr, MAX_SIZE); 
    create_linked_list(arr, strlen(arr));
    display_string();
    reverse();
    display_string();
    return 0;
}