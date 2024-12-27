/*
    Helper functions for My Mastermind, Programmer: Butros, 15-Oct-2024.
    Function list:
    int char_count(char* array);
    void copy_string(char* destination, char* source);
    int* allocate_int_array_memory(int int_num);
    char* allocate_text_memory(int char_num);
    void random_code_generator(char min_digit, char max_digit, int combination_len, char* combination_p);
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "my_mastermind.h"


int char_count(char* array)
/**
 * A helper function to count characters
 * @param array pinter to an array of characters (string)
 * @return int of character count
 */
{
    int count = 0;
    while (array[count] != '\0') 
    {
        count++;
    }
    return count;
}


void copy_string(char* destination, char* source)
/**
 * A helper to copy a string
 * @param destination a pointer to destination location, vhere string will be copied
 * @param source a pointer to string that will be copied
 * @return void
 */
{
    char* temp_dest = destination;
    while (*source) 
    {
        *temp_dest = *source;
        temp_dest++;
        source++;
    }
    return;
}


void random_code_generator(char min_digit, char max_digit, int combination_len, char* combination_p)
/**
 * Generate an array of random digits and store them in user specified pointer address as char array
 * 1) set random seed based on current time
 * 2) generate random digits within specified range provided in parameters
 * 3) iterate adding digit by digit and verify that there are no duplicate digits
 * @param min_digit lower range (inclusive) of random digit output 
 * @param max_digit upper range (inclusive) of random digit output
 * @param combination_len number of consecutive random digits that will be stored as output
 * @param combination_p pointer to character array where output char array is stored  
 * @return void
 */
{
    srand(time(NULL));
    int temp_rand_n;
    temp_rand_n = rand() % (atoi(&max_digit) + 1 - atoi(&min_digit)) + atoi(&min_digit);  // min_digit operations redundant, if min_digit = 0;
    combination_p[0] = temp_rand_n + '0';
    for (int outer_index = 1; outer_index < combination_len; outer_index++) {
        temp_rand_n = rand() % (atoi(&max_digit) + 1 - atoi(&min_digit)) + atoi(&min_digit);
        for (int nested_index = 0; nested_index < outer_index; nested_index++) {
            while (temp_rand_n + '0' == combination_p[nested_index]) {
                // printf("entered while statement, found duplicate: %c at index: %d\n", temp_rand_n + '0', index);  // for testing
                temp_rand_n = rand() % (atoi(&max_digit) + 1 - atoi(&min_digit)) + atoi(&min_digit);
                // printf("inside while statement generated new temp rand: %c\n", temp_rand_n + '0');  // for testing
                nested_index = 0;
            }
        }
        combination_p[outer_index] = temp_rand_n + '0';
    }
}
