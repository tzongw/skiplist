//
//  skiplist.h
//  skiplist
//
//  Created by tzongw on 6/20/16.
//  Copyright © 2016 tzongw. All rights reserved.
//

#ifndef skiplist_h
#define skiplist_h

#include <stdio.h>

struct skiplist;

struct skiplist *sl_create();
void sl_insert(struct skiplist *sl, int key);
void sl_print(struct skiplist *sl);

#endif /* skiplist_h */
