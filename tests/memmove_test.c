/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2018
** File description:
** memmove_test.c
*/

#include <criterion/criterion.h>
#include "load_sym.h"

static size_t my_memmove(void *dest, const void *src, size_t n)
{
    static size_t (*sym)(void *, const void *, size_t) = NULL;

    if (sym)
        return (sym(dest, src, n));
    sym = load_sym("memmove");
    return (sym(dest, src, n));
}

static void test_memmove(const void *string, size_t n)
{
    char *src_got = strdup(string);
    char *got = src_got + 1;
    char *src_expected = strdup(string);
    char *expected = src_expected + 1;

    my_memmove(got, src_got, n);
    memmove(expected, src_expected, n);
    cr_assert_str_eq(got, expected);
}

Test(my_memmove, basic)
{
    test_memmove("00", 2);
}
