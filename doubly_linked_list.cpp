//
// Created by Seo_Hyun on 2020-05-21.
//

#include <stdio.h>
#include <stdlib.h>

typedef int element;

struct node {
    element val;
    node *prev, *next;
};
struct linkedList {
    node *head, *tail;
};

linkedList *createList() {
    linkedList *list = (linkedList *) malloc(sizeof(linkedList *));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void insertNode(linkedList *list, element val) {
    node *n = (node *) malloc(sizeof(node *));
    n->val = val;
    n->next = NULL;
    n->prev = NULL;
    if (!list->head) {
        list->head = n;
        list->tail = n;
    } else {
        node *p = list->head;
        while (p) {
            if (p->val < val) {
                n->next = p;
                n->prev = p->prev;
                p->prev = n;
                if (n->prev)n->prev->next = n;
                else list->head = n;
                return;
            }
            p = p->next;
        }
        list->tail->next = n;
        n->prev = list->tail;
        list->tail = n;
    }
}

void deleteNode(linkedList *list, element val) {
    node *p = list->head;
    while (p) {
        if (p->val == val) {
            if (list->head == p) list->head = p->next;
            if (list->tail == p) list->tail = p->prev;
            if (p->next) p->next->prev = p->prev;
            if (p->prev) p->prev->next = p->next;
            free(p);
            return;
        }
        p = p->next;
    }
}

int searchNode(linkedList *list, element val) {
    node *p = list->head;
    while (p) {
        if (p->val == val) return 1;
        p = p->next;
    }
    return 0;
}

void printList(linkedList *list) {
    node *p = list->head;
    printf("[ ");
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("]\n");
}

int main() {
    linkedList *list=createList();
    insertNode(list, 50);
    insertNode(list, 30);
    insertNode(list, 40);
    printf("%s\n", searchNode(list, 45)?"Yes":"No");
    insertNode(list, 45);
    printf("%s\n", searchNode(list, 45)?"Yes":"No");
    printList(list);
    deleteNode(list, 45);
    printList(list);
}