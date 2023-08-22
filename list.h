#include <stdio.h>
#include <stdlib.h>
#define DOORS_COUNT 10

struct door {
    int id;
    int status;
};

struct node {
    struct node *next;
    struct door *door;
};

void filling(struct node *start, struct door *doors);
void output(struct node *start);
struct node *init(struct door *door);
struct node *add_door(struct node *elem, struct door *door);
struct node *find_door(int door_id, struct node *root);
struct node *remove_door(struct node *elem, struct node *root);
void destroy(struct node *root);