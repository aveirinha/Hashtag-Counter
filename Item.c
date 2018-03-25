#include "Item.h"

link newItem(char* str)
{
link p = (link) malloc(sizeof(Item));
    p -> text = (char*) malloc(sizeof(char)*(MAX_MESSAGE + 1));
    strcpy(p -> text, str); 
    p -> count = 1;
    return p;
}