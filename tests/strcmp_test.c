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
    cr_assert_eq(my_strcmp(s1, s2), strcmp(s1, s2));
}

Test(my_strcmp, basic)
{
    test_strcmp("", "");
}
