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
    printf("\n");
}
struct node *create_node(int v)
{
    struct node *cur;
    cur = (struct node *)malloc(sizeof(struct node));
    if (cur != NULL)
    {
        cur->left = cur->right = NULL;
        cur->data = v;
    }
    return cur;
}
struct node * insert(struct node *r, int v){
    if(r == NULL){
        struct node *cur = (struct node *)malloc(sizeof(struct node));
        cur->left = cur->right = NULL;
        cur->data = v;
        return cur;
    }
    else if(r->data < v){
        r->right = insert(r->right, v);
        return r;
    }
    else if(r->data > v){
        r->left = insert(r->left, v);
        return r;
    }
}
int main(){
    struct node *root = NULL;
    root = create_node(35);
    root->right = create_node(70);
    root->right->right = create_node(71);
    root->right->left = create_node(45);
    root->right->left->right = create_node(63);
    root->right->left->right->left = create_node(50);
    root->right->left->right->left->right = create_node(54);
    root->left = create_node(20);
    root->left->left = create_node(10);
    root->left->right = create_node(29);
    root->left->right->right = create_node(31);
    root->left->right->right->left = create_node(30);
   Inorder(root);
   root = insert(root, 75);
   //Inorder(root);
   root = insert(root, 49);
   Inorder(root);
      
}