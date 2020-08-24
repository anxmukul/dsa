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
void insert_a_node(struct node **h, int v, int pos){
    struct node *cur, *ptr;
    cur = (struct node*)malloc(sizeof(struct node));
    cur -> data = v;
    cur->next = NULL;
    if(*h == NULL){
        *h = cur;
        cur->next = *h;
    }
    else if(pos == 0){
        for(ptr = *h; ptr-> next != *h; ptr = ptr->next);
        cur -> next = *h;
        ptr->next = cur;
        *h = cur;
    }else{
        ptr = *h;
        int i = 1;
        while (i<pos && ptr->next != NULL)
        {
            ptr = ptr->next;
            i++;
        }
        cur->next = ptr->next;
        ptr->next = cur;
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
    insert_a_node(&head, 5, 1);
    display_all_element(head);
    insert_a_node(&head, 34, 3);
    display_all_element(head);
    insert_a_node(&head, 45, 7);
    display_all_element(head);
    insert_a_node(&head, 7, 0);
    display_all_element(head);
}