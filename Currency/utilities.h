//
//  utilities.h
//  Currency
//
//  Created by Achal Agarwal on 22/04/18.
//  Copyright © 2018 Achal Agarwal. All rights reserved.
//
#ifndef graph_h
#include "graph.h"
#endif
#ifndef hash_h
#include "hash.h"
#endif
#ifndef utilities_h
#define utilities_h

#include <stdio.h>

#endif /* utilities_h */

struct array{
    int size;
    void* arr;
};
typedef struct array* Array;
Array parseCurrencies(char* fname);
HT generateHT(Array c);
Graph generateGraph(Array c);
int randomAlphabet(void);
