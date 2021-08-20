
#ifndef MINE_SWEEPER_PROGRAM
#define MINE_SWEEPER_PROGRAM

Square** create_square_matrix(const int, const int);

bool generate_mine_field(Square**, const int, const int, const int);

bool position_inside_bounds(const int, const int, const int, const int);

int adjacent_field_mines(Square**, const Point, const int, const int);

void mark_field_adjacents(Square**, const int, const int);

bool generate_field_mines(Square**, const int, const int, const int);

Point* every_matrix_indexes(const int, const int);

void delete_indexes_point(Point*, const int, const int);

void unlock_field_mines(Square**, const int, const int);

bool mine_field_cleared(Square**, const int, const int);

bool mine_sweeper_game(Square**, const int, const int);

bool unlock_field_square(Square**, Point, const int, const int);

char last_integer_letter(const int);

#endif