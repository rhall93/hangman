#include <stdio.h>
#include <stdlib.h>
#include "my_vect.h"
#include "my_string.h"

STR_VECT my_vect_init_default(void)
{
	Str_vect *pTemp_vect = (Str_vect*) malloc(sizeof(Str_vect));
	int i;
	
	if(pTemp_vect != NULL)
	{
		pTemp_vect->size = 0;
		pTemp_vect->capacity = 1;
		pTemp_vect->data = (MY_STRING*) malloc(sizeof(MY_STRING));
		if(pTemp_vect->data == NULL)
		{
			free(pTemp_vect);
			pTemp_vect = NULL;
		}
		for(i = 0; i < pTemp_vect->capacity; i++)
		{
			pTemp_vect->data[i] = NULL;
		}
	}
	return (STR_VECT) pTemp_vect;
}

int my_vect_get_size(STR_VECT hVect)
{
	Str_vect *pVect = (Str_vect*) hVect;

	return pVect->size;
}

int my_vect_get_capacity(STR_VECT hVect)
{
	Str_vect *pVect = (Str_vect*) hVect;

	return pVect->capacity;
}

char* my_vect_get_string(STR_VECT hVect, int index)
{
	Str_vect *pVect = (Str_vect*) hVect;
	return my_string_get_data(pVect->data[index]);
}

MY_STRING my_vect_get_MY_STRING(STR_VECT hVect, int index)
{
	Str_vect *pVect = (Str_vect*) hVect;
	return (pVect->data[index]);
}

void my_vector_increase_capacity(STR_VECT hVect)
{
	int i;
	Str_vect *pVect = (Str_vect*) hVect;
	pVect->capacity *= 2;
	STR_VECT *pTemp = (STR_VECT*) malloc(sizeof(STR_VECT) * pVect->capacity);
	if(pTemp != NULL)
	{
		for(i = 0; i < pVect->size; i++)
		{
			pTemp[i] = pVect->data[i];
		}
		while(i < pVect->capacity)
		{
			pTemp[i] = NULL;
			i++;
		}
		free(pVect->data);
		pVect->data = (MY_STRING) pTemp;		
	}
}

void my_vect_add_string(MY_STRING hString, STR_VECT hVect)
{
	Str_vect *pVect = (Str_vect*) hVect;
	int i = 0;

	if(pVect->size >= pVect->capacity)
	{
		my_vector_increase_capacity(hVect);
	}

	while(pVect->data[i] != NULL)
	{
		i++;
	}
	my_string_assignment(&pVect->data[i], hString);	
	pVect->size++;
}

void my_vect_copy_vector(STR_VECT *phLeft, STR_VECT hRight)
{
	int i = 0;
	Str_vect *pRight = (Str_vect*) hRight;
	*phLeft = my_vect_init_default();

	for(i = 0; i < pRight->size; i++)
	{
		my_vect_add_string(pRight->data[i], *phLeft);
	}
}

void my_vect_destroy(STR_VECT *phVect)
{
	Str_vect *pVect = (Str_vect*) *phVect;
	int i = 0;
	while(i < pVect->size)
	{
		my_string_destroy(&pVect->data[i]);
		i++;
	}
	free(pVect->data);
	free(pVect);
	*phVect = NULL;
}


