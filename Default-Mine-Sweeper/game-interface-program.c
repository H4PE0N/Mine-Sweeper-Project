
#include "include-define-header.h"

void variable_input_error(void)
{
	CLEAR_LINE; printf("Game variables not inputted correctly\n");
}

void mine_sweeper_victory(Square** mineField, const int height, const int width, const int mines)
{
	unlock_field_mines(mineField, height, width);
	CLEAR_LINE; printf("You have won the minesweeper game!\n");
	CLEAR_LINE; printf("\n"); display_mine_field(mineField, height, width);
}

void mine_sweeper_defeat(Square** mineField, const int height, const int width, const int mines)
{
	unlock_field_mines(mineField, height, width);
	CLEAR_LINE; printf("Unfortunately you have lost the game\n");
	CLEAR_LINE; printf("\n"); display_mine_field(mineField, height, width);
}

void error_game_variables(const int height, const int width, const int mines)
{
	CLEAR_LINE; printf("[X]: HEIGHT\t= %d\n", height);
	CLEAR_LINE; printf("[X]: WIDTH\t= %d\n", width);
	CLEAR_LINE; printf("[X]: MINES\t= %d\n", mines);
}

void field_create_error(const int height, const int width, const int mines)
{
	CLEAR_LINE; printf("[ERROR]: The minefield could not be created\n");
	error_game_variables(height, width, mines);
}

void display_input_before(void)
{
	CLEAR_LINE; printf("[?] === INPUT GAME VARIALBES === [?]\n");
	CLEAR_LINE; printf("[?]: HEIGHT\t:\n");
	CLEAR_LINE; printf("[?]: WIDTH\t:\n");
	CLEAR_LINE; printf("[?]: MINES\t:\n");
}

bool input_height_variable(int* height)
{
	CLEAR_LINE; printf("[$]: HEIGHT\t: "); return scanf("%d", height);
}

bool input_width_variable(int* width)
{
	CLEAR_LINE; printf("[$]: WIDTH\t: "); return scanf("%d", width);
}

bool input_mines_variable(int* mines)
{
	CLEAR_LINE; printf("[$]: MINES\t: "); return scanf("%d", mines);
}

bool input_game_variables(int* height, int* width, int* mines)
{
	display_input_before(); MOVE_UP(3);

	if(!input_height_variable(height)) return false;

	if(!input_width_variable(width)) return false;

	if(!input_mines_variable(mines)) return false;

	MOVE_UP(4); return true;
}

bool game_input_handler(Point* position, Square** mineField, const int height, const int width)
{
	int lines = display_mine_field(mineField, height, width);

	bool output = input_field_position(position);

	MOVE_UP(lines);

	return output;
}

bool input_field_position(Point* position)
{
	CLEAR_LINE; printf("INPUT POSITION : ");

	int output = scanf("%d%d", &position->height, &position->width);

	fflush(stdin); MOVE_UP(1);

	return (output == 2);
}

void display_row_numbers(const int width)
{
	CLEAR_LINE; printf("  ");

	for(int integer = 0; integer < width; integer = integer + 1)
	{
		printf("%c ", last_integer_letter(integer));
	}
	printf("\n");
}

void display_game_symbol(const Square square)
{
	if(!square.isVisable) printf("+");

	else if(square.isThreat) printf("@");

	else if(!square.adjacent) printf(".");

	else printf("%d", square.adjacent);
	
	printf(" ");
}

void display_field_row(Square** mineField, const int width, const int hIndex)
{
	for(int wIndex = 0; wIndex < width; wIndex = wIndex + 1)
	{
		display_game_symbol(mineField[hIndex][wIndex]);
	}
	printf("\n");
}

int display_mine_field(Square** mineField, const int height, const int width)
{
	display_row_numbers(width); 

	for(int hIndex = 0; hIndex < height; hIndex = hIndex + 1)
	{
		char index = last_integer_letter(hIndex);
		CLEAR_LINE; printf("%c ", index);

		display_field_row(mineField, width, hIndex);	
	}
	return (height + 1);
}
