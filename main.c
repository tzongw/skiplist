//
//  main.c
//  skiplist
//
//  Created by tzongw on 6/20/16.
//  Copyright © 2016 tzongw. All rights reserved.
//

#include <stdio.h>
#include "skiplist.h"
#include "stdlib.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    struct skiplist *sl = sl_create();
    for (int i = 0; i < 64; i++) {
        sl_insert(sl, rand()%100);
    }
    sl_print(sl);
    return 0;
}
