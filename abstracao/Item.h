#ifndef ITEM_H
#define ITEM_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_MESSAGE 140   /*maior tamanho para uma mensagem*/

#define KeyWord(A) (A -> text)
#define KeyCount(A) (A -> count)
#define KeyWord(A) (A -> text)
#define CompWord(A,B) (strcmp( A, B))
#define LessWord(A,B) (CompWord(A,B) < 0)
#define EqKeyCount(A,B) (KeyCount(A) == KeyCount(B))
#define DiffKeyCount(A,B) (KeyCount(A) - KeyCount(B))

typedef struct {
    char* text;
	int count;
} Item;

typedef Item* link; 

link newItem(char* str);

#endif