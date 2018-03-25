#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Item.h"


/*extern int HT_size;*/
void init_HT();
void re_init_HT();
int hash(char* str);
void insert(link p); 
void atualiza_max(link L);
link search(char* HT);
void aumenta(link L);
int comparacao(link x, link y);
int qcmp(void const* p, void const* q);

#endif