//Addition of two sparse matrix
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
void add(struct node *h1, struct node *h2, struct node **h){
    struct node *ptr, *p1, *p2, *temp;
    if(!(h1->r == h2->r && h1->c == h2->c)){
        return;
    }
    *h = (struct node *)malloc(sizeof(struct node));
    (*h)->r = (h1)->r;
    (*h)->c = (h1)->c;
    (*h)->v = (h1)->v + (h2)->v;
    ptr = *h;
    for(p1 = h1->next; p1 != NULL; p1=p1->next){
        struct node *cur;
        cur = (struct node*)malloc(sizeof(struct node));
        cur->r = p1->r;
        cur->c = p1->c;
        cur->v = p1->v;
        ptr->next = cur;
        ptr = cur;
    }
    for(p2 = h2->next; p2 != NULL; p2=p2->next){
        struct node *cur;
        cur = (struct node*)malloc(sizeof(struct node));
        cur->r = p2->r;
        cur->c = p2->c;
        cur->v = p2->v;
        ptr->next = cur;
        ptr = cur;
    }
    for(p1 = (*h)->next; p1 != NULL; p1 = p1->next ){
        temp = p1;
        p2 = p1->next;
        while(p2 != NULL){
            if(p1->r == p2->r && p1->c == p2->c){
                p1->v = p1->v + p2->v;
                temp -> next = p2->next;
                free(p2);
                p2 = temp;
            }
            temp = p2;
            p2 = p2->next;
        }
    }   
}
int main(){
    struct node *h1, *h2, *h3;
    h1 = NULL;
    create(&h1);
    create(&h2);
    printf("1st ");
    display(h1);
    printf("2nd ");
    display(h2);
    add(h1,h2,&h3);
    printf("After addition ");
    display(h3);
}