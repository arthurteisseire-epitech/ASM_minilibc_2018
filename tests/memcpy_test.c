/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2018
** File description:
** memcpy_test.c
*/

#include <criterion/criterion.h>
#include "load_sym.h"

static size_t my_memcpy(void *dest, void *src, size_t n)
{
    static size_t (*sym)(void *, void *, size_t) = NULL;

    if (sym)
        return (sym(dest, src, n));
    sym = load_sym("memcpy");
    return (sym(dest, src, n));
}

static void test_memcpy(void *src, size_t n)
{
    char *my = calloc(n, sizeof(char));
    char *other = calloc(n, sizeof(char));

    my_memcpy(my, src, n);
    memcpy(other, src, n);
    cr_assert_str_eq(my, other);
    free(my);
    free(other);
}

Test(my_memcpy, cmp)
{
    test_memcpy("", 0);
    test_memcpy("", 1);
    test_memcpy("a", 0);
    test_memcpy("a", 1);
}

Test(my_memcpy, return_value)
{
    char s[] = "";

    cr_assert_eq((size_t)my_memcpy(s, "", 0), (size_t)memcpy(s, "", 0));
}