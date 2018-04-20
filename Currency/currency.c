//
//  currency.c
//  
//
//  Created by Achal Agarwal on 16/04/18.
//

#include "currency.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
Currency createCurrency(char* key){
    Currency c = (Currency)malloc(sizeof(struct currency));
    c->key = (char*)malloc(sizeof(char)*4);
    sprintf(c->key,"%3s",key);
    return c;
}

int hashCurrency(void* cur, int bound){
    if(cur == NULL){
        return -1;
    }
    int a = 31;
    int hv = 0;
    int i =0;
    Currency c = (Currency)cur;
    char ch = c->key[i++];
    while(ch!='\0'){
        hv = (hv*a + ch) % bound;
        ch = c->key[i++];
    }
    return hv;
}
int areEqualCurrencies(void* a, void* b){
    if(a==b)
        return 1;
    if(a == NULL || b == NULL)
        return 0;
    if(strcmp(((Currency)a)->key,((Currency)b)->key)==0)
        return 1;
    else
        return 0;
}

int addCurrency(HT h,Currency c){
    return addToHT(h, (void*)c);
}
