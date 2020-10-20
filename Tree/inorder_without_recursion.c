//Inorder without using recursion;
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
typedef struct{
    struct node * arr[MAX];
    int top;
}STACK;
struct node *create_node(int v)
{
    // printf("Node created\n");
    struct node *cur;
    cur = (struct node *)malloc(sizeof(struct node));
    if (cur != NULL)
    {
        cur->left = cur->right = NULL;
        cur->data = v;
    }
    return cur;
}
int push(STACK *s, struct node* v){
    if(s->top == MAX -1){
        printf("Stack Overflow\n");
        return 1;
    }
    s->top++;
    s->arr[s->top] = v;
    return 0;
}
int pop(STACK *s, struct node **v){
    if(s->top == -1){
        printf("Stack Underflow\n");
        return 1;
    }
    *v = s->arr[s->top];
    s->top--;
    return 0;
}
// int is_empty(STACK s){
//     if(s.top == -1){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
void Inorder(struct node *r){
    int k;
    struct node *m;
    STACK s1;
    s1.top = -1;
    struct node *temp = r;
    while (temp != NULL)
    {
        k = push(&s1, temp);
        temp = temp->left;
    }
    while (s1.top != -1)
    {
        k = pop(&s1, &m);
        printf("%d ", m->data);
        temp = m->right;
        while(temp != NULL){
            k = push(&s1, temp);
            temp = temp->left;
        }
    }  
}
int main()
{
    struct node *root = NULL;
    root = create_node(4);
    root->left = create_node(9);
    root->left->right = create_node(2);
    root->left->left = create_node(3);
    root->left->left->right = create_node(1);
    root->right = create_node(8);
    root->right->left = create_node(7);
    root->right->right = create_node(6);
    Inorder(root);
}