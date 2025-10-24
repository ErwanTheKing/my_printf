/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my.h
*/

#ifndef LIB_H
    #define LIB_H
    #include "formats.h"
    #include <stdarg.h>

int my_isneg(int nb);
long long int my_put_nbr(long long int nb);
void my_putchar(char c);
int my_is_prime(int nb);
int my_char_isnum(char c);
char *my_revstr(char *str);
void my_putfloat(float nb);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_find_prime_sup(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char *my_strlowcase(char *str);
long long len_nb(long long nb);
int my_showstr(char const *str);
char *my_strdup(char const *src);
int my_char_is_specifier(char c);
int my_str_isnum(char const *str);
char *my_strcapitalize(char *str);
int my_compute_square_root(int nb);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
void erase_flags(formats_t *formats);
int specifier_po(formats_t *formats);
void manage_zeros(formats_t *formats);
void manage_spaces(formats_t *formats);
void struct_prefill(formats_t *formats);
int my_str_isprintable(char const *str);
char *my_strndup(char const *src, int n);
int my_printf(char const *main_str, ...);
int my_show_word_array(char *const *tab);
int my_showmem(char const *str, int size);
void my_sort_int_array(int *tab, int size);
long long int my_compute_power_rec(long long int nb, long long int power);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
char **my_str_to_word_array(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strstr(char *str, char const *to_find);
char *my_nbr_to_str(double nb, formats_t *formats);
char *my_strncpy(char *dest, char const *src, int n);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncat(char *dest, char const *src, int nb);
int my_putnbr_base(unsigned int nbr, char const *base);
int specifier_a(va_list arguments_list, formats_t *formats);
int specifier_b(va_list arguments_list, formats_t *formats);
int specifier_c(va_list arguments_list, formats_t *formats);
int specifier_e(va_list arguments_list, formats_t *formats);
int specifier_g(va_list arguments_list, formats_t *formats);
int specifier_m(va_list arguments_list, formats_t *formats);
int specifier_n(va_list arguments_list, formats_t *formats);
int specifier_o(va_list arguments_list, formats_t *formats);
int specifier_s(va_list arguments_list, formats_t *formats);
int specifier_u(va_list arguments_list, formats_t *formats);
int specifier_x(va_list arguments_list, formats_t *formats);
int specifier_p(va_list arguments_list, formats_t *formats);
int specifier_di(va_list arguments_list, formats_t *formats);
int specifier_bigg(va_list arguments_list, formats_t *formats);
int specifier_biga(va_list arguments_list, formats_t *formats);
int specifier_bigb(va_list arguments_list, formats_t *formats);
int specifier_bige(va_list arguments_list, formats_t *formats);
int specifier_bigs(va_list arguments_list, formats_t *formats);
int specifier_bigx(va_list arguments_list, formats_t *formats);
int specifier_fbigf(va_list arguments_list, formats_t *formats);
int is_specifier(va_list arguments_list, int counter, formats_t *formats);
int fill_format_struct(formats_t *formats,
    char const *main_str, int main_str_pos);
int fill_specifier_struct(formats_t *formats,
    char const *main_str, int main_str_pos);
int fill_length_struct(formats_t *formats,
    char const *main_str, int main_str_pos);
int fill_width_struct(formats_t *formats,
    char const *main_str, int main_str_pos);
int fill_flag_struct(formats_t *formats,
    char const *main_str, int main_str_pos, int many_flags);
int fill_precision_struct(formats_t *formats,
    char const *main_str, int main_str_pos);
#endif /* LIB_H */
