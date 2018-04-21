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
Graph createGraph(int size,int (*h)(void*,int),int (*c)(void*,void*));
int addEdgeToGraph(Graph G, void* e1, void* e2,double weight);
Vertex getVertex(Graph G, int index);
int addEdgeToGraphHelper(Graph G, Vertex v1, Vertex v2, double weight);
int addVertex(Graph G, void* e);
int lookupGraph(Graph G, void* e);
Vertex createVertex(void* e, int id);
int areEqualVertices(Graph G, void* a, void* b);
int hashVertex(Graph G, void* cur, int bound);
