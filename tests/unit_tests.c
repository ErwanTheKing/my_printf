/*
** EPITECH PROJECT, 2025
** mini_printf
** File description:
** unit_tests
*/

#include <stdint.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}


//region testing the basic function print
Test(my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, simple_string_with_backslashn, .init = redirect_all_std)
{
    my_printf("hello world\n");
    cr_assert_stdout_eq_str("hello world\n");
}
//endregion

//region                                   testing the basic function print but with %s parameter


Test(my_printf, simple_string_with_parameters, .init = redirect_all_std)
{
    my_printf("%s", "hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, simple_string_with_backslashn_with_parameters,
    .init = redirect_all_std)
{
    my_printf("%s\n", "hello world");
    cr_assert_stdout_eq_str("hello world\n");
}

Test(my_printf, composed_string, .init = redirect_all_std)
{
    char str [6];
    my_strcpy(str, "world");
    my_printf("Hello %s\n", str);
    cr_assert_stdout_eq_str("Hello world\n");
}

//endregion

//region                                        testing the %d and %i parameters


Test(my_printf, simple_number_without_parameters, .init = redirect_all_std)
{
    my_printf("%d", 4);
    cr_assert_stdout_eq_str("4");
}

Test(my_printf, simple_number_with_parameters, .init = redirect_all_std)
{
    my_printf("%+ d", 4);
    cr_assert_stdout_eq_str("+4");
}

Test(my_printf, simple_number_with_3_parameters, .init = redirect_all_std)
{
    my_printf("%+- d", 4);
    cr_assert_stdout_eq_str("+4");
}

Test(my_printf, simple_number_with_4_parameters, .init = redirect_all_std)
{
    my_printf("%+- 0d", 4);
    cr_assert_stdout_eq_str("+4");
}

Test(my_printf, simple_number_with_3_parameters_0, .init = redirect_all_std)
{
    my_printf("%-+0d", 4);
    cr_assert_stdout_eq_str("+4");
}

Test(my_printf, calcul_in_string, .init = redirect_all_std)
{
    const int nb = 21;
    my_printf("If you multiple %d by %d, the result is %i.\n", nb, 2, nb * 2);
    cr_assert_stdout_eq_str("If you multiple 21 by 2, the result is 42.\n");
}

Test(my_printf_di_exact, d_positive_simple, .init = redirect_all_std)
{
    my_printf("(%d)", 42);
    cr_assert_stdout_eq_str("(42)");
}

Test(my_printf_di_exact, d_negative_simple, .init = redirect_all_std)
{
    my_printf("(%d)", -42);
    cr_assert_stdout_eq_str("(-42)");
}

Test(my_printf_di_exact, d_zero_simple, .init = redirect_all_std)
{
    my_printf("(%d)", 0);
    cr_assert_stdout_eq_str("(0)");
}

Test(my_printf_di_exact, i_equivalence, .init = redirect_all_std)
{
    my_printf("(%i)", -123);
    cr_assert_stdout_eq_str("(-123)");
}

/* ========= FLAGS: + and space ========= */

Test(my_printf_di_exact, plus_flag_positive, .init = redirect_all_std)
{
    my_printf("(%+-d)", 42);
    cr_assert_stdout_eq_str("(+42)");
}

Test(my_printf_di_exact, plus_flag_negative, .init = redirect_all_std)
{
    my_printf("(%0 +-d)", -42);
    cr_assert_stdout_eq_str("(-42)");
}

Test(my_printf_di_exact, space_flag_positive, .init = redirect_all_std)
{
    my_printf("(% d)", 42);
    cr_assert_stdout_eq_str("( 42)");
}

Test(my_printf_di_exact, space_plus_precedence, .init = redirect_all_std)
{
    my_printf("(% +d)", 42);
    cr_assert_stdout_eq_str("(+42)");
}

/* ========= WIDTH & ALIGNMENT ========= */

Test(my_printf_di_exact, width_right_aligned, .init = redirect_all_std)
{
    my_printf("(%10d)", 1234);
    cr_assert_stdout_eq_str("(      1234)");
}

Test(my_printf_di_exact, width_left_aligned, .init = redirect_all_std)
{
    my_printf("(%-10d)", 1234);
    cr_assert_stdout_eq_str("(1234      )");
}

Test(my_printf_di_exact, width_with_sign, .init = redirect_all_std)
{
    my_printf("(%+8d)", 1234);
    cr_assert_stdout_eq_str("(   +1234)");
}

Test(my_printf_di_exact, width_negative_number, .init = redirect_all_std)
{
    my_printf("(%8d)", -42);
    cr_assert_stdout_eq_str("(     -42)");
}

/* ========= ZERO-PADDING ========= */

Test(my_printf_di_exact, zero_padding_basic, .init = redirect_all_std)
{
    my_printf("(%010d)", 1234);
    cr_assert_stdout_eq_str("(0000001234)");
}

Test(my_printf_di_exact, zero_padding_with_sign, .init = redirect_all_std)
{
    my_printf("(%+010d)", 1234);
    cr_assert_stdout_eq_str("(+000001234)");
}

Test(my_printf_di_exact, zero_padding_negative, .init = redirect_all_std)
{
    my_printf("(%010d)", -1234);
    cr_assert_stdout_eq_str("(-000001234)");
}

Test(my_printf_di_exact, zero_padding_ignored_with_left_align, .init = redirect_all_std)
{
    my_printf("(%-010d)", 1234);
    cr_assert_stdout_eq_str("(1234      )");
}

/* ========= PRECISION ========= */

Test(my_printf_di_exact, precision_increases_digits, .init = redirect_all_std)
{
    my_printf("(%.6d)", 1234);
    cr_assert_stdout_eq_str("(001234)");
}

Test(my_printf_di_exact, precision_zero_with_zero_value_empty, .init = redirect_all_std)
{
    my_printf("(%.0d)", 0);
    cr_assert_stdout_eq_str("()");
}

Test(my_printf_di_exact, precision_beats_zero_padding, .init = redirect_all_std)
{
    my_printf("(%010.6d)", 1234);
    cr_assert_stdout_eq_str("(    001234)");
}

Test(my_printf_di_exact, precision_with_negative, .init = redirect_all_std)
{
    my_printf("(%.6d)", -1234);
    cr_assert_stdout_eq_str("(-001234)");
}

/* ========= COMBINED FLAGS ========= */

Test(my_printf_di_exact, combo_left_plus_width_prec, .init = redirect_all_std)
{
    my_printf("(%-+10.6d)", 1234);
    cr_assert_stdout_eq_str("(+001234   )");
}

Test(my_printf_di_exact, combo_space_zero_width_prec_negative, .init = redirect_all_std)
{
    my_printf("(% 010.6d)", -1234);
    cr_assert_stdout_eq_str("(   -001234)");
}

Test(my_printf_di_exact, combo_plus_zero_width, .init = redirect_all_std)
{
    my_printf("(%+07d)", 42);
    cr_assert_stdout_eq_str("(+000042)");
}

/* ========= EDGE VALUES ========= */

Test(my_printf_di_exact, int_min_max, .init = redirect_all_std)
{
    my_printf("(%d|%d)", (int)0x80000000, (int)0x7fffffff);
    cr_assert_stdout_eq_str("(-2147483648|2147483647)");
}

/* ========= LENGTH MODIFIERS ========= */

Test(my_printf_di_exact, length_hh_signed_char, .init = redirect_all_std)
{
    signed char v = -120;
    my_printf("(%hhd)", v);
    cr_assert_stdout_eq_str("(-120)");
}

Test(my_printf_di_exact, length_h_short, .init = redirect_all_std)
{
    short v = -32000;
    my_printf("(%hd)", v);
    cr_assert_stdout_eq_str("(-32000)");
}

Test(my_printf_di_exact, length_l_long, .init = redirect_all_std)
{
    long v = -2147483649L;
    my_printf("(%ld)", v);
    cr_assert_stdout_eq_str("(-2147483649)");
}

Test(my_printf_di_exact, length_ll_long_long, .init = redirect_all_std)
{
    long long v = -9223372036854775807LL;
    my_printf("(%lld)", v);
    cr_assert_stdout_eq_str("(-9223372036854775807)");
}

Test(my_printf_di_exact, length_j_intmax, .init = redirect_all_std)
{
    intmax_t v = -9223372036854775807LL;
    my_printf("(%jd)", v);
    cr_assert_stdout_eq_str("(-9223372036854775807)");
}

Test(my_printf_di_exact, length_z_size_t, .init = redirect_all_std)
{
    size_t v = 123456789;
    my_printf("(%zd)", v);
    cr_assert_stdout_eq_str("(123456789)");
}

//endregion

//region                                        testing the %u parameter

/* ========= BASIC TESTS ========= */

Test(my_printf_u_basic, testplusespace, .init = redirect_all_std)
{
    my_printf("%+u", 26);
    cr_assert_stdout_eq_str("26");
}

Test(my_printf_u_basic, testzero, .init = redirect_all_std)
{
    my_printf("%05u", 26);
    cr_assert_stdout_eq_str("00026");
}

Test(my_printf_u_basic, testplusmoins, .init = redirect_all_std)
{
    my_printf("%+-u", 26);
    cr_assert_stdout_eq_str("26");
}

Test(my_printf_u_basic, testplus, .init = redirect_all_std)
{
    my_printf("% +u", 26);
    cr_assert_stdout_eq_str("26");
}

Test(my_printf_u_basic, simple_unsigned, .init = redirect_all_std)
{
    my_printf("(%u)", 42);
    cr_assert_stdout_eq_str("(42)");
}

Test(my_printf_u_basic, zero_value, .init = redirect_all_std)
{
    my_printf("(%u)", 0);
    cr_assert_stdout_eq_str("(0)");
}

Test(my_printf_u_basic, max_unsigned, .init = redirect_all_std)
{
    my_printf("(%u)", 4294967295U);
    cr_assert_stdout_eq_str("(4294967295)");
}

Test(my_printf_u_basic, multiple_values, .init = redirect_all_std)
{
    my_printf("(%u %u %u)", 1, 200, 30000);
    cr_assert_stdout_eq_str("(1 200 30000)");
}

/* ========= FLAGS ========= */

Test(my_printf_u_flags, plus_ignored_for_unsigned, .init = redirect_all_std)
{
    my_printf("(%+u)", 42);
    cr_assert_stdout_eq_str("(42)");
}

Test(my_printf_u_flags, space_ignored_for_unsigned, .init = redirect_all_std)
{
    my_printf("(% u)", 42);
    cr_assert_stdout_eq_str("(42)");
}

/* ========= WIDTH & ALIGNMENT ========= */

Test(my_printf_u_width, right_aligned, .init = redirect_all_std)
{
    my_printf("(%10u)", 1234);
    cr_assert_stdout_eq_str("(      1234)");
}

Test(my_printf_u_width, width_with_large_number, .init = redirect_all_std)
{
    my_printf("(%12u)", 4294967295U);
    cr_assert_stdout_eq_str("(  4294967295)");
}

/* ========= ZERO-PADDING ========= */

Test(my_printf_u_zero_padding, basic, .init = redirect_all_std)
{
    my_printf("(%010u)", 1234);
    cr_assert_stdout_eq_str("(0000001234)");
}

Test(my_printf_u_zero_padding, with_width, .init = redirect_all_std)
{
    my_printf("(%08u)", 42);
    cr_assert_stdout_eq_str("(00000042)");
}

/* ========= PRECISION ========= */

Test(my_printf_u_precision, increases_digits, .init = redirect_all_std)
{
    my_printf("(%.6u)", 1234);
    cr_assert_stdout_eq_str("(001234)");
}

Test(my_printf_u_precision, zero_precision_zero_value, .init = redirect_all_std)
{
    my_printf("(%.0u)", 0);
    cr_assert_stdout_eq_str("()");
}

/* ========= COMBINED FLAGS ========= */

Test(my_printf_u_combo, left_width_precision, .init = redirect_all_std)
{
    my_printf("(%-10.6u)", 1234);
    cr_assert_stdout_eq_str("(001234    )");
}

Test(my_printf_u_combo, zero_width_precision, .init = redirect_all_std)
{
    my_printf("(%010.6u)", 42);
    cr_assert_stdout_eq_str("(    000042)");
}

/* ========= EDGE CASES ========= */

Test(my_printf_u_edge, large_numbers, .init = redirect_all_std)
{
    my_printf("(%u|%u)", 0U, 4294967295U);
    cr_assert_stdout_eq_str("(0|4294967295)");
}

/* ========= LENGTH MODIFIERS ========= */

Test(my_printf_u_length, hh_unsigned_char, .init = redirect_all_std)
{
    unsigned char v = 255;
    my_printf("(%hhu)", v);
    cr_assert_stdout_eq_str("(255)");
}

Test(my_printf_u_length, h_unsigned_short, .init = redirect_all_std)
{
    unsigned short v = 65000;
    my_printf("(%hu)", v);
    cr_assert_stdout_eq_str("(65000)");
}

Test(my_printf_u_length, l_unsigned_long, .init = redirect_all_std)
{
    unsigned long v = 4000000000UL;
    my_printf("(%lu)", v);
    cr_assert_stdout_eq_str("(4000000000)");
}

Test(my_printf_u_length, ll_unsigned_long_long, .init = redirect_all_std)
{
    unsigned long long v = 18446744073709551615ULL;
    my_printf("(%llu)", v);
    cr_assert_stdout_eq_str("(18446744073709551615)");
}

Test(my_printf_u_length, j_uintmax, .init = redirect_all_std)
{
    uintmax_t v = 12345678901234567890ULL;
    my_printf("(%ju)", v);
    cr_assert_stdout_eq_str("(12345678901234567890)");
}

Test(my_printf_u_length, z_size_t, .init = redirect_all_std)
{
    size_t v = 123456789;
    my_printf("(%zu)", v);
    cr_assert_stdout_eq_str("(123456789)");
}

//endregion

//region                                           testing the %% parameter


Test(my_printf, simple_call, .init = redirect_all_std)
{
    my_printf("%%");
    cr_assert_stdout_eq_str("%");
}

Test(my_printf, call_in_str, .init = redirect_all_std)
{
    my_printf("test%%test");
    cr_assert_stdout_eq_str("test%test");
}
//endregion

//region                                     testing to mix plurals parameters if it works


Test(my_printf, calcul_in_string_and_str, .init = redirect_all_std)
{
    my_printf("The word %%%s%% has %i characters.\n", "Epitech", my_strlen("Epitech"));
    cr_assert_stdout_eq_str("The word %Epitech% has 7 characters.\n");
}
//endregion

//region                                     testing %c parameter

Test(my_printf_c_exact, c_basic_letter, .init = redirect_all_std)
{
    my_printf("(%c)", 'A');
    cr_assert_stdout_eq_str("(A)");
}

Test(my_printf_c_exact, c_basic_digit, .init = redirect_all_std)
{
    my_printf("(%c)", '7');
    cr_assert_stdout_eq_str("(7)");
}

Test(my_printf_c_exact, c_basic_symbol, .init = redirect_all_std)
{
    my_printf("(%c)", '!');
    cr_assert_stdout_eq_str("(!)");
}

Test(my_printf_c_exact, c_width_right, .init = redirect_all_std)
{
    my_printf("(%5c)", 'A');
    cr_assert_stdout_eq_str("(    A)");
}

Test(my_printf_c_exact, c_width_left, .init = redirect_all_std)
{
    my_printf("(%-5c)", 'A');
    cr_assert_stdout_eq_str("(A    )");
}

Test(my_printf_c_exact, c_zero_flag_ignored, .init = redirect_all_std)
{
    my_printf("(%05c)", 'A');
    cr_assert_stdout_eq_str("(    A)");
}

Test(my_printf_c_exact, c_multiple_chars, .init = redirect_all_std)
{
    my_printf("(%c%c%c)", 'A', 'B', 'C');
    cr_assert_stdout_eq_str("(ABC)");
}
//endregion

//region                                     testing the %s parametter


Test(my_printf_s_exact, test32, .init = redirect_all_std)
{
    my_printf("%5.3s", "test");
    cr_assert_stdout_eq_str("  tes");
}

Test(my_printf_s_exact, s_basic, .init = redirect_all_std)
{
    my_printf("(%s)", "hello");
    cr_assert_stdout_eq_str("(hello)");
}

Test(my_printf_s_exact, diez_is_igniored, .init = redirect_all_std)
{
    my_printf("(%#s)", "hello");
    cr_assert_stdout_eq_str("(hello)");
}

Test(my_printf_s_exact, s_empty_string, .init = redirect_all_std)
{
    my_printf("(%s)", "");
    cr_assert_stdout_eq_str("()");
}

Test(my_printf_s_exact, s_spaces, .init = redirect_all_std)
{
    my_printf("(%s)", "  ab ");
    cr_assert_stdout_eq_str("(  ab )");
}

/* ========= WIDTH & ALIGNMENT ========= */

Test(my_printf_s_exact, width_right_aligned, .init = redirect_all_std)
{
    my_printf("(%10s)", "abc");
    cr_assert_stdout_eq_str("(       abc)");
}

Test(my_printf_s_exact, width_left_aligned, .init = redirect_all_std)
{
    my_printf("(%-10s)", "abc");
    cr_assert_stdout_eq_str("(abc       )");
}

Test(my_printf_s_exact, width_exact_fit, .init = redirect_all_std)
{
    my_printf("(%3s)", "abc");
    cr_assert_stdout_eq_str("(abc)");
}

Test(my_printf_s_exact, width_smaller_than_len, .init = redirect_all_std)
{
    my_printf("(%2s)", "abcd");
    cr_assert_stdout_eq_str("(abcd)");
}

/* ========= PRECISION (max chars) ========= */

Test(my_printf_s_exact, precision_truncates, .init = redirect_all_std)
{
    my_printf("(%.3s)", "abcdef");
    cr_assert_stdout_eq_str("(abc)");
}

Test(my_printf_s_exact, precision_zero_prints_empty, .init = redirect_all_std)
{
    my_printf("(%.0s)", "abcdef");
    cr_assert_stdout_eq_str("()");
}

Test(my_printf_s_exact, width_and_precision, .init = redirect_all_std)
{
    my_printf("(%8.3s)", "abcdef");
    cr_assert_stdout_eq_str("(     abc)");
}

Test(my_printf_s_exact, left_align_with_precision, .init = redirect_all_std)
{
    my_printf("(%-8.3s)", "abcdef");
    cr_assert_stdout_eq_str("(abc     )");
}

/* ========= COMBINED EXAMPLES ========= */

Test(my_printf_s_exact, combo_width_left, .init = redirect_all_std)
{
    my_printf("(%-5s|%7.4s)", "hi", "world");
    cr_assert_stdout_eq_str("(hi   |   worl)");
}

//endregion

//region                                               testing specific cases


Test(my_printf, nothing_with_empty_quotes, .init = redirect_all_std)
{
    my_printf("");
    cr_assert_stdout_eq_str("");
}

Test(my_printf, wrong_specifier, .init = redirect_all_std)
{
    my_printf("%z", 12);
    cr_assert_stderr_eq_str("this specifier does not exist");
}

Test(my_printf, not_done_yet, .init = redirect_all_std)
{
   int a = my_printf("%a", 12);
    cr_assert_eq(a, 0);
}

Test(my_printf, not_done_yet_2, .init = redirect_all_std)
{
    int a = my_printf("%A", 12);
    cr_assert_eq(a, 0);
}

Test(my_printf, not_done_yet_3, .init = redirect_all_std)
{
    int a = my_printf("%G", 12);
    cr_assert_eq(a, 0);
}

//endregion

//region                                                testing the %f function

/* ---------- Basique / défaut (précision 6) ---------- */

Test(my_printf_f_exact, f_simple_positive_default_precision, .init = redirect_all_std)
{
    my_printf("(%f)", 42.0);
    cr_assert_stdout_eq_str("(42.000000)");
}

Test(my_printf_f_exact, f_simple_negative_default_precision, .init = redirect_all_std)
{
    my_printf("(%f)", -42.0);
    cr_assert_stdout_eq_str("(-42.000000)");
}

Test(my_printf_f_exact, f_zero_default_precision, .init = redirect_all_std)
{
    my_printf("(%f)", 0.0);
    cr_assert_stdout_eq_str("(0.000000)");
}

/* ---------- Précision ---------- */

Test(my_printf_f_precision, f_precision_zero_round_down, .init = redirect_all_std)
{
    my_printf("(%.0f)", 3.4);
    cr_assert_stdout_eq_str("(3)");
}

Test(my_printf_f_precision, f_precision_zero_round_up, .init = redirect_all_std)
{
    my_printf("(%.0f)", 3.6);
    cr_assert_stdout_eq_str("(4)");
}

Test(my_printf_f_precision, f_precision_2, .init = redirect_all_std)
{
    my_printf("(%.2f)", 3.14159);
    cr_assert_stdout_eq_str("(3.14)");
}

Test(my_printf_f_precision, f_precision_6_rounding, .init = redirect_all_std)
{
    my_printf("(%.6f)", 3.1415926535);
    cr_assert_stdout_eq_str("(3.141593)");
}

Test(my_printf_f_precision, f_precision_10, .init = redirect_all_std)
{
    my_printf("(%.10f)", 1.5);
    cr_assert_stdout_eq_str("(1.5000000000)");
}

/* ---------- Largeur de champ & alignement ---------- */

Test(my_printf_f_width, f_width_with_spaces, .init = redirect_all_std)
{
    double test = 12.5;

    my_printf("(%8.2f)\n", test); /* "   12.50" */
    cr_assert_stdout_eq_str("(12.50)\n");
}

Test(my_printf_f_width, f_width_with_sign_negative, .init = redirect_all_std)
{
    my_printf("(%8.2f)", -1.5); /* "   -1.50" */
    cr_assert_stdout_eq_str("(   -1.50)");
}

Test(my_printf_f_width, f_left_justify, .init = redirect_all_std)
{
    my_printf("(%-8.2f)", 1.5); /* "1.50    " */
    cr_assert_stdout_eq_str("(1.50    )");
}

Test(my_printf_f_width, f_zero_pad, .init = redirect_all_std)
{
    my_printf("(%08.2f)", 1.5); /* "00001.50" */
    cr_assert_stdout_eq_str("(00001.50)");
}

Test(my_printf_f_width, f_zero_pad_negative, .init = redirect_all_std)
{
    my_printf("(%010.2f)", -12.3); /* "-000012.30" */
    cr_assert_stdout_eq_str("(-000012.30)");
}

/* ---------- Flags: +, espace, # ---------- */

Test(my_printf_f_flags, f_plus_flag_positive, .init = redirect_all_std)
{
    my_printf("(%+f)", 2.0);
    cr_assert_stdout_eq_str("(+2.000000)");
}

Test(my_printf_f_flags, f_space_flag_positive, .init = redirect_all_std)
{
    my_printf("(% f)", 2.0);
    cr_assert_stdout_eq_str("( 2.000000)");
}

Test(my_printf_f_flags, f_space_flag_ignored_on_negative, .init = redirect_all_std)
{
    my_printf("(% f)", -2.0);
    cr_assert_stdout_eq_str("(-2.000000)");
}

Test(my_printf_f_flags, f_plus_overrides_space, .init = redirect_all_std)
{
    my_printf("(% +f)", 1.0); /* '+' doit primer sur ' ' */
    cr_assert_stdout_eq_str("(+1.000000)");
}

Test(my_printf_f_flags, f_hash_with_zero_precision_forces_dot, .init = redirect_all_std)
{
    my_printf("(%#.0f)", 3.0);
    cr_assert_stdout_eq_str("(3.)");
}

/* ---------- Combinaisons de flags ---------- */

Test(my_printf_f_combo, f_plus_zero_pad_width_precision, .init = redirect_all_std)
{
    my_printf("(%+010.2f)", 12.3); /* "+000012.30" */
    cr_assert_stdout_eq_str("(+000012.30)");
}

Test(my_printf_f_combo, f_left_justify_with_precision_and_width, .init = redirect_all_std)
{
    my_printf("(%-10.3f)", 7.25); /* "7.250     " */
    cr_assert_stdout_eq_str("(7.250     )");
}

Test(my_printf_f_combo, f_space_zero_pad_width_precision, .init = redirect_all_std)
{
    my_printf("(% 010.2f)", 12.5); /* " 000012.50" */
    cr_assert_stdout_eq_str("( 000012.50)");
}

/* ---------- Cas sûrs de l’arrondi (valeurs exactement représentables en binaire) ---------- */

Test(my_printf_f_rounding_safe, f_rounding_exact_binary_1_5, .init = redirect_all_std)
{
    my_printf("(%.2f)", 1.5); /* 1.50 */
    cr_assert_stdout_eq_str("(1.50)");
}

Test(my_printf_f_rounding_safe, f_rounding_exact_binary_2_25, .init = redirect_all_std)
{
    my_printf("(%.2f)", 2.25); /* 2.25 */
    cr_assert_stdout_eq_str("(2.25)");
}

Test(my_printf, puting_floats_simply, .init = redirect_all_std)
{
    my_printf("%f", 42.42);
    cr_assert_stdout_eq_str("42.420000");
}

Test(my_printf, puting_floats_with_a_length_of_6, .init = redirect_all_std)
{
    my_printf("%f", 42.427565);
    cr_assert_stdout_eq_str("42.427565");
}

Test(my_printf, puting_floats_greater_than_6, .init = redirect_all_std)
{
    my_printf("%f", 42.4275655558);
    cr_assert_stdout_eq_str("42.427566");
}

Test(my_printf, puting_floats_way_greater_than_6_more, .init = redirect_all_std)
{
    my_printf("%f", 42.42756555555555555555555555555555555555555555555555555555558);
    cr_assert_stdout_eq_str("42.427566");
}

Test(my_printf, puting_floats_way_greater_than_6_less, .init = redirect_all_std)
{
    my_printf("%f", 42.42756555555555555555555555555555555555555555555555555555552);
    cr_assert_stdout_eq_str("42.427566");
}

Test(my_printf, testing_the_return_value, .init = redirect_all_std)
{
    const int a = my_printf("%f", 42.427565);
    const int b = printf("%f", 42.427565);

    cr_assert_eq(a, b);
}
//endregion

//region                                      testing the %x function

Test(my_printf, test, .init = redirect_all_std)
{
    my_printf("%#4x", 26);
    cr_assert_stdout_eq_str("0x1a");
}

Test(my_printf, test2, .init = redirect_all_std)
{
    my_printf("%-.4x", 26);
    cr_assert_stdout_eq_str("001a");
}

Test(my_printf, test_hexadecimal_x, .init = redirect_all_std)
{
    my_printf("%x", 26);
    cr_assert_stdout_eq_str("1a");
}

Test(my_printf_x_basic, simple_hexadecimal, .init = redirect_all_std)
{
    my_printf("(%x)", 255);
    cr_assert_stdout_eq_str("(ff)");
}

Test(my_printf_x_basic, zero_value, .init = redirect_all_std)
{
    my_printf("(%x)", 0);
    cr_assert_stdout_eq_str("(0)");
}

Test(my_printf_x_basic, multiple_values, .init = redirect_all_std)
{
    my_printf("(%x %x %x)", 10, 15, 255);
    cr_assert_stdout_eq_str("(a f ff)");
}

/* ========= FLAGS ========= */

Test(my_printf_x_flags, hashtag_prefix, .init = redirect_all_std)
{
    my_printf("(%#x)", 255);
    cr_assert_stdout_eq_str("(0xff)");
}

Test(my_printf_x_flags, hashtag_zero_value_no_prefix, .init = redirect_all_std)
{
    my_printf("(%#x)", 0);
    cr_assert_stdout_eq_str("(0)");
}

Test(my_printf_x_flags, zero_padding, .init = redirect_all_std)
{
    my_printf("(%08x)", 255);
    cr_assert_stdout_eq_str("(000000ff)");
}

Test(my_printf_x_flags, zero_padding_with_prefix, .init = redirect_all_std)
{
    my_printf("(%#08x)", 255);
    cr_assert_stdout_eq_str("(0x0000ff)");
}

Test(my_printf_x_flags, left_align, .init = redirect_all_std)
{
    my_printf("(%-8x)", 255);
    cr_assert_stdout_eq_str("(ff      )");
}

/* ========= WIDTH ========= */

Test(my_printf_x_width, width_right_aligned, .init = redirect_all_std)
{
    my_printf("(%8x)", 255);
    cr_assert_stdout_eq_str("(      ff)");
}

Test(my_printf_x_width, width_left_aligned, .init = redirect_all_std)
{
    my_printf("(%-8x)", 255);
    cr_assert_stdout_eq_str("(ff      )");
}

/* ========= PRECISION ========= */

Test(my_printf_x_precision, precision_increases_digits, .init = redirect_all_std)
{
    my_printf("(%.6x)", 255);
    cr_assert_stdout_eq_str("(0000ff)");
}

Test(my_printf_x_precision, precision_zero_and_value_zero, .init = redirect_all_std)
{
    my_printf("(%.0x)", 0);
    cr_assert_stdout_eq_str("()");
}

Test(my_printf_x_precision, precision_beats_zero_padding, .init = redirect_all_std)
{
    my_printf("(%08.4x)", 255);
    cr_assert_stdout_eq_str("(    00ff)");
}

/* ========= COMBINED FLAGS ========= */

Test(my_printf_x_combo, combo_hashtag_zero_width, .init = redirect_all_std)
{
    my_printf("(%#08x)", 255);
    cr_assert_stdout_eq_str("(0x0000ff)");
}

/* ========= UPPERCASE HEXA ========= */

Test(my_printf_x_uppercase, simple_uppercase, .init = redirect_all_std)
{
    my_printf("(%X)", 255);
    cr_assert_stdout_eq_str("(FF)");
}

/* ========= LENGTH MODIFIERS ========= */

Test(my_printf_x_length, hh_modifier, .init = redirect_all_std)
{
    unsigned char v = 255;
    my_printf("(%hhx)", v);
    cr_assert_stdout_eq_str("(ff)");
}

Test(my_printf_x_length, h_modifier, .init = redirect_all_std)
{
    unsigned short v = 65535;
    my_printf("(%hx)", v);
    cr_assert_stdout_eq_str("(ffff)");
}

Test(my_printf_x_length, l_modifier, .init = redirect_all_std)
{
    unsigned long v = 0xABCDEFUL;
    my_printf("(%lx)", v);
    cr_assert_stdout_eq_str("(abcdef)");
}

Test(my_printf_x_length, ll_modifier, .init = redirect_all_std)
{
    unsigned long long v = 0x123456789ABCDEF0ULL;
    my_printf("(%llx)", v);
    cr_assert_stdout_eq_str("(123456789abcdef0)");
}

Test(my_printf_x_length, j_modifier, .init = redirect_all_std)
{
    uintmax_t v = 0xFFFFFFFFFFFFFFFFULL;
    my_printf("(%jx)", v);
    cr_assert_stdout_eq_str("(ffffffffffffffff)");
}

Test(my_printf_x_length, z_modifier, .init = redirect_all_std)
{
    size_t v = 0x1234;
    my_printf("(%zx)", v);
    cr_assert_stdout_eq_str("(1234)");
}

//endregion

//region                                       testing the %X function

Test(my_printf, test1, .init = redirect_all_std)
{
    my_printf("%#4X", 26);
    cr_assert_stdout_eq_str("0X1A");
}

Test(my_printf, test12, .init = redirect_all_std)
{
    my_printf("%-.4X", 26);
    cr_assert_stdout_eq_str("001A");
}


Test(my_printf, test_hexadecimal_X, .init = redirect_all_std)
{
    my_printf("%X", 26);
    cr_assert_stdout_eq_str("1A");
}

Test(my_printf_X_basic, simple_hexadecimal, .init = redirect_all_std)
{
    my_printf("(%X)", 255);
    cr_assert_stdout_eq_str("(FF)");
}

Test(my_printf_X_basic, zero_value, .init = redirect_all_std)
{
    my_printf("(%X)", 0);
    cr_assert_stdout_eq_str("(0)");
}

Test(my_printf_X_basic, multiple_values, .init = redirect_all_std)
{
    my_printf("(%X %X %X)", 10, 15, 255);
    cr_assert_stdout_eq_str("(A F FF)");
}

/* ========= FLAGS ========= */

Test(my_printf_X_flags, hashtag_prefix, .init = redirect_all_std)
{
    my_printf("(%#X)", 255);
    cr_assert_stdout_eq_str("(0XFF)");
}

Test(my_printf_X_flags, hashtag_zero_value_no_prefix, .init = redirect_all_std)
{
    my_printf("(%#X)", 0);
    cr_assert_stdout_eq_str("(0)");
}

Test(my_printf_X_flags, zero_padding, .init = redirect_all_std)
{
    my_printf("(%08X)", 255);
    cr_assert_stdout_eq_str("(000000FF)");
}

Test(my_printf_X_flags, zero_padding_with_prefix, .init = redirect_all_std)
{
    my_printf("(%#08X)", 255);
    cr_assert_stdout_eq_str("(0X0000FF)");
}

Test(my_printf_X_flags, left_align, .init = redirect_all_std)
{
    my_printf("(%-8X)", 255);
    cr_assert_stdout_eq_str("(FF      )");
}

/* ========= WIDTH ========= */

Test(my_printf_X_width, width_right_aligned, .init = redirect_all_std)
{
    my_printf("(%8X)", 255);
    cr_assert_stdout_eq_str("(      FF)");
}

Test(my_printf_X_width, width_left_aligned, .init = redirect_all_std)
{
    my_printf("(%-8X)", 255);
    cr_assert_stdout_eq_str("(FF      )");
}

/* ========= PRECISION ========= */

Test(my_printf_X_precision, precision_increases_digits, .init = redirect_all_std)
{
    my_printf("(%.6X)", 255);
    cr_assert_stdout_eq_str("(0000FF)");
}

Test(my_printf_X_precision, precision_zero_and_value_zero, .init = redirect_all_std)
{
    my_printf("(%.0X)", 0);
    cr_assert_stdout_eq_str("()");
}

Test(my_printf_X_precision, precision_beats_zero_padding, .init = redirect_all_std)
{
    my_printf("(%08.4X)", 255);
    cr_assert_stdout_eq_str("(    00FF)");
}

/* ========= COMBINED FLAGS ========= */

Test(my_printf_X_combo, combo_hashtag_zero_width, .init = redirect_all_std)
{
    my_printf("(%#08X)", 255);
    cr_assert_stdout_eq_str("(0X0000FF)");
}

/* ========= UPPERCASE HEXA ========= */

Test(my_printf_X_uppercase, simple_uppercase, .init = redirect_all_std)
{
    my_printf("(%X)", 255);
    cr_assert_stdout_eq_str("(FF)");
}

/* ========= LENGTH MODIFIERS ========= */

Test(my_printf_X_length, hh_modifier, .init = redirect_all_std)
{
    unsigned char v = 255;
    my_printf("(%hhX)", v);
    cr_assert_stdout_eq_str("(FF)");
}

Test(my_printf_X_length, h_modifier, .init = redirect_all_std)
{
    unsigned short v = 65535;
    my_printf("(%hX)", v);
    cr_assert_stdout_eq_str("(FFFF)");
}

Test(my_printf_X_length, l_modifier, .init = redirect_all_std)
{
    unsigned long v = 0xABCDEFUL;
    my_printf("(%lX)", v);
    cr_assert_stdout_eq_str("(ABCDEF)");
}

Test(my_printf_X_length, ll_modifier, .init = redirect_all_std)
{
    unsigned long long v = 0x123456789ABCDEF0ULL;
    my_printf("(%llX)", v);
    cr_assert_stdout_eq_str("(123456789ABCDEF0)");
}

Test(my_printf_X_length, j_modifier, .init = redirect_all_std)
{
    uintmax_t v = 0xFFFFFFFFFFFFFFFFULL;
    my_printf("(%jX)", v);
    cr_assert_stdout_eq_str("(FFFFFFFFFFFFFFFF)");
}

Test(my_printf_X_length, z_modifier, .init = redirect_all_std)
{
    size_t v = 0x1234;
    my_printf("(%zX)", v);
    cr_assert_stdout_eq_str("(1234)");
}

//endregion

//region                                          testing the %o function

Test(my_printf, test_ll, .init = redirect_all_std)
{
    my_printf("%llo", 26);
    cr_assert_stdout_eq_str("32");
}

Test(my_printf, test_j, .init = redirect_all_std)
{
    my_printf("%jo", 26);
    cr_assert_stdout_eq_str("32");
}

Test(my_printf, test_z, .init = redirect_all_std)
{
    my_printf("%zo", 26);
    cr_assert_stdout_eq_str("32");
}

Test(my_printf, test_octal_o, .init = redirect_all_std)
{
    my_printf("%o", 26);
    cr_assert_stdout_eq_str("32");
}

Test(my_printf, test_octal_o_in_str, .init = redirect_all_std)
{
    my_printf("hello%oworld", 26);
    cr_assert_stdout_eq_str("hello32world");
}

Test(my_printf_o_exact, o_basic, .init = redirect_all_std)
{
    my_printf("(%o)", 5);
    cr_assert_stdout_eq_str("(5)");
}

Test(my_printf_o_exact, o_zero, .init = redirect_all_std)
{
    my_printf("(%o)", 0);
    cr_assert_stdout_eq_str("(0)");
}

Test(my_printf_o_exact, o_width_right, .init = redirect_all_std)
{
    my_printf("(%8o)", 5);
    cr_assert_stdout_eq_str("(       5)");
}

Test(my_printf_o_exact, o_width_left, .init = redirect_all_std)
{
    my_printf("(%-8o)", 5);
    cr_assert_stdout_eq_str("(5       )");
}

Test(my_printf_o_exact, o_zero_padding, .init = redirect_all_std)
{
    my_printf("(%08o)", 5);
    cr_assert_stdout_eq_str("(00000005)");
}

Test(my_printf_o_exact, o_precision, .init = redirect_all_std)
{
    my_printf("(%.5o)", 5);
    cr_assert_stdout_eq_str("(00005)");
}

Test(my_printf_o_exact, o_precision_zero_value, .init = redirect_all_std)
{
    my_printf("(%.0o)", 0);
    cr_assert_stdout_eq_str("()");
}

Test(my_printf_o, simple_number, .init = redirect_all_std)
{
    my_printf("%o", 5);
    cr_assert_stdout_eq_str("5");
}

Test(my_printf_o, zero_value, .init = redirect_all_std)
{
    my_printf("%o", 0);
    cr_assert_stdout_eq_str("0");
}

Test(my_printf_o, large_number, .init = redirect_all_std)
{
    my_printf("%o", 255);
    cr_assert_stdout_eq_str("377");
}

Test(my_printf_o, flag_hash_prefix, .init = redirect_all_std)
{
    my_printf("%#o", 5);
    cr_assert_stdout_eq_str("05");
}

Test(my_printf_o, flag_hash_prefix_zero, .init = redirect_all_std)
{
    my_printf("%#o", 0);
    // Le flag '#' ne double pas le zéro : il reste "0"
    cr_assert_stdout_eq_str("0");
}

Test(my_printf_o, flag_zero_padding, .init = redirect_all_std)
{
    my_printf("%08o", 5);
    cr_assert_stdout_eq_str("00000005");
}

Test(my_printf_o, flag_minus_left_align, .init = redirect_all_std)
{
    my_printf("%-8o", 5);
    cr_assert_stdout_eq_str("5       ");
}

Test(my_printf_o, flag_combined_hash_zero, .init = redirect_all_std)
{
    my_printf("%#08o", 5);
    cr_assert_stdout_eq_str("00000005"); // préfixe déjà inclus dans le remplissage
}

Test(my_printf_o, width_field, .init = redirect_all_std)
{
    my_printf("%8o", 5);
    cr_assert_stdout_eq_str("       5");
}

Test(my_printf_o, width_and_prefix, .init = redirect_all_std)
{
    my_printf("%#10o", 5);
    cr_assert_stdout_eq_str("        05");
}

Test(my_printf_o, unsigned_long, .init = redirect_all_std)
{
    my_printf("%lo", 1024L);
    cr_assert_stdout_eq_str("2000");
}

Test(my_printf_o, min_uint, .init = redirect_all_std)
{
    my_printf("%o", 0U);
    cr_assert_stdout_eq_str("0");
}

Test(my_printf_o, combo_hash_width_precision, .init = redirect_all_std)
{
    my_printf("%#12.8o", 42);
    cr_assert_stdout_eq_str("    00000052");
}

Test(my_printf_o, combo_minus_hash, .init = redirect_all_std)
{
    my_printf("%-#10o", 3);
    cr_assert_stdout_eq_str("03        ");
}

//endregion

//region                                          testing the %b function


Test(my_printf, test_binary_b, .init = redirect_all_std)
{
    my_printf("%b", 26);
    cr_assert_stdout_eq_str("11010");
}

Test(my_printf, test_binary_b_in_str, .init = redirect_all_std)
{
    my_printf("hello%bworld", 26);
    cr_assert_stdout_eq_str("hello11010world");
}

Test(my_printf_b_exact, b_basic, .init = redirect_all_std)
{
    my_printf("(%b)", 5);
    cr_assert_stdout_eq_str("(101)");
}

Test(my_printf_b_exact, b_zero, .init = redirect_all_std)
{
    my_printf("(%b)", 0);
    cr_assert_stdout_eq_str("(0)");
}

Test(my_printf_b_exact, b_width_right, .init = redirect_all_std)
{
    my_printf("(%8b)", 5);
    cr_assert_stdout_eq_str("(     101)");
}

Test(my_printf_b_exact, b_width_left, .init = redirect_all_std)
{
    my_printf("(%-8b)", 5);
    cr_assert_stdout_eq_str("(101     )");
}

Test(my_printf_b_exact, b_zero_padding, .init = redirect_all_std)
{
    my_printf("(%08b)", 5);
    cr_assert_stdout_eq_str("(00000101)");
}

Test(my_printf_b_exact, b_precision, .init = redirect_all_std)
{
    my_printf("(%.8b)", 5);
    cr_assert_stdout_eq_str("(00000101)");
}

Test(my_printf_b_exact, b_precision_zero_value, .init = redirect_all_std)
{
    my_printf("(%.0b)", 0);
    cr_assert_stdout_eq_str("()");
}

Test(my_printf_b, simple_number, .init = redirect_all_std)
{
    my_printf("%b", 5);
    cr_assert_stdout_eq_str("101");
}

Test(my_printf_b, zero_value, .init = redirect_all_std)
{
    my_printf("%b", 0);
    cr_assert_stdout_eq_str("0");
}

Test(my_printf_b, large_number, .init = redirect_all_std)
{
    my_printf("%b", 255);
    cr_assert_stdout_eq_str("11111111");
}

Test(my_printf_b, flag_hash_prefix, .init = redirect_all_std)
{
    my_printf("%#b", 5);
    cr_assert_stdout_eq_str("0b101");
}

Test(my_printf_b, flag_zero_padding, .init = redirect_all_std)
{
    my_printf("%08b", 5);
    cr_assert_stdout_eq_str("00000101");
}

Test(my_printf_b, flag_minus_left_align, .init = redirect_all_std)
{
    my_printf("%-8b", 5);
    cr_assert_stdout_eq_str("101     ");
}

Test(my_printf_b, flag_combined_hash_zero, .init = redirect_all_std)
{
    my_printf("%#08b", 5);
    cr_assert_stdout_eq_str("0b000101");
}

Test(my_printf_b, width_field, .init = redirect_all_std)
{
    my_printf("%8b", 5);
    cr_assert_stdout_eq_str("     101");
}

Test(my_printf_b, width_and_prefix, .init = redirect_all_std)
{
    my_printf("%#10b", 5);
    cr_assert_stdout_eq_str("     0b101");
}

Test(my_printf_b, unsigned_long, .init = redirect_all_std)
{
    my_printf("%lb", 1024L);
    cr_assert_stdout_eq_str("10000000000");
}

Test(my_printf_b, min_uint, .init = redirect_all_std)
{
    my_printf("%b", 0U);
    cr_assert_stdout_eq_str("0");
}

Test(my_printf_b, combo_hash_width_precision, .init = redirect_all_std)
{
    my_printf("%#12.8b", 42);
    cr_assert_stdout_eq_str("  0b00101010");
}

Test(my_printf_b, combo_minus_hash, .init = redirect_all_std)
{
    my_printf("%-#10b", 3);
    cr_assert_stdout_eq_str("0b11      ");
}

//endregion

//region                                          testing the %B function

Test(my_printf, test_binary_B, .init = redirect_all_std)
{
    my_printf("%B", 26);
    cr_assert_stdout_eq_str("11010");
}

Test(my_printf, test_binary_B_in_str, .init = redirect_all_std)
{
    my_printf("hello%Bworld", 26);
    cr_assert_stdout_eq_str("hello11010world");
}

Test(my_printf_B_exact, B_basic, .init = redirect_all_std)
{
    my_printf("(%B)", 5);
    cr_assert_stdout_eq_str("(101)");
}

Test(my_printf_B_exact, B_zero, .init = redirect_all_std)
{
    my_printf("(%B)", 0);
    cr_assert_stdout_eq_str("(0)");
}

Test(my_printf_B_exact, B_width_right, .init = redirect_all_std)
{
    my_printf("(%8B)", 5);
    cr_assert_stdout_eq_str("(     101)");
}

Test(my_printf_B_exact, B_width_left, .init = redirect_all_std)
{
    my_printf("(%-8B)", 5);
    cr_assert_stdout_eq_str("(101     )");
}

Test(my_printf_B_exact, B_zero_padding, .init = redirect_all_std)
{
    my_printf("(%08B)", 5);
    cr_assert_stdout_eq_str("(00000101)");
}

Test(my_printf_B_exact, B_precision, .init = redirect_all_std)
{
    my_printf("(%.8B)", 5);
    cr_assert_stdout_eq_str("(00000101)");
}

Test(my_printf_B_exact, B_precision_zero_value, .init = redirect_all_std)
{
    my_printf("(%.0B)", 0);
    cr_assert_stdout_eq_str("()");
}

Test(my_printf_B, simple_number, .init = redirect_all_std)
{
    my_printf("%B", 5);
    cr_assert_stdout_eq_str("101");
}

Test(my_printf_B, zero_value, .init = redirect_all_std)
{
    my_printf("%B", 0);
    cr_assert_stdout_eq_str("0");
}

Test(my_printf_B, large_number, .init = redirect_all_std)
{
    my_printf("%B", 255);
    cr_assert_stdout_eq_str("11111111");
}

Test(my_printf_B, flag_hash_prefix, .init = redirect_all_std)
{
    my_printf("%#B", 5);
    cr_assert_stdout_eq_str("0B101");   // NOTE: majuscule dans le préfixe
}

Test(my_printf_B, flag_zero_padding, .init = redirect_all_std)
{
    my_printf("%08B", 5);
    cr_assert_stdout_eq_str("00000101");
}

Test(my_printf_B, flag_minus_left_align, .init = redirect_all_std)
{
    my_printf("%-8B", 5);
    cr_assert_stdout_eq_str("101     ");
}

Test(my_printf_B, flag_combined_hash_zero, .init = redirect_all_std)
{
    my_printf("%#08B", 5);
    cr_assert_stdout_eq_str("0B000101");
}

Test(my_printf_B, width_field, .init = redirect_all_std)
{
    my_printf("%8B", 5);
    cr_assert_stdout_eq_str("     101");
}

Test(my_printf_B, width_and_prefix, .init = redirect_all_std)
{
    my_printf("%#10B", 5);
    cr_assert_stdout_eq_str("     0B101");
}

Test(my_printf_B, unsigned_long, .init = redirect_all_std)
{
    my_printf("%lB", 1024L);
    cr_assert_stdout_eq_str("10000000000");
}

Test(my_printf_B, min_uint, .init = redirect_all_std)
{
    my_printf("%B", 0U);
    cr_assert_stdout_eq_str("0");
}

Test(my_printf_B, combo_hash_width_precision, .init = redirect_all_std)
{
    my_printf("%#12.8B", 42);
    cr_assert_stdout_eq_str("  0B00101010");
}

Test(my_printf_B, combo_minus_hash, .init = redirect_all_std)
{
    my_printf("%-#10B", 3);
    cr_assert_stdout_eq_str("0B11      ");
}

//endregion

//region                                            testing the %e function


Test(my_printf, test_scientific_writing, .init = redirect_all_std)
{
    my_printf("%e", 4252525.6);
    cr_assert_stdout_eq_str("4.252525e+06");
}

//endregion

//region                                testing the %S function
Test(my_printf_S_exact, S_simple_array, .init = redirect_all_std)
{
    char *arr[] = {"Hello", "World", NULL};
    my_printf("(%S)", arr);
    cr_assert_stdout_eq_str("(Hello\nWorld)");
}

Test(my_printf_S_exact, S_single_word, .init = redirect_all_std)
{
    char *arr[] = {"OnlyOne", NULL};
    my_printf("(%S)", arr);
    cr_assert_stdout_eq_str("(OnlyOne)");
}

Test(my_printf_S_exact, S_empty_array, .init = redirect_all_std)
{
    char *arr[] = {NULL};
    my_printf("(%S)", arr);
    cr_assert_stdout_eq_str("()");
}

Test(my_printf_S_exact, S_three_words, .init = redirect_all_std)
{
    char *arr[] = {"foo", "bar", "baz", NULL};
    my_printf("(%S)", arr);
    cr_assert_stdout_eq_str("(foo\nbar\nbaz)");
}

Test(my_printf_S_exact, S_array_with_empty_string, .init = redirect_all_std)
{
    char *arr[] = {"Hello", "", "World", NULL};
    my_printf("(%S)", arr);
    cr_assert_stdout_eq_str("(Hello\n\nWorld)");
}
//endregion

//region                                testing the %m function

Test(my_printf_m_exact, write_in_error_output, .init = redirect_all_std)
{
    my_printf("%m", "Error");
    cr_assert_stderr_eq_str("Error");
}

//endregion

//region                                testing the %n function

Test(my_printf_n_exact, write_in_error_output, .init = redirect_all_std)
{
    my_printf("%n");
    cr_assert_stderr_eq_str("We have not yet implemented specifier n");
}

//endregion

//region                                testing the %p function

Test(my_printf_p_exact, write_in_error_output, .init = redirect_all_std)
{
    my_printf("%p");
    cr_assert_stderr_eq_str("We have not yet implemented specifier p");
}

//endregion

//region                                testing the %g function

Test(my_printf_g_exact, write_in_error_output, .init = redirect_all_std)
{
    my_printf("%g");
    cr_assert_stderr_eq_str("We have not yet implemented specifier g");
}

//endregion

//region                                testing the %G function

Test(my_printf_G_exact, write_in_error_output, .init = redirect_all_std)
{
    my_printf("%G");
    cr_assert_stderr_eq_str("We have not yet implemented specifier G");
}

//endregion