
#ifndef INCLUDE_DEFINE_HEADER
#define INCLUDE_DEFINE_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
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

#endif