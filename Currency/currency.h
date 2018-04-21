//
//  currency.h
//  
//
//  Created by Achal Agarwal on 16/04/18.
//

#ifndef currency_h
#define currency_h

#include <stdio.h>

#endif /* currency_h */
#ifndef hash_h
#include "hash.h"
#endif
struct currency;
typedef struct currency* Currency;

struct currency{
    char* key;
};

int hashCurrency(void* c, int bound);
int areEqualCurrencies(void* a, void* b);
char* getKey(Currency c);
int addCurrency(HT h,Currency c);

Currency createCurrency(char* key);
