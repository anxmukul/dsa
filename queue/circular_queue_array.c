#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef struct{
    int data[MAX];
    int front;
    int rear;
}QUEUE;

int insert(QUEUE *q,int v) {
	if(q->front==(q->rear+1)%MAX) {
		printf("Canot insert Queue Full\n");
		return 1;
	} 
	if(q->rear==-1 && q->front == -1) {
		q->rear=q->front=0;
		q->data[q->rear ]=v;
	}
	else {
		q->rear=(q->rear+1)%MAX;
		q->data[q->rear]=v;
	}
	return 0;
}
int delete(QUEUE *q,int *r) {
	if(q->front==-1) {
		printf("NOTHING TO DELETE\n");
		return 1;
	}
	if(q->front==q->rear) {     //only one element
		*r=q->data[q->front];
		q->front=q->rear=-1;
	}
	else {
		*r=q->data[q->front];
		q->front=(q->front+1)%MAX;
	}
	return 0;
}
void display(QUEUE *q){
    if(q->rear == q->front == -1){
        printf("Empty Queue\n");
    }
    else if(q->rear >= q->front ){
        printf("Queue is:\n");
        int i;
        for(i = q->front; i<= q->rear; i++){
            printf("%d ", q->data[i]);
        }
        printf("\n");
    }
    else{
         printf("Queue is:\n");
        for(int i = q->front; i< MAX; i++){
            printf("%d ", q->data[i]);
        }
        for(int i=0; i <= q->rear; i++){
            printf("%d", q->data[i]);
        }
        printf("\n");
    }
}
int main(){
    int p, q, m;
    QUEUE q1;
    q1.rear = q1.front = -1;
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
            delete(&q1, &m);
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