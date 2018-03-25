#ifndef ITEM_H
#define ITEM_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_MESSAGE 140   /*maior tamanho para uma mensagem*/

typedef struct {
    char* text;
	int count;
} Item;

typedef Item* link; 

link newItem(char* str);

#endif