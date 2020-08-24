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
void display_all_element(struct node *head){
    struct node* p;
    printf("Data in the nodes are:-\n");
    for(p = head; p != NULL; p = p->next){
        printf("%d\n", p->data);
    }
}
void insert_a_node(struct node **h, int v, int pos){
    struct node *cur, *itr;
    cur = (struct node*)malloc(sizeof(struct node));
    cur->data = v;
    cur->next = NULL;
    if(*h == NULL){
        *h = cur;
    }else if(pos == 0){
        cur->next  = *h;
        *h = cur;
    }else{
        itr = *h;
        int i = 1;
        while (i<pos && itr->next != NULL)
        {
            itr = itr->next;
            i++;
        }
        cur->next = itr->next;
        itr->next = cur;
    }
}
int main(){
    create_linked_list();
    display_all_element(head);
    insert_a_node(&head, 45, 0);
    display_all_element(head);
    insert_a_node(&head, 10, 2);
    display_all_element(head);
    insert_a_node(&head, 9, 5);
    display_all_element(head);
    
}