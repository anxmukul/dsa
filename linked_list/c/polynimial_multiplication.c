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
void simplify(struct node *h){
    struct node *ptr, *prv, *ptr1;
    for(ptr = h; ptr != NULL; ptr = ptr ->next){
        prv = ptr;
        ptr1 = ptr->next;
        while(ptr1 != NULL){
            if(ptr->exp == ptr1->exp){
                ptr->cof = (ptr->cof) + (ptr1->cof);
                prv->next = ptr1->next;
                free(ptr1);
                ptr1 = prv; // mast line h re baba
            }
            prv = ptr1;
            ptr1 = ptr1->next;
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
void multiplication(struct node *h1, struct node *h2, struct node **h3){
    struct node *p1, *p2, *cur, *ptr;
    for(p1=h1; p1!= NULL; p1 = p1->next){
        for(p2 = h2; p2 != NULL; p2 = p2->next){
            cur = (struct node*)malloc(sizeof(struct node));
            cur->cof = (p1->cof)*(p2->cof);
            cur->exp = (p1->exp) + (p2->exp);
            cur->next = NULL;
            if(*h3 == NULL){
                (*h3) = ptr = cur;
            }
            else{
                ptr->next = cur;
                ptr = cur;
            }
        }
    }
}
int main(){
    struct node *h1 = NULL, *h2 = NULL, *h3 = NULL;
    create(&h1);
    display(h1);
    create(&h2);
    display(h2);
    multiplication(h1, h2, &h3);
    simplify(h3);
    display(h3);

}