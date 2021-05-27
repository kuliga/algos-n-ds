#include "stdlib.h"
#include "stdio.h"
#include "stdint.h"

struct node {
        struct node *next;
        int val;
};

void print_elements(struct node *p)
{
        //walk the list
        while (p != NULL) {
                printf("\n%d", p->val);
                p = p->next;
        }
}

//insert node functions
void push_list_entry(struct node **head, int val)
{
        //allocate memory for a new node
        struct node *p = malloc(sizeof(struct node));
        //initialize new node
        p->next = *head;
        p->val = val;
        //new node is head now
        *head = p;
}

void insert(struct node* prev, int val)
{
        if (prev == NULL)
                return;
        
        //allocate memory for a new node 
        struct node *p = malloc(sizeof(struct node));
        //initiliaze new node
        p->next = prev->next;
        p->val = val;
        //change previous node
        prev->next = p;
}

void insert_list_entry(struct node *head, int seek_val, int val)
{
        struct node *i = head;
        while (i->val != seek_val)
                i = i->next;
        insert(i, val);
}

void append_list_entry(struct node *head, int val)
{
        //allocate memory for a new node
        struct node *p = malloc(sizeof(struct node));
        //initialize node
        p->val = val;
        p->next = NULL;
        //indirect pointer
        struct node *i = head;
        //no entry yet
        if (i == NULL) {
                i = p;
                return;
        }
        //walk the list
        while (i->next != NULL)
                i = i->next;
        i->next = p;
        
}

//delete node functions
int remove_list_entry(struct node *head, int val)
{
        struct node *i = head;
        struct node *prev = NULL;

        //walk the list
        while (i->val != val && i != NULL) {
                prev = i;
                i = i->next;
        }
        //no such entry
        if (i == NULL)
                return -1;
        
        prev->next = i->next;
        free(i);
        return 0;
}

void remove_list(struct node **head)
{
        struct node *i = *head;
        struct node *next;
        while (i->next != NULL) {
                next = i->next;
                free(i);
                i = next;
        }
        i = NULL;
}