// creating sparse matrix
#include <stdio.h>
#include <stdlib.h>
struct node{
    int r;
    int c;
    int v;
    struct node *next;
};
void create(struct node **h){
    struct node *ptr;
    *h = (struct node *)malloc(sizeof(struct node));
    printf("Enter the details in header node:\n");
    scanf("%d%d%d", &(*h)->r, &(*h)->c, &(*h)->v);
    (*h)->next =NULL;
    ptr = *h;
    for(int i=0; i< (*h)->v; i++){
        struct node *cur;
        cur = (struct node *)malloc(sizeof(struct node));
        printf("Enter the details in node no %d\n", i+1);
        scanf("%d%d%d", &cur->r, &cur->c, &cur->v);
        cur->next = NULL;
        ptr->next = cur;
        ptr = cur;
    }
}
void display(struct node *h){
    struct node *ptr = h->next;
    printf("Sparse matrix is: \n");
    for(int i=0; i < h->v; i++){
        printf("%d %d %d\n",ptr->r,ptr->c,ptr->v);
        ptr=ptr->next;
    }
}
int main(){
    struct node *h1;
    h1 = NULL;
    create(&h1);
    display(h1);
}