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
void delete_a_node(struct node **h, int pos){
    struct node *ptr;
    if(*h == NULL){
        printf("Empty list\n");
    }
    else
    {
        ptr = *h;
        int i = 1;
        while(i<pos && ptr != NULL){
            ptr = ptr->next;
            i++;
        }
        if(ptr == NULL){
            printf("Node not found\n");
        }
        else if(ptr == *h && ptr->next == NULL){
            printf("Sinle node deleted and list become empty.\n");
            *h = NULL;
            free(ptr);
        }
        else if(ptr == *h){
            (*h) = ptr->next;
            (*h)->prev = NULL;
            free(ptr);
        }
        else if(ptr -> next == NULL){
            ptr->prev->next = NULL;
            free(ptr);
        }else{
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            free(ptr);
        }
    }
    
}
int main(){
    create_double_linkedlist(&head);
    delete_a_node(&head, 0);
    display_all_element(head);
    delete_a_node(&head, 3);
    printf("After 3rd node deletion\n");
    display_all_element(head);
    delete_a_node(&head, 1);
    printf("After 1st node deletion\n");
    display_all_element(head);
    delete_a_node(&head, 9);  

}