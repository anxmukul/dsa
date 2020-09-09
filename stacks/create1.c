#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
    //struct node *top;
};
typedef struct{
    struct node *top;
}STACK;

int push(STACK *s, int v){
    struct node *cur;
    cur = (struct node*)malloc(sizeof(struct node));
    if(cur == NULL){
        printf("Error: Stack Overflow\n");
        return 1;
    }
    cur->data = v;
    cur->next = NULL;
    cur->next = s->top;
    s->top = cur;
    return 0;
}
int pop(STACK *s, struct node **v){
    struct node *ptr;
    if(s->top == NULL){
        printf("Stack Underflow\n");
        return 1;
    }
    ptr = s->top;
    s->top = s->top->next;
    *v = ptr;
    free(ptr);
    return 0;
}
int Top(STACK *s){
    if(s->top == NULL){
        printf("Empty Stack\n");
        return 1;
    }
    printf("%d\n", s->top->data);
    return 0;
}
void display(STACK *s){
    struct node *p;
    p = s->top;
    printf("Stack is: ");
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int main(){
    struct node *m;
    STACK s1;
    s1.top = NULL;
    printf("1. To push an element.\n2. To pop.\n3. TO get top element.\n4. To dispaly whole stack.\nPress 0 to exit.\n");
    while(1>0){
        printf("Choose you number\n");
        int c, n, k;
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
            int k = Top(&s1);
        }
        else if(c == 4){
            display(&s1);
        }
        else if(c == 0){
            break;
        }
        else{
            printf("Invalid input\n");
        }
    }
}