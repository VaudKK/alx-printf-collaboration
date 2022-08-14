#ifndef MAIN_FUNCTIONS
#define MAIN_FUNCTIONS

int _printf(const char *format, ...);
int print_binary(int number);
int print_percent(void);
int print_hex(int num);
int print_oct(int num);
int print_decimal(int);
int print_char(char);
int print_helper_extended(const char *, va_list, int *);

#endif
