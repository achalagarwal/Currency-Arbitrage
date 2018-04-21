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
#ifndef utilities_h
#include "utilities.h"
#endif

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
    char* name = "currencies";
    Array c = parseCurrencies(name);
    Graph g = generateGraph(c);
   // HT h = generateHT(c);
    
    return 0;
}
