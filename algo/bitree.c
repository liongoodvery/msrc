//
// Created by lion on 17-7-20.
//
#include <memory.h>
#include "bitree.h"

void bitree_init(BiTree *tree, void (*destroy)(void *data), void(*print)(void *print)) {
    memset(tree, 0, sizeof(BiTree));
    tree->destroy = destroy;
    tree->print = print;
}

void bitree_destroy(BiTree *tree) {
    bitree_rem_left(tree, NULL);
    memset(tree, 0, sizeof(BiTree));
}

int bitree_ins_left(BiTree *tree, BiTreeNode *node, const void *data) {
    if (node == NULL) {
        if (bitree_size(tree) == 0) {
            BiTreeNode *pb = (BiTreeNode *) malloc(sizeof(BiTreeNode));
            memset(pb, 0, sizeof(BiTreeNode));
            pb->data = data;
            tree->root = pb;
            tree->size++;
            return 0;
        } else {
            return -1;
        }
    } else {
        if (node->left != NULL) {
            return -1;
        } else {
            BiTreeNode *pb = (BiTreeNode *) malloc(sizeof(BiTreeNode));
            memset(pb, 0, sizeof(BiTreeNode));
            pb->data = data;
            node->left = pb;
            tree->size++;
            return 0;
        }
    }


}

int bitree_ins_right(BiTree *tree, BiTreeNode *node, const void *data) {
    if (node == NULL) {
        if (bitree_size(tree) == 0) {
            BiTreeNode *pb = (BiTreeNode *) malloc(sizeof(BiTreeNode));
            memset(pb, 0, sizeof(BiTreeNode));
            pb->data = data;
            tree->root = pb;
            tree->size++;
            return 0;
        } else {
            return -1;
        }
    } else {
        if (node->right != NULL) {
            return -1;
        } else {
            BiTreeNode *pb = (BiTreeNode *) malloc(sizeof(BiTreeNode));
            memset(pb, 0, sizeof(BiTreeNode));
            pb->data = data;
            node->right = pb;
            tree->size++;
            return 0;
        }
    }
}

void bitree_rem_left(BiTree *tree, BiTreeNode *node) {
    if (tree->size == 0) {
        return;
    }

    BiTreeNode *p;

    if (node == NULL) {
        p = tree->root;
    } else {
        p = node->left;
    }

    if (p == NULL) {
        return;
    }

    bitree_rem_left(tree, p);
    bitree_rem_right(tree, p);

    if (tree->destroy != NULL) {
        tree->destroy(p->data);
    }

    free(p);
    p = NULL;
    tree->size--;
}

void bitree_rem_right(BiTree *tree, BiTreeNode *node) {
    if (tree->size == 0) {
        return;
    }

    BiTreeNode *p;

    if (node == NULL) {
        p = tree->root;
    } else {
        p = node->right;
    }

    if (p == NULL) {
        return;
    }

    bitree_rem_left(tree, p);
    bitree_rem_right(tree, p);

    if (tree->destroy != NULL) {
        tree->destroy(p->data);
    }

    free(p);
    p = NULL;
    tree->size--;
}

int bitree_merge(BiTree *merge, BiTree *left, BiTree *right, const void *data);


static void preorder(BiTree *tree, BiTreeNode *node) {
    if (node == NULL) {
        preorder(tree, tree->root);
        return;
    }

    if (tree->print != NULL) {
        tree->print(bitree_data(node));
    }

    if (node->left != NULL) {
        preorder(tree, node->left);
    }

    if (node->right != NULL) {
        preorder(tree, node->right);
    }


}


int bitree_traverse(BiTree *tree) {
    preorder(tree, NULL);
}


int bitree_fill(BiTree *tree, void *datas[], size_t len, size_t size) {

    BiTreeNode *nodes[size];
    for (int i = size - 1; i >= 0; i--) {
        BiTreeNode *node = (BiTreeNode *) malloc(sizeof(BiTreeNode));
        memset(node, 0, sizeof(BiTreeNode));
        node->data = *(datas + i);

        if (2 * i + 1 < size) {
            node->left = nodes[2 * i + 1];
        }

        if (2 * i + 2 < size) {
            node->right = nodes[2 * i + 2];
        }
        nodes[i] = node;
    }


    tree->size = size;
    tree->root = nodes[0];

}


