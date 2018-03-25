#include "hashtable.h"
#include "Item.h"

#define HASHTABLE_INIT_SIZE 1000

 unsigned long int HT_size = HASHTABLE_INIT_SIZE; /*nao sei se sera boa ideia ser inteiro ou double ou outro tipo de variavel*/
 int N_items = 0;
 int N_ocur = 0;

 link* hashtable;
/*static link* items;*/
 int ocur_max = 0;
 char* tag_max;



void init_HT()
{
	int i;
	hashtable = (link*) malloc(HASHTABLE_INIT_SIZE*sizeof(link));
	for (i = 0; i < HASHTABLE_INIT_SIZE; i++)
	{
		hashtable[i] = NULL;
	}
}

/*void re_init_HT()
{
	int i, j;
	items = (link*) malloc(N_items*sizeof(link));
	for (i = 0, j = 0; i < HT_size; i++)//cria um vetor auxiliar com todos os elementos da tabela
	{	
		if (hashtable[i] == NULL) items[j] = hashtable[i];
	}
	HT_size = 2 * HT_size;
	free(hashtable);
	hashtable = (link*) malloc(HT_size*sizeof(link));
	for (i = 0; i < HT_size; i++)// inicializa a tabela
	{	
		hashtable[i] = NULL;
	}
	for (i = 0; i < N_items; i++)// re-incere os elementos na tabela
	{
		insert(items[i]);
	}
	free(items);
}
*/

void re_init_HT()
{
	int i;
	link* k = hashtable;
	hashtable = (link*) malloc(2*HT_size*sizeof(link));
	for (i = 0; i < 2 * HT_size; i++)// inicializa a tabela
	{	
		hashtable[i] = NULL;
	}	
	for (i = 0; i < HT_size; i++)//cria um vetor auxiliar com todos os elementos da tabela
	{	
		if (k[i] != NULL) insert(*k[i]);
	}
	HT_size = 2 * HT_size;
	free(k);
}
int hash(char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return (int) hash % HT_size;
}

/*
int hash(char* str, int M)
{
	int i, a = 31415, b = 27183;
	for (i = 0; *str != '\0'; a = a*b % (M-1))
	{
		i = (a*i + *str) % M;
	}
	return i;
}
*/
void insert(Item p) 
{
	if (((float) N_items/HT_size)>0.6) re_init_HT();
 	int i = hash(p->text);	/*ou *text*/
 	while (hashtable[i]!=NULL) i = (i+1) % HT_size;
 	hashtable[i] = p;
 	N_items ++;
 	N_ocur ++;
}

link search(char* HT)
{
 	int i = hash(HT);
	while (hashtable[i]!=NULL)
	{
		if (!strcmp( *hashtable[i]->text, HT))  return hashtable[i];
		else i = (i+1) % HASHTABLE_INIT_SIZE;
	}
 	return NULL;
}

void aumenta(link L)
{
	L -> count++;
	N_ocur ++;
	if ((L -> count) > ocur_max) 
	{
		ocur_max = L -> count;
		tag_max = L -> text;
	}
	if ((L -> count) == ocur_max)
	{
		if (strcmp( L -> text, tag_max ) < 0) tag_max = L -> text;
	}
}

int comparacao(link x, link y) 
{
	if (x -> count == y -> count) return strcmp(x -> text, y -> text);
	return y -> count - x -> count;
}

int qcmp(void const* p, void const* q)
{
	return comparacao( (*( link const*)p), (*( link const*)q));
}


//para ordenar usar qsort(nome_array, sizeof(nome_array), sizeof(link), qcmp)