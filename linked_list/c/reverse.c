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
void reverse(){
    printf("Reverse called:\n");
    struct node *cur, *prv, *far;
    cur = head;
    prv = NULL;
    while(cur != NULL){
        //printf("Inside while:");
        far = cur->next;
        cur->next = prv;
        prv = cur;
        cur = far;
    }
    head = prv;
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
    reverse();
    printf("Complete reverse:\n");
    display_all_element(head);
}