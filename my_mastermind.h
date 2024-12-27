#define MAX_GUESS_LEN 100
#define DEFAULT_ROUNDS 10
#define DEFAULT_COMBINATION_LEN 4
#define DEFAULT_COMBINATION_MIN '0'
#define DEFAULT_COMBINATION_MAX '8'
#define FLAG_ATTEMPTS "-t"
#define FLAG_CODE "-c"

// HELPER FUNCTIONS
int char_count(char* array);

void copy_string(char* destination, char* source);
void random_code_generator(char min_digit, char max_digit, int combination_len, char* combination_p);

// CORE FUNCTIONS
void check_flags(char** argv, int argc, int* round_var, char* combination_var);
int input_verification(char* guess_input);
int master_reader(char* guess);
int guess_correctness(char* player_guess, char* correct_combination, int* missplaced_p, int* well_placed_p);
