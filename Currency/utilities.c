//
//  utilities.c
//  Currency
//
//  Created by Achal Agarwal on 22/04/18.
//  Copyright © 2018 Achal Agarwal. All rights reserved.
//

#include "utilities.h"
#ifndef hash_h
#include "hash.h"
#endif
#ifndef graph_h
#include "graph.h"
#endif
#ifndef currency_h
#include "currency.h"
#endif
#include<stdio.h>
#include<stdlib.h>

int randomAlphabet(){
    return 65+(rand()%26);
}

int randomNumber(int bound){
    return rand()%bound;
}

Array parseCurrencies(char* fname){
    FILE* f = fopen(fname,"r");
    char* temp = (char*)malloc(sizeof(char)*4);
    int a = fscanf(f,"%s\n",temp);
    int size = 0;
    while(a!=EOF){
        size++;
        a = fscanf(f, "%s\n",temp);
    }
    fclose(f);
    f = fopen(fname,"r");
    a = fscanf(f, "%s",temp);
    Currency* currencies = (Currency*)malloc(sizeof(Currency)*size);
    for(int i =0;i<size;i++){
        //currencies[i] = createCurrency(<#char *key#>)
        //for(int j = 0;j<3;j++)
        //  temp[j] = (char)randomAlphabet();
        currencies[i] = createCurrency(temp);
        printf("%s\n",currencies[i]->key);
        
        a = fscanf(f, "%s",temp);
    }
    Array arr = malloc(sizeof(struct array));
    arr->size = size;
    arr->arr = currencies;
    return arr;
    
    
}

Graph generateGraph(Array c){
    int size = c->size;
    void** temp = c->arr;
    Graph g = createGraph(size, &hashCurrency,&areEqualCurrencies);
    for(int i = 0;i<size;i++){
        int flag = addVertex(g,temp[i]);
        if(flag == 0){
            printf("Could Not Insert %dth element\n",i);
            break;
        }
        if(flag == -1){
            printf("Already inserted the currency %s\n",((Currency)temp[i])->key);
        }
    }
    return g;
}


HT generateHT(Array c){
    int size = c->size;
    HT h = createHT(size*2, &hashCurrency, &areEqualCurrencies);
    Currency* currencies = c->arr;
    for(int i = 0;i<size;i++){
        int flag = addCurrency(h, currencies[i]);
        if(flag == 0){
            printf("Could Not Insert %dth element\n",i);
            break;
        }
        if(flag == -1){
            printf("Already inserted the currency %s\n",currencies[i]->key);
        }
    }
    return h;
}
