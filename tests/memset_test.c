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

static void test_memset(int c, size_t n)
{
    char s[n];
//    char my[n];
//    char other[n];

    cr_assert_eq((size_t)my_memset(s, c, n), (size_t)memset(s, c, n));
//    my_memset(my, c, n);
//    memset(other, c, n);
//    cr_assert_str_eq(my, other);
}

Test(my_memset, basic)
{
    test_memset(0, 0);
}
