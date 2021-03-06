//Converting infix expression to prefix.
#include <stdio.h>
#include <stdio.h>
#define MAX 30
typedef struct{
    char data[MAX];
    int top;
}STACK;
void push(STACK *, int);
void pop(STACK *, int *);
STACK s1;
void push(STACK *s, int v){
    if(s->top == MAX -1){
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->data[s->top] = v;
}
void pop(STACK *s, int *v){
    if(s->top == -1){
        printf("Stack Underflow\n");
        return;
    }
    *v = s->data[s->top];
    s->top--;
}
int get_v(char o){
    int t;
    switch(o){
        case '+':
        case '-':
            t = 1;
            break;
        case '*':
        case '/':
            t = 2;
            break;
        case '^':
            t = 3;
            break;
    }
    return t;
}
int is_operand(int c){
    if(c >= 65 && c <= 90 || c >= 97 && c <= 122){
        return 1;
    }
    else{
        return 0;
    }
}
int is_LtoH(char o1, char o2){
    if(get_v(o1) < get_v(o2))
        return 1;
    else
        return 0;
}
void infix_to_postfix(char *inp, char *out){
    int i=0, k=0;
    int m,n;
    while(inp[i] != '\0'){
    if(is_operand(inp[i])){
        out[k++] = inp[i];
        }
        else if(inp[i] == '('){
            push(&s1, inp[i]);
        }
        else if(inp[i] == ')'){
            while(1){
                pop(&s1, &m);
                if(m == '('){
                    break;
                }
                out[k++] = m;
            }
        }
        else{
            if(s1.top == -1){
                push(&s1, inp[i]);
            }
            else{
                pop(&s1,&n);
                if(n == '('){
                    push(&s1, n);
                    push(&s1, inp[i]);
                }
                else if(is_LtoH(n, inp[i])){
                    out[k++] = n;
                    continue; 
                }
                else{
                    push(&s1, n);
                    push(&s1, inp[i]);
                }
            }           
        }
        i += 1;
    }
    while(s1.top != -1){
        pop(&s1, &m);
        out[k++] = m;
    }
    out[k] = '\0';
}
int main(){
    s1.top = -1;
    char input[] = "a/b-k*(d-e*f+g)/p";
    int n = sizeof(input);
    char reverse_of_input[MAX];
    for(int i=0; i<n; i++){
        if(input[n-i-1] == '('){
            input[n-i-1] = ')';
        }
        else if(input[n-i-1] == ')'){
            input[n-i-1] = '(';
        }
        reverse_of_input[i] = input[n-i-1];
       // printf("%c\n", reverse_of_input[i]);
    }
    for(int i=0; i<n; i++){
        printf("%c", reverse_of_input[i]);
    }
    //printf("%s\n", reverse_of_input);
    char output[MAX];
    infix_to_postfix(reverse_of_input, output);
    printf("%s\n", output);
}
