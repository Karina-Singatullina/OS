#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int data;
    int key;
};

struct node *actual = NULL;
struct node *start = NULL;

void insert_node(int key, int data) {

    struct node *link;
    link = (struct node *) malloc(sizeof(struct node));
    link->key = key;
    link->data = data;
    link->next = start;
    start = link;
}

struct node* delete_node(int key) {

    struct node* actual = start;
    struct node* prev = NULL;

    if (start == NULL) {
        return NULL;
    }

    while(actual->key != key) {


        if(actual->next == NULL) {
            return NULL;
        } else {
            prev = actual;
            actual = actual->next;
        }
    }

    if(actual == start) {
        start = start->next;
    } else {
        prev->next = actual->next;
    }
    return actual;
}

void print_list() {

    struct node *p = start;
    while (p!= NULL) {
        printf(" %d;%d ", p -> key, p -> data);
        p = p -> next;
    }
}

void main() {
    insert_node(1,86);
    insert_node(2,10);
    insert_node(3,3);

    delete_node(2);

    insert_node(2, 16);

    delete_node(3);

    print_list();
}