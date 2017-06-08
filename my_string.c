#include <stdlib.h>
#include <stdio.h>
#include "my_string.h"
#include <string.h>

typedef struct my_string{
  int size;
  int capacity;
  char *data;
}My_string;

MY_STRING my_string_init_default(void){
  // write function definition
  My_string *pMy_string = (My_string*) malloc(sizeof(My_string));
  if(pMy_string != NULL)
    {
      pMy_string->size = 0;
      pMy_string->capacity = 7;
      pMy_string->data = (char*) malloc(sizeof(char) * pMy_string->capacity);
      if(pMy_string->data == NULL)
	{
	  free (pMy_string);
	  pMy_string = NULL;
	}	
  pMy_string->data[0] = '\0';
    }
  return (MY_STRING) pMy_string;
}

MY_STRING my_string_init_c_string(const char *c_string){
  My_string *pMy_string = (My_string*) malloc(sizeof(My_string));
  int i = 0;
  if (pMy_string != NULL){
    pMy_string->size = strlen(c_string);
    pMy_string->capacity = strlen(c_string) + 1;
    pMy_string->data =  (char*) malloc(sizeof(char) * pMy_string->capacity);
    while(c_string[i] != '\0')
      {
	       pMy_string->data[i] = c_string[i];
	       i++;
      }
    
    pMy_string->data[i] = '\0'; 
  }
  return (MY_STRING) pMy_string;
}

int my_string_get_capacity(MY_STRING hMy_string)
{
  My_string *pMy_string = (My_string*) hMy_string;

  return pMy_string->capacity;
}

int my_string_get_size(MY_STRING hMy_string)
{
  My_string *pMy_string = (My_string*) hMy_string;

  return pMy_string->size;
}

char* my_string_get_data(MY_STRING hMy_string)
{
  My_string *pMy_string = (My_string*) hMy_string;

  return pMy_string->data;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string)
{
  My_string *pLeft_string = (My_string*) hLeft_string;
  My_string *pRight_string = (My_string*) hRight_string;
  int i;
       
  for(i = 0; ;i++)
    {
      if(pLeft_string->data[i] < pRight_string->data[i])
	return 1;

      if(pRight_string->data[i] < pLeft_string->data[i])
	return -1;

      if(pLeft_string->data[i] == '\0')
	return 0;
    }
}

Status my_string_extraction(MY_STRING hMy_string, FILE *fp)
{
   My_string *pMy_string = (My_string*) hMy_string;
    
   char *temp;
   int i = 0;
   int j;
   static int flag = 1;
   
   pMy_string->size = 0;
     
   while (fscanf(fp, "%c", &pMy_string->data[i]) != EOF)
     {
       if((i == 0) && pMy_string->data[i] == ' ')
	 continue; 
       pMy_string->size++;
       if(pMy_string->size >= pMy_string->capacity)
	 {
	   pMy_string->capacity *= 2;
	   temp = (char*)malloc(sizeof(char*) * pMy_string->capacity);

	   for(j = 0; j < pMy_string->size; j++)
	     {
	       temp[j] = pMy_string->data[j]; 
	     }
   
	   free(pMy_string->data);
	   pMy_string->data = temp;
	   
	 }
       if ((pMy_string->data[i] == ' ') || pMy_string->data[i] == '\n')
       {
	       
	 fseek(fp, -1, SEEK_CUR);
	 pMy_string->data[i] = '\0';
	 pMy_string->size--;
	 return SUCCESS;
       }
       i++;
     }
   if(flag)
     {
       flag = 0;
       pMy_string->data[i+1] = '\0';
       fseek(fp, -2, SEEK_CUR);
       return SUCCESS;
     }
 return FAILURE;
}

Status my_string_insertion(MY_STRING hMy_string, FILE *fp)
{
  
  
  My_string *pMy_string = (My_string*) hMy_string;
  
  

	if(fprintf(fp, "%s", pMy_string->data))
	  {
	    return SUCCESS;
	  }
 
  return FAILURE;
}

