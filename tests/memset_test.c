/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2018
** File description:
** memset.c
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
