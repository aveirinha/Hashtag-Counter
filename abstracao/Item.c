#include "Item.h"

link newItem(char* str)
{
link p = (link) malloc(sizeof(Item));
    KeyWord(p) = (char*) malloc(sizeof(char)*(MAX_MESSAGE + 1));
    strcpy(KeyWord(p), str); 
    KeyCount(p) = 1;
    return p;
}