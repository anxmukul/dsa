#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head = NULL;
struct node* ptr = NULL;

void create_linked_list(){
    struct node* cur;
    //struct node* ptr;
    int n;
    printf("Enter the number of nodes:\n");
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        cur = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data in the node:\n");
        scanf("%d", &cur->data);
        cur->next = NULL;
        if(head == NULL){
            head = ptr = cur;
        }else{
            ptr->next = cur;
            ptr = cur;
        }
    }
}
void delete_a_node(struct node **h, int pos){    
    struct node *itr, *prv;
    if(*h == NULL){
        printf("Empty List\n");
    }else{
        itr = *h;
        int i = 1;
        while(i<pos && ptr != NULL){    // bringing prv pointer just before the node which has to be deleted
            prv = itr;
            itr = itr->next;
            i++;
        }   
    }
    if(itr == NULL){
        printf("ERROR: NOT FOUND\n");
    }else if(pos == 1){
        head = itr->next;
        free(itr);
    }else{
        prv->next = itr->next;
        free(itr);
    }
}
void display_all_element(struct node *head){
    struct node* p;
    printf("Data in the nodes are:-\n");
    for(p = head; p != NULL; p = p->next){
        printf("%d\n", p->data);
    }
}
int main(){
    create_linked_list();
    display_all_element(head);
    delete_a_node(&head, 1);
    printf("After deleting node at 1st position the list is:-\n");
    display_all_element(head);
    delete_a_node(&head, 3);
    printf("After deleting node at 3rd position list is:-\n");
    display_all_element(head);
    delete_a_node(&head, 5);
    printf("After deleting node at last position list is:-\n");
    display_all_element(head);
}