
#include "include-define-header.h"

const char* colors[] = {ONE_COLOR, TWO_COLOR, THREE_COLOR, FOUR_COLOR, FIVE_COLOR, SIX_COLOR, SEVEN_COLOR, EIGHT_COLOR};

void variable_input_error(void)
{
	printf("%s%s%s\n%s", CLEAR_LINE, TEXT_COLOR, VAR_INPUT_ERROR, NONE_COLOR); 
}

void mine_sweeper_victory(Square** mineField, const int height, const int width, const int mines)
{
	printf("%s%s%s\n%s%s\n", CLEAR_LINE, TEXT_COLOR, GAME_VICTORY_MSG, NONE_COLOR, CLEAR_LINE);
	display_mine_field(mineField, height, width);
}

void mine_sweeper_defeat(Square** mineField, const int height, const int width, const int mines)
{
	printf("%s%s%s\n%s%s\n", CLEAR_LINE, TEXT_COLOR, GAME_DEFEAT_MSG, NONE_COLOR, CLEAR_LINE);
	display_mine_field(mineField, height, width);
}

void show_game_variables(const int height, const int width, const int mines)
{
	printf("%s%s[%s%c%s] %s%d\n%s", CLEAR_LINE, TEXT_COLOR, ERROR_COLOR, ERROR_SYMBOL, TEXT_COLOR, HEIGHT_INPUT, height, NONE_COLOR);
	printf("%s%s[%s%c%s] %s%d\n%s", CLEAR_LINE, TEXT_COLOR, ERROR_COLOR, ERROR_SYMBOL, TEXT_COLOR, WIDTH_INPUT, width, NONE_COLOR);
	printf("%s%s[%s%c%s] %s%d\n%s", CLEAR_LINE, TEXT_COLOR, ERROR_COLOR, ERROR_SYMBOL, TEXT_COLOR, MINES_INPUT, mines, NONE_COLOR);
}

void field_create_error(const int height, const int width, const int mines)
{
	printf("%s%s[%s%s%s]: %s\n%s", CLEAR_LINE, TEXT_COLOR, ERROR_COLOR, ERROR_TEXT, TEXT_COLOR, CREATE_FLD_ERROR, NONE_COLOR);
	show_game_variables(height, width, mines);
}

void display_input_before(void)
{
	printf("%s%s\n%s", TEXT_COLOR, VAR_INPUT_BANNER, NONE_COLOR);
	printf("%s[%s?%s] %s\n%s", TEXT_COLOR, BEFORE_INP, TEXT_COLOR, HEIGHT_INPUT, NONE_COLOR);
	printf("%s[%s?%s] %s\n%s", TEXT_COLOR, BEFORE_INP, TEXT_COLOR, WIDTH_INPUT, NONE_COLOR);
	printf("%s[%s?%s] %s\n%s", TEXT_COLOR, BEFORE_INP, TEXT_COLOR, MINES_INPUT, NONE_COLOR);
}

bool input_game_variables(int* height, int* width, int* mines)
{
	display_input_before(); MOVE_UP(3);

	printf("%s%s[%s$%s] %s%s", CLEAR_LINE, TEXT_COLOR, AFTER_INP, TEXT_COLOR, HEIGHT_INPUT, NONE_COLOR);
	if(!scanf("%d", height)) return false;

	printf("%s%s[%s$%s] %s%s", CLEAR_LINE, TEXT_COLOR, AFTER_INP, TEXT_COLOR, WIDTH_INPUT, NONE_COLOR);
	if(!scanf("%d", width)) return false;

	printf("%s%s[%s$%s] %s%s", CLEAR_LINE, TEXT_COLOR, AFTER_INP, TEXT_COLOR, MINES_INPUT, NONE_COLOR);
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
	printf("%s%s%s%s", CLEAR_LINE, TEXT_COLOR, POSITION_INPUT, NONE_COLOR);

	int output = scanf("%d%d", &position->height, &position->width);

	fflush(stdin); MOVE_UP(1);

	return (output == 2);
}

void show_number_square(const int adjacent)
{
	printf("%s%d%s", colors[(adjacent - 1)], adjacent, NONE_COLOR);
}

void display_row_numbers(const int width)
{
	printf("%s%s  ", CLEAR_LINE, INDEX_COLOR);

	for(int integer = 0; integer < width; integer = integer + 1)
	{
		printf("%c ", last_integer_letter(integer));
	}
	printf("\n%s", NONE_COLOR);
}

void display_game_symbol(const Square square)
{
	if(!square.isVisable) printf("%s%c%s", SQUARE_COLOR, SQUARE_SYMBOL, NONE_COLOR);
	
	else if(square.isThreat) printf("%s%c%s", THREAT_COLOR, THREAT_SYMBOL, NONE_COLOR);
	
	else if(!square.adjacent) printf("%s%c%s", EMPTY_COLOR, EMPTY_SYMBOL, NONE_COLOR);

	else show_number_square(square.adjacent);
	
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
		int index = last_integer_letter(hIndex);
		printf("%s%s%c%s ", CLEAR_LINE, INDEX_COLOR, index, NONE_COLOR);

		display_field_row(mineField, width, hIndex);	
	}
	return (height + 1);
}
