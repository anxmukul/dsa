//Circular queue using linked list data structure
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
typedef struct{
    struct node *rear;
    struct node *front;
}QUEUE;
int insert(QUEUE *q, int v){
    struct node *cur, *ptr;
    cur = (struct node*)malloc(sizeof(struct node));
    if(cur == NULL){
        printf("Memory full\n");
        return 1;
    }
    else{
        if(q->front == NULL){
            cur->data = v;
            cur->next = cur;
            q->rear = cur;
            q->front = cur;
        }
        else{
            cur->data = v;
            cur->next = q->rear->next;
            q->rear->next = cur;
            q->rear = q->rear->next;
        }
        return 0;
    }
}
void display(QUEUE *q){
    struct node *p;
    p = q->front;
    if(p == NULL){
        printf("Empty Queue");
        return;
    }
    printf("Queue is: ");
    for(p = q->front; p->next != q->front; p = p->next){
        printf("%d ", p->data);
    }
    printf("%d",p->data);
    printf("\n");
}
int delete(QUEUE *q){
    if(q->front == NULL){
        printf("Empty Queue\n");
        return 1;
    }
    else if(q->front == q->rear){
        free(q->front);
        return 0;
    }
    else{
        struct node *p, *first;
        for(p = q->front; p->next != q->front; p = p->next);
        first = q->front;
        q->front = first->next;
        p->next = q->front;
        free(first);
        return 0;
    }
}
int main(){
    QUEUE q1;
    q1.rear = NULL;
    q1.front = NULL;
    printf("1. To Insert in queue\n2. To delete from queue\n3. To show Queue\n4. Enter 0 to exit\n");
    while(1>0){
        printf("Choose you number\n");
        int c, n;
        scanf("%d", &c);
        if(c == 1){
            printf("Enter data:\n");
            scanf("%d", &n);
            int k = insert(&q1, n);
        }
        else if(c == 2){
            delete(&q1);
        }
        else if(c == 3){
            display(&q1);
        }
        else if(c == 0){
            break;
        }
        else{
            printf("Invalid input\n");
        }
    }

}