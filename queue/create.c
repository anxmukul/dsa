#include <stdio.h>
#include <stdlib.h>
#define MAX 6
typedef struct{
    int data[MAX];
    int front;
    int rear;
}QUEUE;

int insert(QUEUE *q, int v){    // This function will return 0 if data inserted in queue
    if(q->rear == MAX-1){       // Else it will return 1
        printf("Error: Queue Full\n");
        return 1;
    }
    if(q->rear == -1){
        q->rear = 0;
        q->front = 0;
        q->data[q->rear] = v;

    }
    else{
        q->rear += 1;
        q->data[q->rear] = v;
    }
    return 0;
}
/*
int delete(QUEUE *q){     // IN this delete function we are changing front and top pointer 
    int res;
    if(q->rear == -1){           // But we are not deleting the data at front of array.
        printf("Empty Queue\n");
        return 1;
    }
    if(q->front == q->rear){
        printf("Total elements in queue\t%d\n", q->rear +1); 
        res = q->data[q->front];
        q->rear = q->front = -1;
        return res;
    }
    else{
        printf("Total elements in queue\t%d\n", q->rear +1); 
        printf("Front is at index\t%d\n", q->front);
        res = q->data[q->front];
        q->front++;
        return res;
    }
}
*/
int delete(QUEUE *q){     //Deleting element with keeping front fix
    int res;
    if(q->rear == -1){   
        printf("Total elements in queue\t%d\n", q->rear +1);           
        printf("Empty Queue\n");
        return 1;
    }
    else{
        printf("Total elements in queue\t%d\n", q->rear+1);
        res = q->data[q->front];
        for(int i=1; i <= q->rear; i++){
            q->data[i-1] = q->data[i];
        }
        q->rear -= 1;
        return res;
    }
}
void display(QUEUE *q){
    printf("Front is at index\t%d\n", q->front);
    for(int i = q->front; i<= q->rear; i++){
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main(){
    int p, q, m;
    QUEUE q1;
    q1.rear = q1.front = -1;
    p = insert(&q1, 5);
    printf("%d\n", p);
    p = insert(&q1, 2);
    printf("%d\n", p);
    p = insert(&q1, 8);
    printf("%d\n", p);
    p = insert(&q1, 1);
    printf("%d\n", p);
    display(&q1);
    m = delete(&q1);
    printf("Deleted data is\t%d\n", m);
    display(&q1);
}
