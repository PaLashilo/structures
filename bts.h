#include <stdio.h>
#include <stdlib.h>

typedef struct s_btree 
{
    struct s_btree *left; 
    struct s_btree *right;
    int item; 
} t_btree;



