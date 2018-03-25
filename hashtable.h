#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct {
    char* text;
	int count;
} Item;

typedef Item* link; 

/*extern int HT_size;*/
void init_HT();
void re_init_HT();
int hash(char* str);
void insert(Item p); 
link search(char* HT);
void aumenta(link L);
int comparacao(link x, link y);
int qcmp(void const* p, void const* q);

#endif