//Program for checking wether the parentheses are balanced or not.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    char par;
    struct node *next;
};
typedef struct
{
    struct node *top;
} STACK;
int push(STACK *s, char v)
{
    struct node *cur;
    cur = (struct node *)malloc(sizeof(struct node));

    if (cur == NULL)
    {
        printf("Error: Stack Overflow\n");
        return 1;
    }
    cur->par = v;
    cur->next = NULL;
    cur->next = s->top;
    s->top = cur;

    return 0;
}
int pop(STACK *s)
{
    struct node *ptr;
    if (s->top == NULL)
    {
        printf("Unbalanced\n");
        return 1;
    }
    ptr = s->top;
    s->top = s->top->next;
    free(ptr);
    return 0;
}
void check(STACK *s)
{
    if (s->top != NULL)
    {
        printf("Unbalanced parantheses\n");
    }
    else
    {
        printf("Balanced\n");
    }
}
int main()
{
    STACK s1;
    s1.top = NULL;
    char p;
    int n;
    printf("Enter C if you want to check at the end\nPress E exit the program\n");
    printf("Enter the parentheses:\n");
    while (1 > 0)
    {
        scanf("%c", &p);
        if (p == '(')
        {
            int k = push(&s1, p);
        }
        else if (p == ')')
        {
            int k = pop(&s1);
            if (k == 1)
            {
                break;
            }
        }
        else if (p == 'C')
        {
            check(&s1);
        }
        else if (p == 'E')
        {
            break;
        }
        else
        {
            printf("Invalid Input\n");
        }
    }
}