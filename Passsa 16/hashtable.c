#include "hashtable.h"
#include "Item.h"

#define HASHTABLE_INIT_SIZE 1000

 unsigned long int HT_size = HASHTABLE_INIT_SIZE; 
 unsigned int N_items = 0;
 unsigned int N_ocur = 0;

 link* hashtable;
 unsigned int ocur_max = 0;
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

void re_init_HT()
{
	int i;
	unsigned int old_N_items = N_items;
	link* k = hashtable;
	HT_size = 2 * HT_size;
	hashtable = (link*) malloc(HT_size*sizeof(link));
	for (i = 0; i < HT_size; i++)// inicializa a tabela
	{	
		hashtable[i] = NULL;
	}	
	for (i = 0; i < HT_size / 2; i++)//cria um vetor auxiliar com todos os elementos da tabela
	{	
		if (k[i] != NULL) insert(k[i]);
	}
	
	free(k);
	N_items = old_N_items;
}

int hash(char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; 

    return (int) hash % HT_size;
}

void insert(link L) 
{
	if (((float) N_items/HT_size)>0.6) 
		re_init_HT();
 	int i = hash(L->text);	
 	while (hashtable[i]!=NULL) i = (i+1) % HT_size;
 	hashtable[i] = L;
 	N_items ++;
 	atualiza_max(L);
}

link search(char* HT)
{
 	int i = hash(HT);
	while (hashtable[i]!=NULL)
	{
		if (!strcmp( hashtable[i]->text, HT))  return hashtable[i];
		else i = (i+1) % HT_size;
	}
 	return NULL;
}

void aumenta(link L)
{
	L -> count++;
	N_ocur ++;
	atualiza_max(L);
	
}

void atualiza_max(link L)
{
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