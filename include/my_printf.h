/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** header
*/

#ifndef H_PRINTF
#define H_PRINTF

#include <stdarg.h>

#define ABS(x) (x < 0) ? -(long int)x : x
#define LSPECIF 12
#define LLEN 5

typedef struct arg {
    char flags[6];
    int width;
    int precision;
    char length[3];
    char spec[2];
} arg_t;

int disp_int(arg_t *arg, va_list *ap);
int disp_uint_x_x(arg_t *arg, va_list *ap);
int disp_uint_o(arg_t *arg, va_list *ap);
int disp_uint_b(arg_t *arg, va_list *ap);
int disp_uint_u(arg_t *arg, va_list *ap);

int disp_char(arg_t *arg, va_list *ap);
int disp_str(arg_t *arg, va_list *ap);
int disp_uint_p(arg_t *arg, va_list *ap);
int disp_l_llq(arg_t *arg, va_list *ap);
int disp_ul_ullq(arg_t *arg, va_list *ap);

int disp_short(arg_t *arg, va_list *ap);
int disp_ushort(arg_t *arg, va_list *ap);
int disp_uint_lx(arg_t *arg, va_list *ap);

int define_len_preci(arg_t *arg, long long int data, int base);
int define_len_space(arg_t *arg, long long int data, int base);
int disp_zeros(char flag_zero, int len_space, int len_preci);
int disp_width(int len_space, int len_preci);
int disp_not_printable_char(char c);

int display_arg(arg_t *arg, va_list *ap, char *ptrformat);
int disp_llq_ext(arg_t *arg, long long int *data, int len_space,
int len_preci);

int len_nbr(long long int nbr, int base);
int what_type(char spe);
void get_nbr_fromformat(char *format, int *i, int *nbr);
int is_digit(char c, int len_nbr);
int strlen_spec(char *str, char type, int len);

void clean_flags(arg_t *arg);

void search_flags(char *format, int *i, arg_t *arg);
int search_specifier(char *format, int *i, char dest[2]);
int search_length(char *format, int *i, char dest[3]);

#endif
