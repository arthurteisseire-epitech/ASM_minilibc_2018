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

static void test_memcpy(const void *src, size_t n)
{
    void *my = calloc(n + 1, sizeof(char));
    void *other = calloc(n + 1, sizeof(char));

    my_memmove(my, src, n);
    memcpy(other, src, n);
    cr_assert_str_eq(my, other);
    free(my);
    free(other);
}

Test(my_memmove, memcpy)
{
    test_memcpy("", 0);
    test_memcpy("aaaa", 3);
    test_memcpy("aaaa", 4);
    test_memcpy("abcdefg", 5);
}
Test(my_memmove, basic)
{
    test_memmove("00123", 2);
    test_memmove("0123456789", 10);
    test_memmove(";ldsakjfsa;ld", 12);
}
