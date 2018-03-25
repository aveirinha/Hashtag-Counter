#include "split.h"
#include "hashtable.h"
#include "Item.h"

void split(char *line)
{
	int i = 0;
 	char* token = strtok(line, separators);
 	link c;
 	while(token != NULL) 
 	{
 		if (*token == '#')
 		{
 			c = search(token); /*primeira letra dps do #*/
 			if (c != NULL) aumenta(c);
 			else 
 			{
 				c = newItem(token);
 				insert(*c);
 			}
 		}
 	}
 	token = strtok(NULL, separators);
}