Status my_string_push_back(MY_STRING hMy_string, char item)
{
  My_string *pMy_string = (My_string*) hMy_string;
  char *temp;
  int i = 0;
  int j;

  if(pMy_string->size + 1 >= pMy_string->capacity)
    {
      pMy_string->capacity *= 2;
      temp = (char*)malloc(sizeof(char*) * pMy_string->capacity);

      if(temp == NULL)
	{
	  return FAILURE;
	}

      for(j = 0; j <= pMy_string->size; j++)
	{
	  temp[j] = pMy_string->data[j]; 
	}
   
      free(pMy_string->data);
      pMy_string->data = temp;	   
    }
  
  while(pMy_string->data[i] != '\0')
    {
      i++;
    }
  pMy_string->data[i] = item;
  pMy_string->data[i+1] = '\0';
  pMy_string->size++;

  return SUCCESS;
}

Status my_string_pop_back(MY_STRING hMy_string)
{
  My_string *pMy_string = (My_string*) hMy_string;
  int i = 0;

  if(pMy_string->data[i] == '\0')
    return FAILURE;

  while(pMy_string->data[i] != '\0')
    i++;

  pMy_string->data[i-1] = '\0';

  pMy_string->size--;

  return SUCCESS;
}

char* my_string_at(MY_STRING hMy_string, int index)
{
  My_string *pMy_string = (My_string*) hMy_string;

  if(index >= pMy_string->size)
    return NULL;
  
  char *pCh = &pMy_string->data[index];

  return pCh;
}

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend)
{
  My_string *pResult = (My_string*) hResult;
  const My_string *pAppend = (My_string*) hAppend;
  char *temp;
  int i;
  int j;
  
  if((pResult->size + pAppend->size) >= pResult->capacity)
    {
      pResult->capacity *= 2;
      temp = (char*)malloc(sizeof(char*) * pResult->capacity);

      if(temp == NULL)
	{
	  return FAILURE;
	}

      for(j = 0; j <= pResult->size; j++)
	{
	  temp[j] = pResult->data[j]; 
	}
   
      free(pResult->data);
      pResult->data = temp;	   
    }

  i = 0;
  while(pResult->data[i] != '\0')
  {
    i++;
  }

  
  j = 0;

 while(pAppend->data[j] != '\0')
    {
      pResult->data[i] = pAppend->data[j];
      i++;
      j++;
    }


  pResult->data[i] = '\0';
  pResult->size += pAppend->size;

  

  return SUCCESS;
}

Boolean my_string_empty(MY_STRING hMy_string)
{
  My_string *pMy_string = (My_string*) hMy_string;
  
  if(pMy_string->size == 0)
  {
    return TRUE;
  }
  else
  {
    return FALSE;
  }
}

void my_string_assignment(Item* pLeft, Item Right)
{
  My_string *pRight = (My_string*) Right;
  My_string *ppLeft;

  ppLeft = (My_string*) malloc(sizeof(My_string));
  *pLeft = ppLeft;

  if(ppLeft != NULL)
  {
    ppLeft->size = pRight->size;
    ppLeft->capacity = pRight->capacity;

    ppLeft->data = (char*) malloc(sizeof(char) * pRight->capacity);
    if(ppLeft->data == NULL)
    {
      free(ppLeft);
      ppLeft = NULL;
    }


    strcpy(ppLeft->data, pRight->data);
   /* char *x = ppLeft->data;
    while(*pRight->data) {
      *ppLeft->data = *pRight->data;
      ppLeft->data++;
      pRight->data++;
    }
    *ppLeft->data = '\0';
    ppLeft->data = x;*/

  }
}

void my_string_destroy(Item *pItem){
  // write function definition
  My_string *pMy_string = (My_string*) *pItem;

 
  free(pMy_string->data);
  pMy_string->data = NULL;
  free(pMy_string);
  *pItem = NULL;
}
