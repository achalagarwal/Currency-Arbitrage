//
//  main.c
//  Currency
//
//  Created by Achal Agarwal on 16/04/18.
//  Copyright © 2018 Achal Agarwal. All rights reserved.
//
#include <unistd.h>
#include <stdio.h>
#ifndef currency_h
#include "currency.h"
#endif
#ifndef hash_h
#include "hash.h"
#endif
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int randomAlphabet(){
    return 65+(rand()%26);
}

HT generateRandom(){
    int size = 162;
    FILE* f = fopen("currencies","r");
    char* temp = (char*)malloc(sizeof(char)*4);
    int a = fscanf(f, "%s",temp);
    Currency* currencies = (Currency*)malloc(sizeof(Currency)*size);
    HT h = createHT(size, &hashCurrency, &areEqualCurrencies);
    for(int i =0;i<size;i++){
        //currencies[i] = createCurrency(<#char *key#>)
        //for(int j = 0;j<3;j++)
          //  temp[j] = (char)randomAlphabet();
        currencies[i] = createCurrency(temp);
        printf("%s\n",currencies[i]->key);
        int flag = addCurrency(h, currencies[i]);
        if(flag == 0){
            printf("Could Not Insert %dth element\n",i);
            break;
        }
        if(flag == -1){
            printf("Already inserted the currency %s\n",currencies[i]->key);
        }
        a = fscanf(f, "%s",temp);
    }
    return h;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //printf("Hello, World!\n");
//    FILE* f = fopen("cur.txt","r");
//    FILE* n = fopen("currencies","w");
//    char* buf = (char*)malloc(sizeof(char)*100);
//    printf("%s",getwd(buf));
//    char* t = (char*)malloc(sizeof(char)*10);
//    int a = 0;
//    char c = fgetc(f);
//    while(a!=EOF && c!=EOF){
//        if(c=='\n'){
//            a = fscanf(f, "%3s",t);
//            fprintf(n,"%s\n",t);
//        }
//        c = fgetc(f);
//
//    }
    HT h = generateRandom();
    
    return 0;
}
