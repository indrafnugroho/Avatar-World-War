/**
Filename: pcolor.h
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 17/10/2019
**/

/**
Details

print_xxx(c) will print c with xxx color. Import this header to use the declared functions.
We only provide 8 colors. Feel free to modify/add colors if you want to.
**/

#define NORMAL "\x1B[0m"
#define BLACK "\x1B[38;5;0m"
#define BG_BLACK "\x1B[48;5;0m"
#define RED "\x1B[31m"
#define BG_RED "\x1B[41m"
#define GREEN "\x1B[32m"
#define BG_GREEN "\x1B[42m"
#define YELLOW "\x1B[33m"
#define BG_YELLOW "\x1B[43m"
#define BLUE "\x1B[34m"
#define BG_BLUE "\x1B[44m"
#define MAGENTA "\x1B[35m"
#define BG_MAGENTA "\x1B[45m"
#define CYAN "\x1B[36m"
#define BG_CYAN "\x1B[46m"
#define BOLD "\x1B[1m"
#define UNDERLINE "\x1B[4m"
void print_red(char c);
void print_green(char c);
void print_yellow(char c);
void print_blue(char c);
void print_magenta(char c);
void print_cyan(char c);
void print_color(char c, char* color);
void set_print_color(char* color);
void reset_print_color();
