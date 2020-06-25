#include <stdio.h>
#include <stdlib.h>

typedef int element;

struct node {
    element val;
    node *l, *r;
};

typedef node *bst;

node *searchTree(bst tree, element el) {
    if (!tree) return NULL;
    if (tree->val == el) return tree;
    if (tree->val > el) return searchTree(tree->l, el);
    return searchTree(tree->r, el);
}

void insertn(bst *tree, node *no) {
    if ((*tree)->val > no->val) {
        if ((*tree)->l) insertn(&((*tree)->l), no);
        else (*tree)->l = no;
    } else {
        if ((*tree)->r) insertn(&((*tree)->r), no);
        else (*tree)->r = no;
    }
}

void insertTree(bst *tree, element el) {
    if (searchTree((*tree), el)) return;
    node *nn = (node *) malloc(sizeof(node));
    nn->val = el;
    nn->l = nn->r = NULL;
    if (!(*tree)) *tree = nn;
    else insertn(tree, nn);
}

bst deleteTree(bst *tree, element el) {
    if (!(*tree)) return *tree;
    if ((*tree)->val == el) {
        if ((*tree)->l) {
            node *t = (*tree)->l, *tt = (*tree);
            while (t->r) tt = t, t = t->r;
            if (tt != (*tree)) tt->r = t->l;
            if (tt != (*tree)) t->l = (*tree)->l;
            t->r = (*tree)->r;
            free(*tree);
            (*tree) = t;
        } else if ((*tree)->r) {
            node *t = (*tree)->r, *tt = (*tree);
            while (t->r) tt = t, t = t->l;
            if (tt != (*tree)) tt->l = t->r;
            t->l = (*tree)->l;
            if (tt != (*tree)) t->r = (*tree)->r;
            free(*tree);
            (*tree) = t;
        } else {
            free(*tree);
            (*tree) = NULL;
        }
    } else if ((*tree)->val > el) (*tree)->l = deleteTree(&((*tree)->l), el);
    else (*tree)->r = deleteTree(&((*tree)->r), el);
    return *tree;
}

void inorder(bst *tree) {
    if (!(*tree)) return;
    inorder(&((*tree)->l));
    printf("%d ", (*tree)->val);
    inorder(&((*tree)->r));
}

int main() {
    bst tree = NULL;
    insertTree(&tree, 20);
    insertTree(&tree, 13);
    insertTree(&tree, 35);
    insertTree(&tree, 30);
    insertTree(&tree, 17);
    insertTree(&tree, 20);
    insertTree(&tree, 10);
    insertTree(&tree, 33);
    insertTree(&tree, 40);
    insertTree(&tree, 15);
    insertTree(&tree, 19);
    inorder(&tree);
    printf("\n");
    deleteTree(&tree, 13);
    deleteTree(&tree, 30);
    deleteTree(&tree, 40);
    inorder(&tree);
    printf("\n");
}