//
// Created by Seo_Hyun on 2020-05-18.
//

#include <stdio.h>
#include <stdlib.h>

typedef int element;

struct node {
    element val;
    node *next;
};

struct linkedList {
    node *head;
};

linkedList *createList() {
    linkedList *list = (linkedList *) malloc(sizeof(linkedList *));
    list->head = NULL;
    return list;
}

void insertNode(linkedList *list, element val) {
    node *n = (node *) malloc(sizeof(node *));
    n->val = val;
    n->next = NULL;
    if (!list->head) list->head = n;
    else {
        node *p = NULL, *q = list->head;
        while (q) {
            if (q->val > val) {
                n->next = q;
                if (!p) list->head = n;
                else p->next = n;
                return;
            }
            p = q;
            q = q->next;
        }
        p->next = n;
    }
}

void deleteNode(linkedList *list, element val) {
    node *p = NULL, *q = list->head;
    while (q) {
        if (q->val == val) {
            if (!p) list->head = q->next;
            else p->next = q->next;
            free(q);
            return;
        }
        p = q;
        q = q->next;
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

node *reverseDfs(node *n) {
    if (!n) return NULL;
    node *t = reverseDfs(n->next);
    if (!t) t = n;
    if (n->next) n->next->next = n;
    return t;
}

void reverse(linkedList *list) {
    if (!list->head) return;
    node *t = reverseDfs(list->head);
    list->head->next = NULL;
    list->head = t;
}

int main() {
    linkedList *list = createList();
    insertNode(list, 30);
    insertNode(list, 60);
    insertNode(list, 40);
    insertNode(list, 20);
    printList(list);
    deleteNode(list, 20);
    insertNode(list, 10);
    printf("%d\n", searchNode(list, 40));
    printf("%d\n", searchNode(list, 15));
    printList(list);
    reverse(list);
    printList(list);
}