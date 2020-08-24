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
void insert_a_node(struct node **h, int v, int pos){
    struct node *cur, *ptr;
    cur = (struct node*)malloc(sizeof(struct node));
    cur -> data = v;
    cur->next = cur->prev = NULL; 
    if(*h == NULL){     
    }else if(pos == 0){
        cur->next = *h;
        (*h)->prev = cur;
        (*h) = cur;
    }else
    {
        ptr = *h;
        int i = 1;
        while(i<pos && ptr -> next != NULL){
            ptr = ptr->next;
            i++;
        }
        if(ptr->next == NULL){
            cur->prev = ptr;
            ptr->next = cur;
        }else{
            cur->prev = ptr;
            cur->next = ptr->next;
            ptr->next = cur;
            cur->next->prev = cur;
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
int main(){
    create_double_linkedlist(&head);
    display_all_element(head);
    insert_a_node(&head, 4, 0);
    display_all_element(head);
    insert_a_node(&head, 56, 3);
    display_all_element(head);
    insert_a_node(&head, 9, 7);
    display_all_element(head);

}