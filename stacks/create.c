#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct{
    int data[MAX];
    int top;
}STACK;
int push(STACK *s, int v){
    if(s->top == MAX -1){
        printf("Stack Overflow\n");
        return 1;
    }
    s->top++;
    s->data[s->top] = v;
    return 0;
}
int pop(STACK *s, int *v){
    if(s->top == -1){
        printf("Stack Underflow\n");
        return 1;
    }
    *v = s->data[s->top];
    s->top--;
    return 0;
}
int top(STACK *s){
    if(s->top == -1){
        printf("Stack Underflow\n");
        return 1;
    }
    printf("%d\n", s->data[s->top]);
    return 0;
}
int main(){
    STACK s1;
    s1.top = -1;
    printf("1. To push an element.\n2. To pop.\n3. TO get top element.\n4. Press 0 to exit.\n");
    while(1>0){
        printf("Choose you number\n");
        int c, n, k, m;
        scanf("%d", &c);
        if(c == 1){
            printf("Enter data:\n");
            scanf("%d", &n);
            int k = push(&s1, n);
        }
        else if(c == 2){
            int k = pop(&s1, &m);
        }
        else if(c == 3){
            int k = top(&s1);
        }
        else if(c == 0){
            break;
        }
        else{
            printf("Invalid input\n");
        }
    }
}