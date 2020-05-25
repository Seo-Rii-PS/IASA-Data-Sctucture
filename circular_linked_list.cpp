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

void updateHeadLink(linkedList *list) {
    node *p = list->head->next, *q = list->head->next->next;
    while (q != list->head->next && q != list->head) {
        p = q;
        q = q->next;
    }
    if (q == list->head) return;
    p->next = list->head;
}

node *getLastNode(linkedList *list) {
    node *p = list->head;
    while (p->next != list->head) p = p->next;
    return p;
}

void insertNode(linkedList *list, element val) {
    int fl = 1;
    node *n = (node *) malloc(sizeof(node *));
    n->val = val;
    n->next = n;
    if (!list->head) list->head = n;
    else {
        node *p = NULL, *q = list->head;
        while (q != list->head || fl) {
            fl = false;
            if (q->val < val) {
                n->next = q;
                if (!p) list->head = n;
                else p->next = n;
                updateHeadLink(list);
                return;
            }
            p = q;
            q = q->next;
        }
        p->next = n;
        n->next = list->head;
    }
}

void deleteNode(linkedList *list, element val) {
    node *p = NULL, *q = list->head;
    while (q) {
        if (q->val == val) {
            if (!p) list->head = q->next;
            else p->next = q->next;
            //free(q);
            return;
        }
        p = q;
        q = q->next;
    }
}

int searchNode(linkedList *list, element val) {
    node *p = list->head;
    int fl = 1;
    while (p != list->head || fl) {
        fl = 0;
        if (p->val == val) return 1;
        p = p->next;
    }
    return 0;
}

void printList(linkedList *list) {
    node *p = list->head;
    printf("[ %d ", p->val);
    p = p->next;
    while (p != list->head) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("]\n");
}

node *reverseDfs(node *n, node *fin, int fl) {
    if (n == fin && fl) return NULL;
    node *t = reverseDfs(n->next, fin, 1);
    if (!t) t = n;
    if (n->next != fin) n->next->next = n;
    return t;
}

void reverse(linkedList *list) {
    if (!list->head) return;
    node *t = reverseDfs(list->head, list->head, 0);
    if (!t) t = list->head;
    list->head->next = t;
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