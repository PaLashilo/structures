#include "bts.h"

t_btree *bstree_create_node(int item);
void bstree_insert(t_btree *root, int item, int (*cmpf)(int, int));
int max_value(int val1, int val2);
void bstree_apply_infix(t_btree *root, void (*applyf)(int));
void bstree_apply_prefix(t_btree *root, void (*applyf)(int));
void bstree_apply_postfix(t_btree *root, void (*applyf)(int));
void print_node(int value);

int main() {
    t_btree *root = bstree_create_node(5);
    int count_values = 6;
    int values[6] = {6, 3, 61, 8, 9, 0};
    for (int i = 0; i < count_values; i++) {
        printf("adding value %d\n", values[i]);
    }
    printf("\n");
    printf("infix output: ");
    bstree_apply_infix(root, print_node);
    printf("\nprefix output: ");
    bstree_apply_prefix(root, print_node);
    printf("\npostfix output: ");
    bstree_apply_postfix(root, print_node);
    return 0;
}

void print_node(int value) { printf("%d ", value); }

void bstree_apply_infix(t_btree *root, void (*applyf)(int)) {
    if (root != NULL) {
        bstree_apply_infix(root->left, applyf);
        print_node(root->item);
        bstree_apply_infix(root->right, applyf);
    }
}

void bstree_apply_prefix(t_btree *root, void (*applyf)(int)) {
    if (root != NULL) {
        print_node(root->item);
        bstree_apply_prefix(root->left, applyf);
        bstree_apply_prefix(root->right, applyf);
    }
}

void bstree_apply_postfix(t_btree *root, void (*applyf)(int)) {
    t_btree *node = root;
    if (node != NULL) {
        bstree_apply_prefix(node->left, applyf);
        bstree_apply_prefix(node->right, applyf);
        print_node(node->item);
    }
}

t_btree *bstree_create_node(int item) {
    t_btree *node = malloc(sizeof(t_btree));
    node->left = NULL;
    node->right = NULL;
    node->item = item;
    return node;
}

void bstree_insert(t_btree *root, int item, int (*cmpf)(int, int)) {
    t_btree *elem = root;
    t_btree *parent;
    while (elem != NULL) {
        parent = elem;
        if (cmpf(item, elem->item) == item) {
            elem = elem->right;
        } else {
            elem = elem->left;
        }
    }
    if (cmpf(parent->item, item) == item) {
        parent->right = bstree_create_node(item);
    } else {
        parent->left = bstree_create_node(item);
    }
}

int max_value(int val1, int val2) {
    int max_value = val2;
    if (val1 > val2) {
        max_value = val1;
    }
    return max_value;
}