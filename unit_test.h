#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include "my_string.h"

// my_string_init_default tests

Status test_init_default_returns_nonNULL(char* buffer, int length);
Status test_get_size_on_init_default_returns_0(char* buffer, int length);

// my_string_init_c_string tests

Status test_init_c_string_length_is_strlength(char* buffer, int length);

// my_string_get_capacity tests

Status test_get_capacity_returns_capacity(char* buffer, int length);

// my_string_get_size tests

Status test_get_size_returns_size(char* buffer, int length);

// my_string_get_data tests

Status test_get_data_returns_nonNULL(char* buffer, int length);

// my_string_compare tests

Status test_compare_returns_0_for_equal_strings(char* buffer, int length);
Status test_compare_returns_less_than_0_if_first_string_is_bigger(char* buffer, int length);
Status test_compare_returns_greater_than_0_if_first_string_is_smaller(char* buffer, int length);

// my_string_extraction tests

Status test_string_extraction_contains_null_byte(char* buffer, int length);

// my_string_insertion tests

Status test_string_insertion_writes_string(char* buffer, int length);

// my_string_push_back tests

Status test_string_push_back_increases_size(char* buffer, int length);
Status test_string_push_back_appends_appropriate_char(char* buffer, int length);

//Status my_string_pop_back tests

Status test_string_pop_back_decreases_size(char* buffer, int length);
Status test_string_pop_back_pops_appropriate_char(char* buffer, int length);

// my_string_at tests

Status test_string_at_returns_a_char_pointer(char* buffer, int length);
Status test_string_at_returns_the_appropriate_char_pointer(char* buffer, int length);

// my_string_concat tests

// my_string_empty tests

// my_string_destroy tests
#endif
