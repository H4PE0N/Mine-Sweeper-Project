
#include "include-define-header.h"
#include "game-interface-program.h"

bool input_game_variables(int* height, int* width, int* mines)
{
	*height = 10, *width = 10, *mines = 20;
	return true;
}

void variable_input_error()
{
	printf("[ERROR]: Game variables not inputted correctly\n");
}

void mine_sweeper_victory(Square** mineField, const int height, const int width, const int mines)
{
	printf("You have won the minesweeper game!\n");
	// display_mine_field(mineField, height, width);
}

void mine_sweeper_defeat(Square** mineField, const int height, const int width, const int mines)
{
	printf("Unfortunately you have lost the game\n");
	// display_mine_field(mineField, height, width);
}

void field_create_error(const int height, const int width, const int mines)
{
	printf("[ERROR]: The minefield could not be created\n");
	printf("Height: %d\tWidth: %d\tMines: %d\n", height, width, mines);
}

bool game_input_handler(Point* position, Square** mineField, const int height, const int width)
{
	int lines = display_mine_field(mineField, height, width);

	bool output = input_field_position(position);

	fflush(stdout);
	printf("\033[%dA", lines);

	return output;
	
}

bool input_field_position(Point* position)
{
	printf("Input Position: ");
	int output = scanf("%d %d", &position->height, &position->width);

	fflush(stdout);
	printf("\033[%dA", 1);

	return output == 2;
}

void show_number_square(const int adjacent)
{
	if(adjacent >= 8) printf("\033[%dm8 \033[0m", 31);
	printf("\033[%dm%d \033[0m", adjacent + 30, adjacent);
}

int display_mine_field(Square** mineField, const int height, const int width)
{
	int lines = 0;

	printf("  ");
	for(int wIndex = 0; wIndex < width; wIndex = wIndex + 1)
	{
		char string[10]; sprintf(string, "%d", wIndex);
		printf("%c ", string[strlen(string) - 1]);
	}
	printf("\n"); lines += 1;

	for(int hIndex = 0; hIndex < height; hIndex = hIndex + 1)
	{
		char string[10]; sprintf(string, "%d", hIndex);
		printf("%c ", string[strlen(string) - 1]);

		for(int wIndex = 0; wIndex < width; wIndex = wIndex + 1)
		{
			if(mineField[hIndex][wIndex].isVisable == false)
			{
				printf("+ ");
			}
			else if(mineField[hIndex][wIndex].isThreat)
			{
				printf("@ ");
			}
			else if(mineField[hIndex][wIndex].adjacent == 0)
			{
				printf(". ");
			}
			else
			{
				show_number_square(mineField[hIndex][wIndex].adjacent);
			}
		}
		printf("\n"); lines += 1;
	}
	return lines;
}
