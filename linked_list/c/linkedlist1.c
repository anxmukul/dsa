#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
int main(){
    struct node *cur;
    for (int i = 0; i < 5; i++)
    {
        cur = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &cur->data);
        cur -> next = NULL;
        cur -> prev = NULL;
        if(head == NULL){
            head = cur;
        }
        else{
            head->next = cur;
            cur -> prev = head -> prev;
        }
    }
    for ( cur = head; cur!= NULL; cur = cur->next)
    {
        printf("%d\n", cur->data);
    }
    struct node *ptr;
    ptr = head;
    for(int i=0; i<5; i++){
        ptr = head->next;
    }
}