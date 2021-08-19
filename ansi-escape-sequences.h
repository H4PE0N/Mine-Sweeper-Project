
#ifndef ANSI_ESCAPE_SEQUENCES
#define ANSI_ESCAPE_SEQUENCES

#define MOVE_UP(lines) printf("\033[%dA", lines)

#define MOVE_RIGHT(lines) printf("\033[%dC", lines);

#define SET_COLOR(number) printf("\033[%dm", number)

#endif