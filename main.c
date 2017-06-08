#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
#define MAX 100

int main(int argc, char *argv[])
{
    MY_STRING str_array[MAX];
    int i;

    for(i = 0; i < MAX; i++)
    {
        str_array[i] = NULL;
    }

    str_array[0] = my_string_init_c_string("COPY ME!");

    for(i = 1; i < MAX; i++)
    {
        my_string_assignment(&str_array[i], str_array[i-1]);
    }
    
    printf("%s\n", my_string_get_data(str_array[MAX-1]));

    for(i = 0; i < MAX; i++)
    {
        my_string_destroy(&str_array[i]);
    }

    return 0;
}


