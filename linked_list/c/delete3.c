#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;   //it is global because we are passing by value as argument in display fuction.

void create_double_circular_linkedlist(struct node **h){
    struct node *cur, *ptr;
    int n;
    printf("Enter the number of nodes\n");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        cur = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data in node:-\n");
        scanf("%d", &cur->data);
        cur->next = cur->prev = NULL;
        if(*h == NULL){
            (*h) = ptr = cur;
            cur -> next = cur;
            cur -> prev = cur;
        }else{
            cur -> prev = ptr;
            cur -> next = ptr -> next;
            ptr -> next = cur;
            (*h) -> prev = cur; // ptr -> prv = cur;
            ptr = cur;
        }
    }
    
}
void delete_a_node(struct node **h, int pos){
    struct node *ptr;
    if(*h == NULL){
        printf("Empty\n");
    }else{
        ptr = *h;
        int i = 1;
        while(i < pos && ptr -> next != *h){
            ptr = ptr->next;
            i++;
        }
        if(ptr -> next == *h && i<pos){
            printf("Node not found\n");
        }else if(ptr == *h && ptr->next == ptr){
            *h = NULL;
            free(ptr);
        }else if(ptr == *h){
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            (*h) = (*h)->next;
            free(ptr);
        }else{
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            free(ptr);
        }

    }
}
void display_all_elements(struct node *h){   
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
    create_double_circular_linkedlist(&head);
    display_all_elements(head); //if pass by reference was done then we can declare head node pointer in main fuction.
    delete_a_node(&head, 1);
    printf("After deleting 1st node\n");
    display_all_elements(head);
    delete_a_node(&head, 5);
    printf("After deleting 5th node\n");
    display_all_elements(head);
    delete_a_node(&head, 2);
    printf("After deleting 2nd node\n");
    display_all_elements(head);
    delete_a_node(&head, 7);
    printf("After deleting 7th node\n");
    display_all_elements(head);
}
