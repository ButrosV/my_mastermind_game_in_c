# My Mastermind in C
***

## Goal of the project
Replicate Mastermind game behavior in C.

**Mastermind Game Rules:**

1. **Objective:** Guess the secret code, which is made up of 4 distinct pieces chosen from 9 colors (0-8).
2. **Code Format:** The secret code consists of 4 digits, each between '0' and '8'. A piece cannot be repeated in the code.
3. **Attempts:** You have 10 attempts to guess the secret code (can be adjusted with the `-t` option).
4. **Feedback:** After each guess:
   - **Well placed pieces**: Correct pieces in the correct positions.
   - **Misplaced pieces**: Correct pieces but in the wrong positions.
5. **Winning:** If you guess the code correctly, the game ends, and you win.
6. **Custom Code:** Use `-c [CODE]` to specify a secret code. If not provided, the code is randomly generated.
7. **End of Game:** The game stops either when you find the code or when you run out of attempts.

- No LLMs used apart from generating the game description above:)

## Pseudo logic
Define my_mastermind helper and my_mastermind core business functions. Business functions deal with:
- checking for presence of game flags, storing their values as global variables in main file
- verifying user inputs when launching the game or in-game for compliance with Mastermind rules
- reading user in-game inputs via standard input
- comparing user guess with correct answers and store relevant misplaced/well placed counts as global variables

Main my_mastermind_play.c file:
- Define key global variables.
- from 'main' function call required core functions defined in my_mastermind_core.c and my_mastermind_helpers.c
- from 'main' function countdown game rounds and print corresponding messages.

**Makefile**: to compile relevant files into a target ./my_mastermind program

## Installation
**Dependencies**:
- GCC compiler
- make support for GNU

Download/pull files:
```
.
├── Makefile
├── README.md
├── my_mastermind_play.c
├── my_mastermind.h
├── my_mastermind_core_play.c
└── my_mastermind_helpers_play.c
```
- Depending if you use Windows or Linux systems, comment/uncomment relevant cleanup calls in Makefile (rows 18 or 19 and 23 or 24)
- From folder containing all above files run following terminal command to compile program:
 ```
make
```
to remove .o and .exe files after the use of program, run from the terminal
 ```
make fclean
```

## Usage
run program to start the game with default settings (10 rounds, random code)
```
 ./my_mastermind
```
or add flags with corresponding values:
- -t NUM // change round count
- -c 4-digit NUM // change correct response code to your preferred value
```
 ./my_mastermind -c 1234 -t 3
```
***
### Author
Butros
***