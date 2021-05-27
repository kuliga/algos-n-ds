#include "stdlib.h"
#include "stdio.h"

struct node {
        struct node *prev;
        int data;
        struct node *next;
};

// struct q

struct node* queue_init(void)//[3]
{
        // static int a[] = {1, 2, 3};
        // return &a;
        struct node *p = calloc(2, sizeof(struct node));
        return p;
}

// void 

#define HUJ(cipa) printf("" #cipa)

int main(void)
{
        HUJ(huj\n);
        struct node *end[2];
        end[0] = queue_init();
        end[1] = end[0] + sizeof(struct node);
        printf("%d\n", end[0]->data);

}