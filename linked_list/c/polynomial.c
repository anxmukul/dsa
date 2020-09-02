#include <stdio.h>
#include <stdlib.h>
struct node{
    int cof;
    int exp;
    struct node *next;
};
void create(struct node **h){
    struct node *cur, *ptr;
    int n;
    printf("Enter the number of node according to the polynomial:\n");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        cur = (struct node *)malloc(sizeof(struct node));
        cur->next = NULL;
        printf("Enter the coefficient and exponent of node %d:\n", i+1);
        scanf("%d%d", &cur->cof, &cur->exp);
        if(*h == NULL){
            *h = cur;
        }
        else{
            for(ptr = *h; ptr->next != NULL; ptr = ptr->next);
            ptr->next = cur;
            ptr = cur;
        }
    }

}
void display(struct node *head){
    struct node* p;
    printf("Coefficient with respective exponent are:-\n");
    for(p = head; p != NULL; p = p->next){
        printf("%d\t%d\n", p->cof, p->exp);
    }
}
void join(struct node **head1, struct node *head2){
    struct node *ptr;
    if(*head1 == NULL){
        *head1 = head2;
        return;
    }
    for(ptr = *head1; ptr->next != NULL; ptr = ptr->next);
    ptr->next = head2;
}
void simplify(struct node *h){
    struct node *ptr, *prv, *ptr1;
    for(ptr = h; ptr != NULL; ptr = ptr ->next){
        prv = ptr;
        ptr1 = ptr->next;
        while(ptr1 != NULL){
            if(ptr->exp == ptr1->exp){
                ptr->cof = (ptr->cof) + (ptr1->cof);
                prv->next = ptr1->next;
                free(ptr);
                ptr1 = prv; // mast line h re baba
            }
            prv = ptr1;
            ptr1 = ptr1->next;
        }
    }
}
int main(){
    struct node *h1 = NULL, *h2 = NULL;
    create(&h1);
    display(h1);
    create(&h2);
    display(h2);
    join(&h1, h2);
    printf("After joining the polynomial become:\n");
    display(h1);
    simplify(h1);
    //display(h1);
}