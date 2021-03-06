#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

int main(int argc, char *argv[])
{
   MY_STRING hMy_string = NULL;
   MY_STRING hMy_other_string = NULL;
   char ch;

    if(my_string_empty(hMy_string))
      printf("EMPTY\n");
  
  hMy_string = my_string_init_c_string("Hello World");
  hMy_other_string = my_string_init_c_string("Goodbye World");
  
  my_string_push_back(hMy_string, '!');
  printf("%s\n", my_string_get_data(hMy_string));
  
  my_string_pop_back(hMy_string);
  printf("%s\n", my_string_get_data(hMy_string));

  ch = *my_string_at(hMy_string, 1);
  printf("%cvil ", ch);
  ch = *my_string_at(hMy_string, 4);
  printf("%cctopus\n", ch);
  
  my_string_concat(hMy_string, hMy_other_string);
  printf("%s\n", my_string_get_data(hMy_string));
  
  if(!my_string_empty(hMy_string))
    printf("NOT EMPTY\n");
  
   my_string_destroy(&hMy_string);
   my_string_destroy(&hMy_other_string);
  
  return 0;
}
