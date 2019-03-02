/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2018
** File description:
** memset_test.c
*/

#include <criterion/criterion.h>
#include "load_sym.h"

static size_t my_memset(void *s, int c, size_t n)
{
    static size_t (*sym)(void *, int, size_t) = NULL;

    if (sym)
        return (sym(s, c, n));
    sym = load_sym("memset");
    return (sym(s, c, n));
}

static void test_memset(int c, size_t n)
{
    char *my = calloc(n, sizeof(char));
    char *other = calloc(n, sizeof(char));

    my_memset(my, c, n);
    memset(other, c, n);
    cr_assert_str_eq(my, other);
    free(my);
    free(other);
}

Test(my_memset, cmp)
{
    test_memset('a', 0);
    test_memset('a', 1);
    test_memset('a', 2);
    test_memset('x', 100);
}

static void test_return_value(int c, size_t n)
{
    char s[n];

    cr_assert_eq((size_t)my_memset(s, c, n), (size_t)memset(s, c, n));
}

Test(my_memset, return_value)
{
    test_return_value(0, 0);
    test_return_value('a', 2);
}
