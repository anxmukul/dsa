//Converting infix expression to postfix.
#include <stdio.h>
#include <stdio.h>
#define MAX 20
typedef struct{
    char data[MAX];
    int top;
}STACK;
STACK s1;
void push(STACK *s, int v){
    if(s->top == MAX -1){
        printf("Stack Overflow\n");
    }
    s->top++;
    s->data[s->top] = v;
}
void pop(STACK *s, int *v){
    if(s->top == -1){
        printf("Stack Underflow\n");
    }
    *v = s->data[s->top];
    s->top--;
}
int get_v(char o){
    int t;
    switch(o){
        case '+':
        case '-':
        t =1;
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
    if(65<= c >= 90){
        return 1;
    }
    else{
        return 0;
    }
}
int is_LtoH(char o1, char o2){
    if(get_v(o1) < get_v(o2)){
        return 1;
    }
    else{
        return 0;
    }
}
void infix_to_postfix(char *inp, char *out){
    int i=0, k=0;
    char m,n;
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
                if(m == "("){
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
                    push(&s1, n);
                    push(&s1, inp[i]);
                }
                else{
                    out[k++] = n;
                    i--;
                    continue;
                }
            }
        }
        i += 1;
    }
    while(s1.top != -1){
        pop(&s1, &m);
        out[k++] = m;
    }
}
int main(){
    s1.top = -1;
    char i[] = "a/b-k*(d-e*f+g)/p";
    char o[MAX];
    printf("%s", i);
    infix_to_postfix(i, o);
    printf("\n%s",o);
}
