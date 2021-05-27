#include "stdlib.h"
#include "stdio.h"

struct node {
        struct node *link;
        int data;
};

struct node* stack_init(void)
{
        struct node *p = malloc(sizeof(struct node));
        p->data = 3;
        p->link = p;
        return p;
}

void push(struct node **top, int data)
{
        struct node *p = malloc(sizeof(struct node));
        p->data = data;
        p->link = *top;
        *top = p;
}

void pop(struct node **top)
{
        struct node *old_top = *top;
        *top = old_top->link;
        old_top->link = NULL;
        free(old_top);
}

int peek(struct node *top)
{
        return top->data;
}

int main(void)
{       
        struct node *top = stack_init(); 
        push(&top, 1);
        int x = peek(top);
        push(&top, 2);
        x = peek(top);
        pop(&top);
        x = peek(top);
}