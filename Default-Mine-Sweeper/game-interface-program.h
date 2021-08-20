
#ifndef GAME_INTERFACE_PROGRAM
#define GAME_INTERFACE_PROGRAM

#include "include-define-header.h"

bool input_field_position(Point*);

int display_mine_field(Square**, const int, const int);

void mine_sweeper_victory(Square**, const int, const int, const int);

void mine_sweeper_defeat(Square**, const int, const int, const int);

void field_create_error(const int, const int, const int);

bool game_input_handler(Point*, Square**, const int, const int);

bool input_game_variables(int*, int*, int*);

void variable_input_error(void);

void display_row_numbers(const int);

void display_input_before(void);

void display_field_row(Square**, const int, const int);

void error_game_variables(const int, const int, const int);

bool input_height_variable(int*);

bool input_width_variable(int*);

bool input_mines_variable(int*);

#endif