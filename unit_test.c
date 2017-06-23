#include "unit_test.h"

int main(int argc, char* argv[])
{
   Status (*tests[])(char*, int) =
       { 
            test_init_default_returns_nonNULL,
            test_get_size_on_init_default_returns_0,
            test_init_c_string_length_is_strlength,
            test_get_capacity_returns_capacity,
            test_get_size_returns_size,
            test_get_data_returns_nonNULL,
            test_compare_returns_0_for_equal_strings,
            test_compare_returns_less_than_0_if_first_string_is_bigger,
            test_compare_returns_greater_than_0_if_first_string_is_smaller,
            test_string_extraction_contains_null_byte,
            test_string_insertion_writes_string,
            test_string_push_back_increases_size,
            test_string_push_back_appends_appropriate_char,
            test_string_push_back_returns_SUCCESS_for_good_push,
            test_string_pop_back_decreases_size,
            test_string_pop_back_pops_appropriate_char,
            test_string_pop_back_returns_FAILURE_for_empty_string,
            test_string_pop_back_returns_SUCCESS_for_good_pop,
            test_string_at_returns_a_char_pointer,
            test_string_at_returns_the_appropriate_char_pointer,
            test_string_concat_increases_size_appropriately,
            test_string_concat_contains_NULL_byte,
            test_string_empty_returns_TRUE_for_empty_string,
            test_string_empty_returns_FALSE_for_nonempty_string,
            test_string_destroy_destroys
       };
   int number_of_functions = sizeof(tests) / sizeof(tests[0]);
   int i;
   char buffer[500];
   int success_count = 0;
   int failure_count = 0;

   for(i=0; i<number_of_functions; i++)
   {
      if(tests[i](buffer, 500) == FAILURE)
      {
         printf("FAILED: Test %d failed miserably\n", i);
         printf("\t%s\n", buffer);
         failure_count++;
      }
      else
      {
// printf("PASS: Test %d passed\n", i);
 	// printf("\t%s\n", buffer);
         success_count++;
      }
   }
   printf("Total number of tests: %d\n", number_of_functions);
   printf("%d/%d Pass, %d/%d Failure\n", success_count,
   number_of_functions, failure_count, number_of_functions);
   return 0;
}


