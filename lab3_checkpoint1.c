#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

int main(int argc, char *argv[])
{
  printf("hello world\n");
  MY_STRING hMy_string = NULL;
  FILE *fp;
  
  hMy_string = my_string_init_default();
  fp = fopen("simple.txt", "r");

   while(my_string_extraction(hMy_string, fp))
    {
      my_string_insertion(hMy_string, stdout);
      printf("\n");
      if(fgetc(fp) == ' ')
	{
	  printf("Found a space after the string\n");
	  
	}
	}
    printf("goodbye");
   my_string_destroy(&hMy_string);
  return 0;
}
