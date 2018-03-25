#include <ctype.h>
#include "split.h"
#include "hashtable.h"
#include "Item.h"

void split(char *line)
{
 	char* token = strtok(line, separators);
 	link c;
 	int i;
 	while(token != NULL) 
 	{
 		if (*token == '#')
 		{
 			for (i = 1; token[i] != '\0'; i++) token[i] = tolower(token[i]);
 			c = search(token); /*primeira letra dps do #*/
 			if (c != NULL) aumenta(c);
 			else 
 			{
 				c = newItem(token);
 				insert(c);
 				N_ocur ++;
 			}
 		}
 		token = strtok(NULL, separators);
 	}
}
