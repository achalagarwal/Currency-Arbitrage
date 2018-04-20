//
//  graph.h
//  Currency
//
//  Created by Achal Agarwal on 18/04/18.
//  Copyright © 2018 Achal Agarwal. All rights reserved.
//

#ifndef hash_h
#include "hash.h"
#endif

#ifndef graph_h
#define graph_h

#include <stdio.h>

#endif /* graph_h */

struct vertex{
    void* e;
    int id;
};

typedef struct vertex* Vertex;

struct graph{
    HT table;
    double** adj;
    Vertex* vertices;
    int size;
    int (*hash)(void*,int);
    int (*compare)(void*,void*);
};

typedef struct graph* Graph;



