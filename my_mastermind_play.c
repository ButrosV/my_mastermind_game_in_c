/*
    Game of guessing 4-number combination - My Mastermind, Programmer: Butros, 15-Oct-2024.
    Define main global variables.
    From 'main' call:
    - required core functions defined in my_mastermind_core.c and my_mastermind_helpers.c
    - countdown game rounds and print corresponding messages.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "my_mastermind.h"

const char* welcome_msg = "Will you find the secret code in 10 attempts?\nPlease enter a valid guess:\n\t\
non-repeating numbers from 0-8.\n\
If you wish, next time use flags -t or -c to toggle attempt times or define correct code.";
const char* winner_msg = "Congratz! You did it!\n";
const char* well_placed_msg = "Well placed pieces: ";
const char* misplaced_msg = "Misplaced pieces: ";

int game_rounds = DEFAULT_ROUNDS;
int* game_rounds_ptr = &game_rounds;
char combination[DEFAULT_COMBINATION_LEN + 1];
char(* combination_ptr)[DEFAULT_COMBINATION_LEN + 1] = &combination;
int current_round = 0;
int* current_rount_ptr = &current_round;
int missplaced;
int* missplaced_ptr = &missplaced;
int well_placed;
int* well_placed_ptr = &well_placed;
char guess[MAX_GUESS_LEN];
char(* guess_ptr)[MAX_GUESS_LEN] = &guess;

int main(int argc, char** argv)
{
    printf("%s", welcome_msg);

    if (argc > 1) {
    check_flags(argv, argc, game_rounds_ptr, *combination_ptr);
    }
    if (*combination_ptr[0] == '\0') {  // generate random code if not provided in previous line via flag
    random_code_generator(DEFAULT_COMBINATION_MIN, DEFAULT_COMBINATION_MAX, DEFAULT_COMBINATION_LEN, *combination_ptr);
    }

    printf("\n---\nRound %d\n", *current_rount_ptr);
    while (*current_rount_ptr < game_rounds) {    
        int char_count = master_reader(*guess_ptr);
        if (char_count == -1) {
            return 0;
            }
        if (input_verification(*guess_ptr) == 0) {
            *current_rount_ptr += 1;
            if (guess_correctness(*guess_ptr, *combination_ptr, missplaced_ptr, well_placed_ptr) == 0) {
                printf("%s", winner_msg);
                return 0;
            }
            printf("%s %d\n%s %d\n---\n",well_placed_msg, *well_placed_ptr, misplaced_msg, *missplaced_ptr);
            if (*current_rount_ptr < game_rounds) {
                printf("Round %d\n", *current_rount_ptr);
            }
            }
            else {
                printf("Wrong input!\n");
            }
    }
    printf("Lost this time... Correct combination was %s.\n", *combination_ptr);
    return 0;
}
