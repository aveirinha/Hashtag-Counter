
#ifndef _SPLIT_
#define _SPLIT_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Item.h"


static const char separators[] = {' ','\t',',',';','.','?','!','"','\n',':','\0'};
void split(char *line);

#endif