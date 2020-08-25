//Deletion function in single circular linked list
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
void delete_a_node(struct node **h, int pos){
    struct node *ptr, *prv;
    int i=1;
    if(*h == NULL){
        printf("Empty List");
    }
    else{
        ptr = *h;
        while(i<pos && ptr->next != *h){
            prv = ptr;
            ptr = ptr ->next;
            i++;
        }
        if(ptr ->next == *h && i<pos){
            printf("Error:\tNode Not Found\n");
        }
        else if(ptr == *h && ptr->next == ptr){
            *h = NULL;
            free(ptr);
        }
        else if(ptr == *h){ //  first node deletion
            struct node *temp;  //  A temporary pointer at the last node.
            for(temp =*h; temp->next != *h; temp = temp->next);
            temp->next = (*h)->next;
            (*h) = (*h)->next;
            free(ptr);
        }
        else{
            prv->next = ptr->next;
            free(ptr);
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
    delete_a_node(&head, 1);
    printf("After deleting 1st node\n");
    display_all_element(head);
    delete_a_node(&head, 5);
    printf("After deleting 5th node\n");
    display_all_element(head);
    delete_a_node(&head, 2);
     printf("After deleting 2nd node\n");
     display_all_element(head);
}