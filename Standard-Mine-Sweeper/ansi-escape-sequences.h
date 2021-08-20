
#ifndef ANSI_ESCAPE_SEQUENCES
#define ANSI_ESCAPE_SEQUENCES

#define MOVE_UP(lines) printf("\033[%dA", lines)

#define MOVE_RIGHT(lines) printf("\033[%dC", lines)

#define CLEAR_LINE "\033[2K"

#endif