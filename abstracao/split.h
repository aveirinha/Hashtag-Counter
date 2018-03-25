
#ifndef _SPLIT_
#define _SPLIT_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Item.h"

extern unsigned int N_ocur;
static const char separators[] = {' ','\t',',',';','.','?','!','"','\n',':','\0'};
void split(char *line);

#endif