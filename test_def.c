#include "unit_test.h"


Status test_init_default_returns_nonNULL(char* buffer, int length)
{
   MY_STRING hString = NULL;

   hString = my_string_init_default();

   if(hString == NULL)
   {
      my_string_destroy(&hString);
      strncpy(buffer, "test_init_default_returns_nonNULL\n"
                   "my_string_init_default returns NULL\n", length);
      return FAILURE;
   }
   else
   {
      my_string_destroy(&hString);
      strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
      return SUCCESS;
   }
}

Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
   MY_STRING hString = NULL;
   Status status;

   hString = my_string_init_default();

   if(my_string_get_size(hString) != 0)
   {
      status = FAILURE;
      printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
      strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
                   "Did not receive 0 from get_size after init_default\n", length);
   }
   else
   {
      status = SUCCESS;
      strncpy(buffer, "test_get_size_on_init_default_returns_0\n", length);
   }

   my_string_destroy(&hString);
   return status;
}

Status test_init_c_string_length_is_strlength(char* buffer, int length)
{
   MY_STRING hString = NULL;
   Status status;

   hString = my_string_init_c_string("hello");

   if(my_string_get_size(hString) != strlen("hello"))
   {
      status = FAILURE;
      strncpy(buffer, "test_init_c_string_length_is_strlength\n"
                        "my_string_init_c_string length does not match length of string\n", length);
   }

   else
   {
      status = SUCCESS;
      strncpy(buffer, "test_init_c_string_length_is_strlength\n", length);
   }

   my_string_destroy(&hString);
   return status;
}

Status test_get_capacity_returns_capacity(char* buffer, int length)
{
   MY_STRING hString = NULL;
   Status status;
   int n;

   hString = my_string_init_c_string("Y");
   n = my_string_get_capacity(hString);

   if(n != 2)
   {
      status = FAILURE;
      strncpy(buffer, "test_get_capacity_returns_capacity\n"
               "my_string_get_capacity does not return the correct capacity\n", length);
   }
   else
   {
      status = SUCCESS;
      strncpy(buffer, "test_get_capacity_returns_capacity\n", length);
   }

   my_string_destroy(&hString);
   return status;
}

Status test_get_size_returns_size(char* buffer, int length)
{
   MY_STRING hString = NULL;
   Status status;
   int n;

   hString = my_string_init_c_string("Y");
   n = my_string_get_size(hString);

   if(n != 1)
   {
      status = FAILURE;
      strncpy(buffer, "test_get_size_returns_size\n"
               "my_string_get_size does not return the correct size\n", length);
   }
   else
   {
      status = SUCCESS;
      strncpy(buffer, "test_get_size_returns_size\n", length);
   }

   my_string_destroy(&hString);
   return status;

}

Status test_get_data_returns_nonNULL(char* buffer, int length)
{
   MY_STRING hString = NULL;
   Status status;
   char *ch;

   hString = my_string_init_c_string("hello");
   ch = my_string_get_data(hString);

   if(ch == NULL)
   {
      status = FAILURE;
      strncpy(buffer, "test_get_data_returns_nonNULL\n"
                        "my_string_get_data returns NULL\n", length);
   }
   else
   {
      status = SUCCESS;
      strncpy(buffer, "test_get_data_returns_nonNULL\n", length);
   }

   my_string_destroy(&hString);
   return status;

}

Status test_compare_returns_0_for_equal_strings(char* buffer, int length)
{
   MY_STRING hString1 = NULL;
   MY_STRING hString2 = NULL;
   Status status;
   int num;

   hString1 = my_string_init_c_string("hello");
   hString2 = my_string_init_c_string("hello");

   num = my_string_compare(hString1, hString2);

   if(num != 0)
   {
      status = FAILURE;
      strncpy(buffer, "test_compare_returns_0_for_equal_strings\n"
                        "my_string_compare doesn't returns 0 for equal strings\n", length);
   }
   else
   {
      status = SUCCESS;
      strncpy(buffer, "test_compare_returns_0_for_equal_strings\n", length);
   }

   my_string_destroy(&hString1);
   my_string_destroy(&hString2);
   return status;
}

Status test_compare_returns_less_than_0_if_first_string_is_bigger(char* buffer, int length)
{
   MY_STRING hString1 = NULL;
   MY_STRING hString2 = NULL;
   Status status;
   int num;

   hString1 = my_string_init_c_string("hello!");
   hString2 = my_string_init_c_string("hello");

   num = my_string_compare(hString1, hString2);

   if(num >= 0)
   {
      status = FAILURE;
      strncpy(buffer, "test_compare_returns_greater_than_0_if_first_string_is_bigger\n"
                        "my_string_compare doesn't return greater than 0 if first string is bigger\n", length);
   }
   else
   {
      status = SUCCESS;
      strncpy(buffer, "test_compare_returns_greater_than_0_if_first_string_is_bigger\n", length);
   }

   my_string_destroy(&hString1);
   my_string_destroy(&hString2);
   return status;
}

Status test_compare_returns_greater_than_0_if_first_string_is_smaller(char* buffer, int length)
{
   MY_STRING hString1 = NULL;
   MY_STRING hString2 = NULL;
   Status status;
   int num;

   hString1 = my_string_init_c_string("hello");
   hString2 = my_string_init_c_string("hello!");

   num = my_string_compare(hString1, hString2);

   if(num <= 0)
   {
      status = FAILURE;
      strncpy(buffer, "test_compare_returns_less_than_0_if_first_string_is_smaller\n"
                        "my_string_compare doesn't return less than 0 when first string is smaller\n", length);

   }
   else
   {
      status = SUCCESS;
      strncpy(buffer, "test_compare_returns_less_than_0_if_first_string_is_smaller\n", length);
   }

   my_string_destroy(&hString1);
   my_string_destroy(&hString2);
   return status;

}

