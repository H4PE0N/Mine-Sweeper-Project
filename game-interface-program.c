
#include "include-define-header.h"

const char* colors[] = {ONE_COLOR, TWO_COLOR, THREE_COLOR, FOUR_COLOR, FIVE_COLOR, SIX_COLOR, SEVEN_COLOR, EIGHT_COLOR};

void variable_input_error(void)
{
	printf("%s", TEXT_COLOR);
	printf("[ERROR]: Game variables not inputted correctly\n");
	printf("%s", NONE_COLOR);
}

void mine_sweeper_victory(Square** mineField, const int height, const int width, const int mines)
{
	printf("%s", TEXT_COLOR);
	printf("You have won the minesweeper game!\n");
	printf("%s", NONE_COLOR);

	display_mine_field(mineField, height, width);
}

void mine_sweeper_defeat(Square** mineField, const int height, const int width, const int mines)
{
	printf("%s", TEXT_COLOR);
	printf("Unfortunately you have lost the game\n");
	printf("%s", NONE_COLOR);

	display_mine_field(mineField, height, width);
}

void field_create_error(const int height, const int width, const int mines)
{
	printf("%s", TEXT_COLOR);
	printf("[ERROR]: The minefield could not be created\n");
	printf("Height: %d\tWidth: %d\tMines: %d\n", height, width, mines);
	printf("%s", NONE_COLOR);
}

bool input_game_variables(int* height, int* width, int* mines)
{
	printf("%s", TEXT_COLOR);
	printf("%s\n", VAR_INPUT_BANNER);
	printf("%s", NONE_COLOR);

	printf("%s", BEFORE_INP);
	printf("[?] %s\n[?] %s\n[?] %s\n", HEIGHT_INPUT, WIDTH_INPUT, MINES_INPUT);
	printf("%s", NONE_COLOR);

	MOVE_UP(3);

	printf("%s", AFTER_INP);

	CLEAR_LINE; printf("[$] %s", HEIGHT_INPUT);
	if(!scanf("%d", height)) return false;

	CLEAR_LINE; printf("[$] %s", WIDTH_INPUT);
	if(!scanf("%d", width)) return false;

	CLEAR_LINE; printf("[$] %s", MINES_INPUT);
	if(!scanf("%d", mines)) return false;

	printf("%s", NONE_COLOR);

	MOVE_UP(4);

	return true;
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
	CLEAR_LINE;

	printf("%s", TEXT_COLOR);
	printf("%s", POSITION_INPUT);
	printf("%s", NONE_COLOR);

	int output = scanf("%d%d", &position->height, &position->width);

	fflush(stdin); // This makes reading only one position at a time

	MOVE_UP(1);

	return (output == 2);
}

void show_number_square(const int adjacent)
{
	printf("%s", colors[(adjacent - 1)]);
	printf("%d", adjacent);
	printf("%s", NONE_COLOR);
}

void display_row_numbers(const int width)
{
	CLEAR_LINE;

	printf("%s", INDEX_COLOR);

	printf("  ");
	for(int integer = 0; integer < width; integer = integer + 1)
	{
		printf("%c ", last_integer_letter(integer));
	}
	printf("\n");

	printf("%s", NONE_COLOR);
}

void display_game_symbol(const Square square)
{
	if(!square.isVisable)
	{
		printf("%s", SQUARE_COLOR);
		printf("%c", SQUARE_SYMBOL);
		printf("%s", NONE_COLOR);
	}
	
	else if(square.isThreat)
	{
		printf("%s", THREAT_COLOR);
		printf("%c", THREAT_SYMBOL);
		printf("%s", NONE_COLOR);
	}
	
	else if(!square.adjacent)
	{
		printf("%s", EMPTY_COLOR);
		printf("%c", EMPTY_SYMBOL);
		printf("%s", NONE_COLOR);
	}
	else show_number_square(square.adjacent);
	
	printf(" ");
}

char last_integer_letter(const int integer)
{
	char string[10]; sprintf(string, "%d", integer);
	return string[strlen(string) - 1];
}

int display_mine_field(Square** mineField, const int height, const int width)
{
	display_row_numbers(width); 

	for(int hIndex = 0; hIndex < height; hIndex = hIndex + 1)
	{
		CLEAR_LINE;

		printf("%s", INDEX_COLOR);
		printf("%c ", last_integer_letter(hIndex));
		printf("%s", NONE_COLOR);

		for(int wIndex = 0; wIndex < width; wIndex = wIndex + 1)
		{
			display_game_symbol(mineField[hIndex][wIndex]);
		}
		printf("\n");
	}
	return (height + 1);
}
