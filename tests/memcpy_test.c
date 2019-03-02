/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2018
** File description:
** memcpy_test.c
*/

#include <criterion/criterion.h>
#include "load_sym.h"

static size_t my_memcpy(void *dest, const void *src, size_t n)
{
    static size_t (*sym)(void *, const void *, size_t) = NULL;

    if (sym)
        return (sym(dest, src, n));
    sym = load_sym("memcpy");
    return (sym(dest, src, n));
}

static void test_memcpy(const void *src, size_t n)
{
    void *my = calloc(n + 1, sizeof(char));
    void *other = calloc(n + 1, sizeof(char));

    my_memcpy(my, src, n);
    memcpy(other, src, n);
    cr_assert_str_eq(my, other);
    free(my);
    free(other);
}

Test(my_memcpy, cmp)
{
    test_memcpy("", 0);
    test_memcpy("aaaa", 3);
    test_memcpy("aaaa", 4);
    test_memcpy("abcdefg", 5);
}

Test(my_memcpy, return_value)
{
    char s[] = "";

    cr_assert_eq((size_t)my_memcpy(s, "", 0), (size_t)memcpy(s, "", 0));
}
