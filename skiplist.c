//
//  skiplist.c
//  skiplist
//
//  Created by tzongw on 6/20/16.
//  Copyright © 2016 tzongw. All rights reserved.
//

#include "skiplist.h"
#include "stdlib.h"
#include "strings.h"

static const int KLevelMax = 8;
static const int KFactor = 2;

struct node {
    int key;
    struct node *next[];
};

struct skiplist {
    struct node *head[KLevelMax];
};

static struct node *create_node(int key, int level)
{
    struct node *n = malloc(sizeof(*n) + sizeof(n) * level);
    n->key = key;
    return n;
}

static int random_level()
{
    int level = 0;
    do {
        level++;
    } while (level < KLevelMax && rand() < RAND_MAX / KFactor);
    return level;
}

struct skiplist *sl_create()
{
    return calloc(1, sizeof(struct skiplist));
}

void sl_insert(struct skiplist *sl, int key)
{
    struct node **prev[KLevelMax+1];
    prev[KLevelMax] = &sl->head[KLevelMax-1] + 1;
    for (int level = KLevelMax - 1; level >= 0; level--) {
        prev[level] = prev[level+1] - 1;
        struct node *n;
        while ((n = *prev[level]) && n->key < key) {
            prev[level] = &n->next[level];
        }
    }
    int rlevel = random_level();
    struct node *n = create_node(key, rlevel);
    for (int level = 0; level < rlevel; level++) {
        n->next[level] = *prev[level];
        *prev[level] = n;
    }
}

void sl_print(struct skiplist *sl)
{
    for (int level = KLevelMax - 1; level >= 0; level--) {
        for (struct node *n = sl->head[level]; n != NULL; n = n->next[level]) {
            printf("%d ", n->key);
        }
        printf("\n-------------------------\n");
    }
}


