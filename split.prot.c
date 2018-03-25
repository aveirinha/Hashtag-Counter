#include "split.h"
#include <string.h>

void split(char *line){
	int i = 0;
 	char* token = strtok(line, separators);
 	while(token != NULL) {

 		if (*token == '#'){
 			vec[i++] = token;
 		}

 	token = strtok(NULL, separators);
 	}
}