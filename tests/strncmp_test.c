/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2018
** File description:
** strncmp_test.c
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include "load_sym.h"

static int my_strncmp(const char *s1, const char *s2, size_t n)
{
    static int (*sym)(const char *, const char *, size_t) = NULL;

    if (sym)
        return (sym(s1, s2, n));
    sym = load_sym("strncmp");
    return (sym(s1, s2, n));
}

static void test_strncmp(const char *s1, const char *s2, size_t n)
{
    int mine = my_strncmp(s1, s2, n);
    int other = strncmp(s1, s2, n);

    cr_expect_eq(mine, other, "actual: %d, expected: %d", mine, other);
}

Test(my_strncmp, n_sup)
{
    test_strncmp("", "", 10);
    test_strncmp("a", "", 10);
    test_strncmp("a", "b", 10);
    test_strncmp("abc", "abd", 10);
    test_strncmp("abc", "ab", 10);
    test_strncmp("", "abc", 10);
}

Test(my_strncmp, n_inf)
{
    test_strncmp("abc", "abd", 2);
    test_strncmp("a", "abd", 2);
    test_strncmp("abbbb", "abbbb", 2);
    test_strncmp("ac", "ab", 2);
}
