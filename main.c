#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "my_string.h"
#include "my_vect.h"
#include "my_tree.h"
#include "generic.h"
#define MAX 100

int main(int argc, char *argv[])
{/********************************************
    game variables
    *****************************************/
int word_size;
Status ws = FAILURE;

int guesses;
Status gs = FAILURE;

char cheats[4];
Boolean display_cheating;
Status cs = FAILURE;

STR_VECT hList;

MY_STRING hKey;

MY_STRING hTemp_key;

MY_STRING hTemp_string;

Tree_node *pTemp_node;

Tree_node *pMax;

char theGuess;

int max;
int j;

Status guessFlag = FAILURE;

Tree *pTree;






/********************************************/

    STR_VECT vect_array[30];
    MY_STRING hString;
    FILE *dictionary;
    int i;

    dictionary = fopen("dictionary.txt", "r");

    hString = my_string_init_default();

    for(i = 0; i < 30; i++)
    {
        vect_array[i] = my_vect_init_default();
    }

    
        while(my_string_extraction(hString, dictionary))
        {

            i = my_string_get_size(hString);
            if(i != 0)
            {
                 my_vect_add_string(hString, vect_array[i]);
            }

            if(fgetc(dictionary) == ' ')
            {
               /*unfortunately this is neccessary for the way extraction function currenty operates
                    infinite loop without it*/     
            }
        }
  

    for(i = 1; i < 30; i++)
    {
        printf("%d letter words:  %d\n",i , my_vect_get_size(vect_array[i]));
    }

    fclose(dictionary);



/***************************************************************************/



    printf("\n\n\n*** The Evil Hangman Game ***\n\n\n");
    printf("What size word would you like to play with?\n");

    while(ws == FAILURE)
    {
        scanf("%d", &word_size);

        if(word_size > 0)
        {
            if(word_size <= 29 &&
                my_vect_get_size(vect_array[word_size]) != 0)
            {
                ws = SUCCESS;
            }
            else
            {
                printf("\nI'm sorry, unable to find a word of that size.\n"
                        "Please try a different word size.\n"); 
            }

        }
        else
            printf("\nInvalid input.\n"
                    "Please choose a positive integer that is greater than 0.\n");

    }

    printf("\nExcellent, and how many guesses do you think you will need?\n");

    while(gs == FAILURE)
    {
        scanf("%d", &guesses);
        if(guesses > 0)
        {
            gs = SUCCESS;
        }
        else
        {
            printf("\nInvalid input.\n"
                    "Please enter an integer that is greater than 0.\n");
        }
    }
    printf("\nGreat! Just one more thing...\n\n"
            "Would you like to see me cheating?\n");


    while(cs == FAILURE)
    {
        scanf("%s", cheats);
        uppercase(cheats);
        if(strcmp(cheats, "YES") == 0)
        {
            cs = SUCCESS;
            display_cheating = TRUE;
        }
        else if(strcmp(cheats, "NO") == 0)
        {
            cs = SUCCESS;
            display_cheating = FALSE;
        }
        else
        {
            printf("\nInvalid input.\n"
                    "Please enter a simple yes or no.\n");
        }
    }

    printf("\nAlright, we are ready to play.\n"
            "Prepare to lose!!!\n\n\n\n");
    
    my_vect_copy_vector(&hList, vect_array[word_size]);
    
    hKey = my_string_init_default();
    for(i = 0; i < word_size; i++)
    {
        my_string_push_back(hKey, '_');    
    }
    
    pTree = my_tree_init_default();

    while(guesses > 0)
    {
        printf("You have %d guesses left.", guesses);
        if(display_cheating)
        {
            printf("\nRemaining words: %d", my_vect_get_size(hList));
        
           /* uncomment to see remaining words

           for(i = 0; i < my_vect_get_size(hList); i++)
            {
                printf("   %s   ", my_vect_get_string(hList, i));
            }*/
        }   
        printf("\n\n");

        printf("\t%s\n\n", my_string_get_data(hKey));

        printf("Which character should I reveal?\n");

        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
        
        theGuess = getchar();
        theGuess = tolower(theGuess);

       /* printf("\n\nbefore destroy\n");
        if(pTree->root != NULL)
        {
            printf("root: %s\n\n", my_string_get_data(pTree->root->key));
        }*/
        my_tree_destroy_nodes(pTree->root);
        pTree->root = NULL;
        
        /*printf("after destory\n\n\n");

        printf("hList size: %d\n\n\n", my_vect_get_size(hList));*/
        for(i = 0; i < my_vect_get_size(hList); i++)
        {  
            hTemp_key = my_string_init_default();
            hTemp_string = my_string_init_c_string(my_vect_get_string(hList, i));
            for(j = 0; j < word_size; j++)
            {
                if(*my_string_at(hTemp_string, j) == theGuess)
                {
                    my_string_push_back(hTemp_key, theGuess);
                }
                else if(*my_string_at(hTemp_string, j) == *my_string_at(hKey, j))
                {
                    my_string_push_back(hTemp_key, *my_string_at(hTemp_string, j));
                }
                else
                {
                    my_string_push_back(hTemp_key, '_');
                }
            }
            
           
           
           /* printf("%s\n", my_string_get_data(hTemp_string));
            printf("%s\n", my_string_get_data(hTemp_key));*/
            
            if((pTemp_node = my_tree_find_key(pTree->root, hTemp_key)) != NULL)
            {
                my_vect_add_string(hTemp_string, pTemp_node->words);   
            }
            
            if(my_tree_find_key(pTree->root, hTemp_key) == NULL)
            {
                pTemp_node = my_tree_insert_key(pTree, hTemp_key);
              //  printf("found key:\n");
                my_vect_add_string(hTemp_string, pTemp_node->words); 
              //  printf("%s\n", my_string_get_data(hTemp_key));
            }

            my_string_destroy(&hTemp_key);
            my_string_destroy(&hTemp_string);
        }
     //   printf("The tree:\n");
       // my_tree_print(pTree->root);

        printf("\n\n");

    

        max = 0;
        pMax = NULL;
        my_tree_largest_key(pTree->root, &pMax, &max);
        for(i = 0; i < word_size; i++)
        {          
            if(theGuess == *my_string_at(pMax->key, i))
            {    
                guessFlag = SUCCESS;
            }
        }

        /*printf("\n\npMax:  %s\n", my_string_get_data(pMax->key));
        printf("max: %d\n", max);
        printf("vector size: %d\n\n\n", my_vect_get_size(pMax->words));
        */
            

        my_vect_destroy(&hList);
        my_vect_copy_vector(&hList, pMax->words);
        my_string_destroy(&hKey);
        my_string_assignment(&hKey, pMax->key);


        if(guessFlag == FAILURE)
        {
            guesses--;
            printf("I'm sorry, %c is not in the word.\n\n", theGuess);
        }
        else
        {
            guessFlag = FAILURE;
            printf("Lucky guess!\n");
        }

        if(guesses == 0)
        {
            printf("You are out of guesses...looks like you lost!\n"
                    "The word was %s.\n\n", my_vect_get_string(pMax->words, 0));
        }

        if(my_string_compare(hKey, my_vect_get_MY_STRING(pMax->words, 0)) == 0)
        {
            printf("I can't believe it...it looks like you have won!\n\n");
            guesses = 0;
        }
    }

    my_string_destroy(&hKey);
    my_vect_destroy(&hList);

    my_tree_destroy_nodes(pTree->root);
    free(pTree);

    my_string_destroy(&hString);
    for(i = 0; i < 30; i++)
    {
        my_vect_destroy(&vect_array[i]);   
    }
    return 0;
}


