#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef struct
{
    int data[MAX];
    int f;
    int r;
} QUEUE;
int insert(QUEUE *q, int v, int side)
{
    if (q->f == 0 && q->r == MAX - 1)
    {
        printf("FULL\n");
        return 1;
    }
    if (q->r == -1)
    {
        q->f = 0;
        q->f = 0;
        q->data[q->r] = v;
        return 0;
    }
    if (side == 1)
    {
        if (q->r != MAX - 1)
        {
            q->r++;
            q->data[q->r] = v;
        }
        else
        {
            for (int i = q->f; i <= q->r; i++)
            {
                q->data[i - 1] = q->data[i];
            }
            q->data[q->r] = v;
        }
        return 0;
    }
    if (side == 0)
    {
        if (q->f != 0)
        {
            q->f--;
            q->data[q->f] = v;
        }
        else
        {
            for (int i = q->r; i < q->f; i--)
            {
                q->data[i + 1] = q->data[i];
            }
            q->data[q->f] = v;
        }
        return 0;
    }
}
int delete (QUEUE *q, int *m, int side)
{
    if (q->f == q->r)
    {
        *m = q->data[q->f];
        q->f = -1;
        q->r == -1;
    }
    else if (side == 0)
    {
        *m = q->data[q->f];
        q->f++;
    }
    else
    {
        *m = q->data[q->r];
        q->r--;
    }
    return 0;
}
void display(QUEUE *q)
{
    printf("Queue is: ");
    for (int i = q->f; i <= q->r; i++)
    {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}
int main()
{
    int p, q, m;
    QUEUE q1;
    q1.r = q1.f = -1;
    printf("1. To Insert in queue\n2. To delete from queue\n3. To show Queue\n4. Enter 0 to exit\n");
    while(1>0){
        printf("Choose you number\n");
        int c, n, s;
        scanf("%d", &c);
        if(c == 1){
            printf("Enter data:\n");
            scanf("%d", &n);
            printf("Enter side\n");
            scanf("%d", &s);
            int k = insert(&q1, n, s);
        }
        else if(c == 2){
            printf("Enter side:\n");
            scanf("%d", &s);
            delete(&q1, &m, s);
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