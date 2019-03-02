/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2018
** File description:
** strcmp_test.c
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include "load_sym.h"

static int my_strcmp(const char *s1, const char *s2)
{
    static int (*sym)(const char *, const char *) = NULL;

    if (sym)
        return (sym(s1, s2));
    sym = load_sym("strcmp");
    return (sym(s1, s2));
}

static void test_strcmp(const char *s1, const char *s2)
{
    int mine = my_strcmp(s1, s2);
    int other = strcmp(s1, s2);

    cr_assert_eq(mine, other, "actual: %d, expected: %d", mine, other);
}

Test(my_strcmp, basic)
{
    test_strcmp("", "");
    test_strcmp("a", "");
    test_strcmp("a", "b");
}
