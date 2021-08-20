
#ifndef INCLUDE_DEFINE_HEADER
#define INCLUDE_DEFINE_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

typedef struct mine_field_square
{
	bool isVisable;
	bool isThreat;
	int adjacent;
} Square;

typedef struct mine_filed_point
{
	int height;
	int width;
} Point;

#define MOVE_UP(lines) printf("\033[%dA", lines)

#define MOVE_RIGHT(lines) printf("\033[%dC", lines)

#define CLEAR_LINE printf("\033[2K");

#include "game-symbol-definitions.h"

#include "game-interface-program.h"

#include "mine-sweeper-program.h"

#endif