Status test_string_extraction_contains_null_byte(char* buffer, int length)
{
   MY_STRING hString = NULL;
   Status status = FAILURE;
   char *ch;
   int i = 0;

   hString = my_string_init_default();
   printf("Please type a string\n");
   my_string_extraction(hString, stdin);
   ch = my_string_get_data(hString);

   while(i <= my_string_get_size(hString))
   {  

      if(ch[i] == '\0')
      {
         status = SUCCESS;
         strncpy(buffer, "test_string_extraction_contains_null_byte\n", length);
      }
      i++;
   }

   if(status == FAILURE)
   {
      strncpy(buffer, "test_string_extraction_contains_null_byte\n"
                        "my_string_extraction does not contain null byte", length);
   }

   my_string_destroy(&hString);
   return status;
}

Status test_string_insertion_writes_string(char* buffer, int length)
{
   MY_STRING hString = NULL;
   Status status;
   int i;

   hString = my_string_init_c_string("hello");

   i = my_string_insertion(hString, stdout);

      if(i)
      {
         status = SUCCESS;  
         strncpy(buffer, "test_string_insertions_writes_string\n", length);
      }
      else
      {
         status = FAILURE;
         strncpy(buffer, "test_string_insertions_writes_string\n"
                           "my_string_insertion does not write string", length);
      }
   
   my_string_destroy(&hString);
   return status;
}

Status test_string_push_back_increases_size(char* buffer, int length)
{
   MY_STRING hString = NULL;
   Status status;
   int pre;
   int post;

   hString = my_string_init_c_string("hello");

   pre = my_string_get_size(hString);
   my_string_push_back(hString, '!');
   post = my_string_get_size(hString);

      if(post > pre)
      {
         status = SUCCESS;  
         strncpy(buffer, "test_string_push_back_increases_size\n", length);
      }
      else
      {
         status = FAILURE;
         strncpy(buffer, "test_string_push_back_increases_size\n"
                           "my_string_push_back does not increase size", length);
      }
   
   my_string_destroy(&hString);
   return status;
}

Status test_string_push_back_appends_appropriate_char(char* buffer, int length)
{
   MY_STRING hString = NULL;
   Status status;
   char ch = '!';
   char *str;

   hString = my_string_init_c_string("hello");
   my_string_push_back(hString, ch);

   str = my_string_get_data(hString);
   

      if(str[my_string_get_size(hString)-1] == ch)
      {
         status = SUCCESS;  
         strncpy(buffer, "test_string_push_back_appends_appropriate_char\n", length);
      }
      else
      {
         status = FAILURE;
         strncpy(buffer, "test_string_push_back_appends_appropriate_char\n"
                           "my_string_push_back does not append appropriate char", length);
      }
   
   my_string_destroy(&hString);
   return status;
}

Status test_string_pop_back_decreases_size(char* buffer, int length)
{
   MY_STRING hString = NULL;
   Status status;
   int pre;
   int post;

   hString = my_string_init_c_string("hello!");

   pre = my_string_get_size(hString);
   my_string_pop_back(hString);
   post = my_string_get_size(hString);

      if(post < pre)
      {
         status = SUCCESS;  
         strncpy(buffer, "test_string_pop_back_decreases_size\n", length);
      }
      else
      {
         status = FAILURE;
         strncpy(buffer, "test_string_pop_back_decreases_size\n"
                           "my_string_pop_back does not decrease size", length);
      }
   
   my_string_destroy(&hString);
   return status;

}

Status test_string_pop_back_pops_appropriate_char(char* buffer, int length)
{
   MY_STRING hString = NULL;
   Status status;
   char *str1;
   char *str2;
   

   hString = my_string_init_c_string("hello!");

   str1 = my_string_get_data(hString);
   str1[my_string_get_size(hString) - 1] = '\0';
   my_string_pop_back(hString);
   str2 = my_string_get_data(hString);

   if(str1 == str2)
      {
         status = SUCCESS;  
         strncpy(buffer, "test_string_pop_back_pops_appropriate_char\n", length);
      }
      else
      {
         status = FAILURE;
         strncpy(buffer, "test_string_pop_back_pops_appropriate_char\n"
                           "my_string_pop_back does not pop appropriate char", length);
      }
   
   my_string_destroy(&hString);
   return status;
}

Status test_string_at_returns_a_char_pointer(char* buffer, int length)
{
   MY_STRING hString = NULL;
   Status status;
   char *pCh;

   hString = my_string_init_c_string("hello!");
   pCh = my_string_at(hString, 0);

   if(*pCh)
      {
         status = SUCCESS;  
         strncpy(buffer, "test_string_at_returns_a_char_pointer\n", length);
      }
      else
      {
         status = FAILURE;
         strncpy(buffer, "test_string_at_returns_a_char_pointer\n"
                           "my_string_pop_back does not return a char pointer", length);
      }
   
   my_string_destroy(&hString);
   return status;
}

Status test_string_at_returns_the_appropriate_char_pointer(char* buffer, int length)
{
   MY_STRING hString = NULL;
   Status status;
   char *pCh;

   hString = my_string_init_c_string("hello!");
   pCh = my_string_at(hString, 0);

   if(*pCh == 'h')
      {
         status = SUCCESS;  
         strncpy(buffer, "test_string_at_returns_the_appropriate_char_pointer\n", length);
      }
      else
      {
         status = FAILURE;
         strncpy(buffer, "test_string_at_returns_the_appropriate_char_pointer\n"
                           "my_string_pop_back does not return the appropriate char pointer", length);
      }
   
   my_string_destroy(&hString);
   return status;
}

