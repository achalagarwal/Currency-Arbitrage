//
//  graph.c
//  Currency
//
//  Created by Achal Agarwal on 18/04/18.
//  Copyright © 2018 Achal Agarwal. All rights reserved.
//

#ifndef graph_h
#include "graph.h"
#endif
#ifndef hash_h
#include "hash.h"
#endif
#include <stdlib.h>

#define INF -1

int hashVertex(Graph G, void* cur, int bound){
    //add another level of hash using the vertex number if required (but if -1?)
    Vertex v = cur;
    return G->hash(v->e, bound);
}

int areEqualVertices(Graph G, void* a, void* b){
    if(a==b)
        return 1;
    if(a==NULL || b==NULL)
        return 0;
    
    Vertex v1 = a;
    Vertex v2 = b;
    //default vertex id for non inserted vertices need to be -1
    if(v1->id == -1 || v2->id == -1)
        return G->compare(a,b);
    if(v1->id == v2->id)
        return 1;
    else
        return 0;
    //add another layer of checking if required, how do you check for duplicity in graph? Lets say a new element arrives, what will you do? Lookup the hash table right? Then what? the isEqual check vertex, do you have that? Do You? Say?
}

Vertex createVertex(void* e, int id){
    if(e==NULL)
        return NULL;
    Vertex v = (Vertex)malloc(sizeof(struct vertex));
    v->e = e;
    v->id = id;
    return v;
}
// do you need a new helper for void*
int lookupGraph(Graph G, void* e){
    //is there an alternative to creating a new vertex?
    Vertex v = createVertex(e, -1);
    int flag = lookup(G->table,v);
    free(v);
    return flag;
}

//update sizes?
int addVertex(Graph G, void* e){
    Vertex v = createVertex(e, -1);
    if(lookupGraph(G, e)>=0)
        return -1;
    else{
        v->id = G->size;
        //fix
        G->vertices[G->size++] = v;
        return addToHT(G->table, v);
    }
}
//add checks
int addEdgeToGraphHelper(Graph G, Vertex v1, Vertex v2, double weight){
    if(G==NULL)
        return 0;
    if(v1 == NULL || v2 == NULL)
        return 0;
    if(v1->id == -1 || v2->id == -1)
        return 0;
    if(v1->id>=G->size || v2->id>=G->size)
        return 0;
    G->adj[v1->id][v2->id] = weight;
    return 1;
}

//index of hash table
Vertex getVertex(Graph G, int index){
    //check edges
    return (Vertex)getHTElement(G->table, index);
}

int addEdgeToGraph(Graph G, void* e1, void* e2,double weight){
    //Vertex v1 = createVertex(e1, -1);
    //Vertex v2 = createVertex(<#void *e#>, <#int id#>)
    int index1 = lookupGraph(G, e1);
    int index2 = lookupGraph(G, e2);
    return addEdgeToGraphHelper(G, getVertex(G, index1), getVertex(G, index2), weight);
}

//add function overloading in C for no predefined size graph
    
//create two, dynamic size and with size option
// two functions, inital max number of elements expected
Graph createGraph(int size,int (*h)(void*,int),int (*c)(void*,void*)){
    Graph G = (Graph)malloc(sizeof(struct graph));
    G->size = size;
    
    G->adj = (double**)malloc(sizeof(double*)*size);
    G->vertices = (Vertex*)malloc(sizeof(Vertex)*size);
    G->compare = c;
    G->hash = h;
    G->table = createHT(size*2,G->hash,G->compare);
    for(int i = 0;i<size;i++){
        G->adj[i] = (double*)malloc(sizeof(double)*size);
        for(int j = 0;j<size;j++){
            if(i==j)
                G->adj[i][j] = 0;
            else
                G->adj[i][j] = INF;
        }
    }
    return G;
}


