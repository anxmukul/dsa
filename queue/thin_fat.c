#include <stdio.h>
#include <stdlib.h>
#define MAX 20
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
        q->front++;
        for(int j=0; j<v; j++){
            q->rear ++;
            q->data[q->rear] = v;
        }
    }
    else{
        for(int j =0; j<v; j++){
            q->rear += 1;
            q->data[q->rear] = v;
        }
    }
    return 0;
}
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
        printf("%d\n", res);
        for(int k=0; k < res; k++){
            for(int i=1; i <= q->rear; i++){
                q->data[i-1] = q->data[i];
            }
            q->rear -= 1;
        }
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
    QUEUE q1;
    q1.rear = q1.front = -1;
    int n, v;
    printf("Enter number of testcases\n");
    scanf("%d", &n);
    while(n > 0){
        printf("Enter Number:\n");
        scanf("%d", &v);
        insert(&q1, v);
        n--;
    }
    display(&q1);
    delete(&q1);
    display(&q1);
    delete(&q1);
    display(&q1);
}