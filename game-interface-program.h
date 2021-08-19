
#ifndef GAME_INTERFACE_PROGRAM
#define GAME_INTERFACE_PROGRAM

#include "include-define-header.h"

extern const char* colors[];

bool input_field_position(Point*);

int display_mine_field(Square**, const int, const int);

void show_number_square(const int);

void mine_sweeper_victory(Square**, const int, const int, const int);

void mine_sweeper_defeat(Square**, const int, const int, const int);

void field_create_error(const int, const int, const int);

bool game_input_handler(Point*, Square**, const int, const int);

bool input_game_variables(int*, int*, int*);

void variable_input_error(void);

void display_row_numbers(const int);

char last_integer_letter(const int);

#endif