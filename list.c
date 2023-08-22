#include "list.h"

int main() {
    
    struct door doors[DOORS_COUNT];
    struct node *start = init(doors);

    filling(start, doors);
    output(start);

    int id_find;
    printf("Enter door id to find: ");
    scanf("%d", &id_find);
    struct node *goal_node = find_door(id_find, start);
    printf("Status of %d is %d\n", goal_node->door->id, goal_node->door->status);

    int id_remove;
    printf("Enter door id to remove: ");
    scanf("%d", &id_remove);
    struct node *new_start = remove_door(find_door(id_remove, start), start);
    output(new_start);

    destroy(new_start);
    return 0;
}

void output(struct node *start) {
    struct node *cur_node = start;
    while (cur_node->door->id < DOORS_COUNT) {
        printf("%d %d\n", cur_node->door->id, cur_node->door->status);
        cur_node = cur_node->next;
    }
}

void filling(struct node *start, struct door *doors) {
    struct node *cur_node = start->next;
    for (int i = 2; i <= DOORS_COUNT; i++) {
        doors[i - 1].id = i;
        doors[i - 1].status = rand() % 2;
        cur_node = add_door(cur_node, &doors[i - 1]);
        cur_node = cur_node->next;
    }
}

struct node *init(struct door *doors) {
    doors[0].id = 1;
    doors[0].status = rand() % 2;
    struct node *start = malloc(sizeof(struct node));
    start->next = malloc(sizeof(struct node));
    start->door = &doors[0];
    return start;
}

struct node *add_door(struct node *elem, struct door *door) {
    elem->door = door;
    elem->next = malloc(sizeof(struct node));
    return elem;
}

struct node *find_door(int door_id, struct node *root) {
    struct node *cur_node = root;
    while (cur_node->door->id != door_id) {
        cur_node = cur_node->next;
    }
    return cur_node;
}

struct node *remove_door(struct node *elem, struct node *root) {
    if (elem->door->id == root->door->id) {
        struct node *ptr = root->next;
        free(root);
        root = ptr;
    } else {
        int contin = 1;
        struct node *cur_node = root;
        while (cur_node->door->id < DOORS_COUNT && contin) {
            if (cur_node->next->door->id == elem->door->id) {
                struct node *ptr = cur_node->next;
                cur_node->next = cur_node->next->next;
                free(ptr);
                contin = 0;
            }
            cur_node = cur_node->next;
        }
    }
    return root;
}

void destroy(struct node *root) {
    struct node *cur_node = root;
    while (cur_node->door->id < DOORS_COUNT) {
        struct node *next_ptr = cur_node->next;
        free(cur_node);
        cur_node = next_ptr;
    }
}