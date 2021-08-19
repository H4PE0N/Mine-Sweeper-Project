
#include "include-define-header.h"
#include "game-interface-program.h"
#include "mine-sweeper-program.h"

int main(int argAmount, char* arguments[])
{
	srand(time(NULL));

	int height, width, mines;
	if(!input_game_variables(&height, &width, &mines))
	{
		variable_input_error();
		return false;
	}
	
	Square** mineField = create_square_matrix(height, width);

	if(!generate_mine_field(mineField, height, width, mines))
	{
		field_create_error(height, width, mines);
		free(mineField); return false;
	}
	
	if(!mine_sweeper_game(mineField, height, width))
	{
		unlock_field_mines(mineField, height, width);
		mine_sweeper_defeat(mineField, height, width, mines);
	}
	else
	{
		mine_sweeper_victory(mineField, height, width, mines);
	}
	
	free(mineField);

	return false;
}

bool mine_sweeper_game(Square** mineField, const int height, const int width)
{
	while(!mine_field_cleared(mineField, height, width))
	{
		Point position;

		// This function has all interactive and interface code in it
		if(!game_input_handler(&position, mineField, height, width)) return false;

		if(!position_inside_bounds(position.height, position.width, height, width)) continue;

		if(!unlock_field_square(mineField, position, height, width)) return false;
	}
	return true;
}

void unlock_field_mines(Square** mineField, const int height, const int width)
{
	for(int hIndex = 0; hIndex < height; hIndex = hIndex + 1)
	{
		for(int wIndex = 0; wIndex < width; wIndex = wIndex + 1)
		{
			if(!mineField[hIndex][wIndex].isThreat) continue;
			
			mineField[hIndex][wIndex].isVisable = true;
		}
	}
}

bool unlock_field_square(Square** mineField, Point position, const int height, const int width)
{
	mineField[position.height][position.width].isVisable = true;

	if(mineField[position.height][position.width].isThreat) return false;

	if(mineField[position.height][position.width].adjacent) return true;
	
	for(int hIndex = (position.height - 1); hIndex <= (position.height + 1); hIndex = hIndex + 1)
	{
		for(int wIndex = (position.width - 1); wIndex <= (position.width + 1); wIndex = wIndex + 1)
		{
			if(!position_inside_bounds(hIndex, wIndex, height, width)) continue;

			if(mineField[hIndex][wIndex].isVisable) continue;

			Point newPosition = {hIndex, wIndex};

			if(!unlock_field_square(mineField, newPosition, height, width)) return false;
		}
	}
	return true;
}

bool mine_field_cleared(Square** mineField, const int height, const int width)
{
	for(int hIndex = 0; hIndex < height; hIndex = hIndex + 1)
	{
		for(int wIndex = 0; wIndex < width; wIndex = wIndex + 1)
		{
			if(mineField[hIndex][wIndex].isThreat) continue;

			if(!mineField[hIndex][wIndex].isVisable) return false;
		}
	}
	return true;
}

bool generate_mine_field(Square** mineField, const int height, const int width, const int mines)
{
	if(!generate_field_mines(mineField, height, width, mines)) return false;

	mark_field_adjacents(mineField, height, width); return true;
}

bool generate_field_mines(Square** mineField, const int height, const int width, const int mines)
{
	const int total = (height * width);
	if(mines > total) return false;

	Point* indexes = every_matrix_indexes(height, width);

	for(int index = 0; index < mines; index = index + 1)
	{
		int random = rand() % (total - index);
		int hIndex = indexes[random].height;
		int wIndex = indexes[random].width;

		mineField[hIndex][wIndex].isThreat = true;

		delete_indexes_point(indexes, (total - index), random);
	}

	free(indexes); return true;
}

void delete_indexes_point(Point* indexes, const int amount, const int start)
{
	for(int index = start; index < (amount - 1); index = index + 1)
	{
		indexes[index] = indexes[index + 1];
	}
}

Point* every_matrix_indexes(const int height, const int width)
{
	int total = (height * width);
	Point* indexes = malloc(sizeof(Point) * total);

	for(int hIndex = 0; hIndex < height; hIndex = hIndex + 1)
	{
		for(int wIndex = 0; wIndex < width; wIndex = wIndex + 1)
		{
			int index = (hIndex * width) + wIndex;
			Point current = {hIndex, wIndex};

			indexes[index] = current;
		}
	}
	return indexes;
}

void mark_field_adjacents(Square** mineField, const int height, const int width)
{
	for(int hIndex = 0; hIndex < height; hIndex = hIndex + 1)
	{
		for(int wIndex = 0; wIndex < width; wIndex = wIndex + 1)
		{
			if(mineField[hIndex][wIndex].isThreat) continue;

			Point position = {hIndex, wIndex};
			int adjacent = adjacent_field_mines(mineField, position, height, width);

			mineField[hIndex][wIndex].adjacent = adjacent;
		}
	}
}

int adjacent_field_mines(Square** mineField, const Point position, const int height, const int width)
{
	int adjacent = 0;

	for(int hIndex = (position.height - 1); hIndex <= (position.height + 1); hIndex = hIndex + 1)
	{
		for(int wIndex = (position.width - 1); wIndex <= (position.width + 1); wIndex = wIndex + 1)
		{
			if(!position_inside_bounds(hIndex, wIndex, height, width)) continue;

			if(mineField[hIndex][wIndex].isThreat) adjacent++;
		}
	}
	return adjacent;
}

bool position_inside_bounds(const int hIndex, const int wIndex, const int height, const int width)
{
	return (hIndex >= 0 && hIndex < height) && (wIndex >= 0 && wIndex < width);
}

Square** create_square_matrix(const int height, const int width)
{
	Square** mineField = malloc(sizeof(Square*) * height);
	for(int hIndex = 0; hIndex < height; hIndex = hIndex + 1)
	{
		mineField[hIndex] = malloc(sizeof(Square) * width);
		for(int wIndex = 0; wIndex < width; wIndex = wIndex + 1)
		{
			Square current = {false, false, 0};
			mineField[hIndex][wIndex] = current;
		}
	}
	return mineField;
}
