#include <stdio.h>
#include <stdlib.h>

typedef int element;

struct node {
    element val;
    node *l, *r;
};

typedef node *bst;

int heightTree(bst *tree) {
    if (!(*tree)) return 0;
    int p = heightTree(&((*tree)->l)), q = heightTree(&((*tree)->r));
    return p > q ? p + 1 : q + 1;
}

node *searchTree(bst tree, element el) {
    if (!tree) return NULL;
    if (tree->val == el) return tree;
    if (tree->val > el) return searchTree(tree->l, el);
    return searchTree(tree->r, el);
}

void rotateClockwise(bst *tree) {
    bst org = *tree, orgl = org->l, orglr = org->l->r;
    (*tree) = orgl;
    (*tree)->r = org;
    (*tree)->r->l = orglr;
}

void rotateCounterClockwise(bst *tree) {
    bst org = *tree, orgr = org->r, orgrl = org->r->l;
    (*tree) = orgr;
    (*tree)->l = org;
    (*tree)->l->r = orgrl;
}

bst insertn(bst *tree, node *no) {
    if ((*tree)->val > no->val) {
        if ((*tree)->l) (*tree)->l = insertn(&((*tree)->l), no);
        else (*tree)->l = no;
    } else {
        if ((*tree)->r) (*tree)->r = insertn(&((*tree)->r), no);
        else (*tree)->r = no;
    }
    if (abs(heightTree(&((*tree)->l)) - heightTree(&((*tree)->r))) > 1) {
        if (heightTree(&((*tree)->l)) > heightTree(&((*tree)->r))) {
            if (heightTree(&((*tree)->l->l)) < heightTree(&((*tree)->l->r))) rotateCounterClockwise(&((*tree)->l));
            rotateClockwise(tree);
        } else {
            if (heightTree(&((*tree)->r->l)) > heightTree(&((*tree)->r->r))) rotateClockwise(&((*tree)->r));
            rotateCounterClockwise(tree);
        }
    }
    return *tree;
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
    if (*tree) {
        if (abs(heightTree(&((*tree)->l)) - heightTree(&((*tree)->r))) > 1) {
            if (heightTree(&((*tree)->l)) > heightTree(&((*tree)->r))) {
                if (heightTree(&((*tree)->l->l)) < heightTree(&((*tree)->l->r))) rotateCounterClockwise(&((*tree)->l));
                rotateClockwise(tree);
            } else {
                if (heightTree(&((*tree)->r->l)) > heightTree(&((*tree)->r->r))) rotateClockwise(&((*tree)->r));
                rotateCounterClockwise(tree);
            }
        }
    }
    return *tree;
}

void inorder(bst *tree) {
    if (!(*tree)) return;
    inorder(&((*tree)->l));
    printf("%d ", (*tree)->val);
    inorder(&((*tree)->r));
}

int findTreeR(bst *tree, element el) {
    if (!(*tree)) return 0;
    if ((*tree)->val == el) return 1;
    if ((*tree)->val > el) {
        int r = findTreeR(&((*tree)->l), el);
        return r ? r + 1 : 0;
    } else {
        int r = findTreeR(&((*tree)->r), el);
        return r ? r + 1 : 0;
    }
}

void findTree(bst *tree, element el) {
    int r = findTreeR(tree, el);
    if (r) printf("%d번째에 탐색 성공.\n", r);
    else printf("%d번째에 탐색 실패", heightTree(tree) + 1);
}

int main() {
    bst tree = NULL;
    insertTree(&tree, 50);
    insertTree(&tree, 60);
    insertTree(&tree, 70);
    insertTree(&tree, 90);
    insertTree(&tree, 80);
    insertTree(&tree, 75);
    insertTree(&tree, 73);
    insertTree(&tree, 72);
    insertTree(&tree, 78);
    inorder(&tree);
    printf("\n");
    findTree(&tree, 70);
    findTree(&tree, 72);
    findTree(&tree, 76);
}