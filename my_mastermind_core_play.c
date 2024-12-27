/*
    Core functionality functions for My Mastermind, Programmer: Butros, 15-Oct-2024.
    Function list:
    void check_flags(char** argv, int argc, int* round_var, char* combination_var);
    int input_verification(char* guess_input);
    int master_reader(char* guess);
    int guess_correctness(char* player_guess, char* correct_combination, int* missplaced_p, int* well_placed_p);
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "my_mastermind.h"
    

void check_flags(char** argv, int argc, int* round_var, char* combination_var)
/**
 * 1) Check for presence of 'FLAG_ATTEMPTS' and 'FLAG_CODE' flag's presence in terminal input;
 *      (flag values defined in my_mastermind.h file)
 * 2) Verify if terminal input values after flags comply with Mastermind game input requirements;
 * 3) change referenced global/higher level variables accordingly.
 * @param argv list of terminal inputs
 * @param argc count of terminal inputs
 * @param round_var global/higher level variable referring to round number flag ('FLAG_ATTEMPTS')
 * @param combination_var global/higher level variable referring to initial combination flag ('FLAG_CODE')
 * @return void
 */
{
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], FLAG_ATTEMPTS) == 0) {
            if (atoi(argv[i + 1]) > 0) {
                *round_var = atoi(argv[i + 1]);
            }     
        }
        if (strcmp(argv[i], FLAG_CODE) == 0) {
            if (input_verification(argv[i + 1]) == 0) {
                copy_string(combination_var, argv[i + 1]);
            }
        }
    }
}


int input_verification(char* input_combination)
/**
 * Verify if input array conforms with Mastermind game requirements:
        - input length is 4 numbers from 0 to 8
        - no duplicate entries
 * @param input_combination pointer to a character array with user input
 * @return '0' if input conforms with Mastermind game requirements  
 *       or '1' if it does not
 */
{
    int index_outer = 0;
    while (input_combination[index_outer] != '\0') {
        int index_inner = index_outer;
        int duplicates = 0;
        while (input_combination[index_inner] != '\0') {
            if (index_inner > 3 || input_combination[index_inner] < DEFAULT_COMBINATION_MIN || 
            input_combination[index_inner] > DEFAULT_COMBINATION_MAX) {
                return  1;
            }
            if (input_combination[index_outer] == input_combination[index_inner]) {
                duplicates++;
                if (duplicates > 1) {
                    return  1;
                }
            }
            index_inner++;
        }
        index_outer++;
    }
    return 0;
}

int master_reader(char* guess)
/**
 * Read standard input from terminal or exit program if ctrl+d called
 * @param guess pointer to an array where characters red from standard input are stored
 * @return count of red characters, -1 if ctrl+d called 
 *      or -2 if standard input read issues encountered
 */
{
    char buffer = 0;
    int bytes_red;
    int char_count = 0;    
    while ((bytes_red = read(0, &buffer, 1)) >= -1 && buffer != '\n') {
        if (buffer == 4) {  // does not work on windows, use buffer == 4 (EOT in ascii)            
            return -1; // consider adding printf("EOF\n");
        }
        guess[char_count] = buffer;
        char_count++;
        guess[char_count] = '\0';
        if (char_count > 4) {
            buffer = '\n';
        }
    }
    if (bytes_red < 0) {
        return -2;
    }
    return char_count;
}


int guess_correctness(char* player_guess, char* correct_combination, int* missplaced_p, int* well_placed_p)
/**
 * 1) Compare player guess with correct combination, 
 * 2) update Well placed and Misplaced piece counts accordingly
 * @param player_guess pointer to an array storing player guess
 * @param correct_combination pointer to an array storing correct combination
 * @param missplaced_p pointer to Misplaced piece counts, 
 *                           reset to '0' after function launch
 * @param well_placed_p pointer to  Well placed piece counts, 
 *                           reset to '0' after function launch
 * @return '0' if all pieces match (are guessed correctly)  
 *       or '1' otherwise
 */
{
    int index_outer = 0;
    *well_placed_p = 0; 
    *missplaced_p = 0;
    while (player_guess[index_outer] != '\0') {
        if (player_guess[index_outer] == correct_combination[index_outer]) {
            *well_placed_p += 1;
        }
        int index_nested = 0;
        while (correct_combination[index_nested] != '\0') {
            if (player_guess[index_outer] == correct_combination[index_nested] 
            && player_guess[index_outer] != correct_combination[index_outer]) {
                *missplaced_p += 1;
            }
            index_nested++;
        }
        index_outer++;
    }
    if (*well_placed_p == DEFAULT_COMBINATION_LEN)
        return 0;
    else 
        return 1;
}
