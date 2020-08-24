#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;
void create_circular_linkedlist(struct node **h){
    struct node *cur = NULL, *ptr = NULL;
    int n;
    printf("Enter the number of nodes:-\n");
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        cur = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data for the node:\n");
        scanf("%d", &cur->data);
        if(*h == NULL){
            *h = cur;
            ptr = cur;
            ptr->next = *h;
        }else{
            cur->next = *h;
            ptr->next = cur;
            ptr = cur;
        }
    }
}
void display_all_element(struct node *h){
    struct node* p;
    if(h == NULL){
        printf("Empty List\n");
    }
    printf("Data in the nodes are:-\n");
    for(p = head; p->next != h; p = p->next){
        printf("%d\n", p->data);
    }
    printf("%d\n", p->data);    // for accessing the data of last node due to the exit condition
}
int main(){
    create_circular_linkedlist(&head);
    display_all_element(head);
    
}