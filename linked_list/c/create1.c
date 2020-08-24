#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
void create_double_linkedlist(struct node **h){
       struct node* cur;
        struct node* ptr = head;
    int n;
    printf("Enter the number of nodes:\n");
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        cur = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data in the node:\n");
        scanf("%d", &cur->data);
        cur->next = NULL;
        cur->prev = NULL;
        if(*h == NULL){
            *h = cur;
            ptr = cur;; 
        }else{
            ptr->next = cur;
            cur->prev = ptr;
            ptr = cur;
        }
    }
}
void display_all_element(struct node *head){
    struct node *p;
    printf("Data in the nodes are:-\n");
    for(p = head; p != NULL; p = p->next){
        printf("%d\n", p->data);
    }
}
void display_in_reverse_order(struct node *h){
    struct node *ptr;
    printf("Liat in reverse order:- \n");
    for(ptr = h; ptr->next != NULL; ptr = ptr->next);
    for(; ptr != NULL; ptr = ptr-> prev){
        printf("%d\n", ptr->data);
    }
}
int main(){
    create_double_linkedlist(&head);
    display_all_element(head);
    display_in_reverse_order(head);

}