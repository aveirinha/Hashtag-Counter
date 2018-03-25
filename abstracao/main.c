//Trabalho Realizado Por Afonso Figueiredo (83416) e Maria Aveiro
#include <ctype.h>
#include "main.h"
#include "split.h"
#include "hashtable.h"
#include "Item.h"

int Flag_co = 1; /*flag que indica se e necessario criar e ordenar o vetor vec_ord*/
int Flag_v = 0; /*flag que indica se existe o vec_ord*/
link* vec_ord;
int main()
{
	/* Armazena a mensagem introduzida no comando a */
    char* message = (char*) malloc(sizeof(char)*(MAX_MESSAGE + 1)); /* + NULL */
    char command;
    int i = 0, k = 0;
    init_HT();
    link* aux = NULL;

	while(69)
	{

		command = getchar();

		switch(command)
		{
			case 'a':
				fgets(message, MAX_MESSAGE, stdin);
				split(message);
				Flag_co = 1;
				if (Flag_v) {free(aux); Flag_v = 0;}

			break;

			case 's':
				printf("%d %d\n",N_items, N_ocur);
			break;

			case 'm':
				if (N_items) printf("%s %d\n",tag_max, ocur_max);
			break;

			case 'l':
				if (Flag_co)
				{
					link* vec_ord = (link*) malloc(N_items*sizeof(link));
					aux = vec_ord;
					for (i = 0, k = 0; i < HT_size; i++)
					{
						if (hashtable[i] != NULL) vec_ord[k++] = hashtable[i];
					}
					qsort(vec_ord, N_items, sizeof(link), qcmp);
				}
				for (i = 0; i < N_items; i++)
					printf("%s %d\n",KeyWord(aux[i]), KeyCount(aux[i]));
				Flag_co = 0;
				Flag_v = 1;
			break;

			case 'x':
			free(message);
			for (i = 0, k = 0; i < HT_size; i++)
			{
				if (hashtable[i] != NULL) 
					{
						free(hashtable[i]->text);
						free(hashtable[i]);
					}
			}
			if (Flag_v) {free(aux); Flag_v = 0;}
			free(hashtable);
			return 0;
		}
	}
}

