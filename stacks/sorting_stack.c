#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int data;
    struct Stack *next;
} *input = NULL, *tmpStack = NULL;
void push(struct Stack **st, int x)
{
    struct Stack *t;
    t = (struct Stack *)malloc(sizeof(struct Stack));
    if (st == NULL)
    {
        printf("Stack is full \n");
    }
    else
    {
        t->data = x;
        t->next = *st;
        *st = t;
    }
}
int pop(struct Stack **st)
{
    struct Stack *t;
    t = (struct Stack *)malloc(sizeof(struct Stack));
    ;
    int x;
    if (st == NULL)
    {
        printf("stack is empty");
    }
    else
    {
        t = *st;
        *st = (*st)->next;
        x = t->data;
        free(t);
    }
    return x;
}
void display(struct Stack *st)
{
    struct Stack *p;
    p = st;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
void sort()
{
    while (input)
    {
        int temp = pop(&input);
        while (tmpStack && tmpStack->data < temp)
        {
            push(&input, pop(&tmpStack));
        }
        push(&tmpStack, temp);
    }
}
void recursuion()
{
    while (input)
    {
        int temp = pop(&input);
        push(&tmpStack, temp);
    }
}

void clone()
{
    while (tmpStack)
    {
        int temp = pop(&tmpStack);
        push(&input, temp);
    }
}
int main()
{
    int n;
    printf("Enter number of elements in stack:\n");
    scanf("%d", &n);
    printf("Enter %d elements of stack:\n", n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        push(&input, a);
    }
    printf("Original Stack: ");
    display(input);
    sort();
    printf("Sorted Stack: ");
    display(tmpStack);
    /* recursuion();
 display(tmpStack);
 clone();
 display(input);
*/
    return 0;
}