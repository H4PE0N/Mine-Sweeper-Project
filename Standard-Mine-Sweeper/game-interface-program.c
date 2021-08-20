
#include "include-define-header.h"

void variable_input_error(void)
{
	printf("%s%s\n", CLEAR_LINE, VAR_INPUT_ERROR);
}

void mine_sweeper_victory(Square** mineField, const int height, const int width, const int mines)
{
	printf("%s%s\n", CLEAR_LINE, GAME_VICTORY_MSG); printf("%s\n", CLEAR_LINE);
	display_mine_field(mineField, height, width);
}

void mine_sweeper_defeat(Square** mineField, const int height, const int width, const int mines)
{
	printf("%s%s\n", CLEAR_LINE, GAME_DEFEAT_MSG); printf("%s\n", CLEAR_LINE);
	display_mine_field(mineField, height, width);
}

void error_game_variables(const int height, const int width, const int mines)
{
	printf("%s%s%s%d\n", CLEAR_LINE, ERROR_SYMBOL, HEIGHT_INPUT, height);
	printf("%s%s%s%d\n", CLEAR_LINE, ERROR_SYMBOL, WIDTH_INPUT, width);
	printf("%s%s%s%d\n", CLEAR_LINE, ERROR_SYMBOL, MINES_INPUT, mines);
}

void field_create_error(const int height, const int width, const int mines)
{
	printf("%s%s%s\n", CLEAR_LINE, ERROR_TEXT, CREATE_FLD_ERROR);
	error_game_variables(height, width, mines);
}

void display_input_before(void)
{
	printf("%s\n", VAR_INPUT_BANNER);
	printf("%s%s\n", BEFORE_INP, HEIGHT_INPUT);
	printf("%s%s\n", BEFORE_INP, WIDTH_INPUT);
	printf("%s%s\n", BEFORE_INP, MINES_INPUT);
}

bool input_game_variables(int* height, int* width, int* mines)
{
	display_input_before(); MOVE_UP(3);

	printf("%s%s%s", CLEAR_LINE, AFTER_INP, HEIGHT_INPUT);
	if(!scanf("%d", height)) return false;

	printf("%s%s%s", CLEAR_LINE, AFTER_INP, WIDTH_INPUT);
	if(!scanf("%d", width)) return false;

	printf("%s%s%s", CLEAR_LINE, AFTER_INP, MINES_INPUT);
	if(!scanf("%d", mines)) return false;

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
	printf("%s%s", CLEAR_LINE, POSITION_INPUT);

	int output = scanf("%d%d", &position->height, &position->width);

	fflush(stdin); MOVE_UP(1);

	return (output == 2);
}

void display_row_numbers(const int width)
{
	printf("%s  ", CLEAR_LINE);

	for(int integer = 0; integer < width; integer = integer + 1)
	{
		printf("%c ", last_integer_letter(integer));
	}
	printf("\n");
}

void display_game_symbol(const Square square)
{
	if(!square.isVisable) printf("%c", SQUARE_SYMBOL);

	else if(square.isThreat) printf("%c", THREAT_SYMBOL);

	else if(!square.adjacent) printf("%c", EMPTY_SYMBOL);

	else printf("%d", square.adjacent);
	
	printf(" ");
}

char last_integer_letter(const int integer)
{
	char string[10]; sprintf(string, "%d", integer);
	return string[strlen(string) - 1];
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
		printf("%s%c ", CLEAR_LINE, index);

		display_field_row(mineField, width, hIndex);	
	}
	return (height + 1);
}
