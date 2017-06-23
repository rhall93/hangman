#ifndef MY_VECT_H
#define MY_VECT_H

#include "my_string.h"

typedef struct str_vect
{
	int size;
	int capacity;
	MY_STRING *data;
}Str_vect;

typedef void* STR_VECT;


/* vector functions */


STR_VECT my_vect_init_default(void);

int my_vect_get_size(STR_VECT hVect);

int my_vect_get_capacity(STR_VECT hVect);

char* my_vect_get_string(STR_VECT hVect, int index);

MY_STRING my_vect_get_MY_STRING(STR_VECT hVect, int index);

void my_vector_increase_capacity(STR_VECT hVect);

void my_vect_add_string(MY_STRING hMy_string, STR_VECT hVect);

void my_vect_copy_vector(STR_VECT *phLeft, STR_VECT hRight);

void my_vect_destroy(STR_VECT *phVect);

#endif /* MY_VECT_H */