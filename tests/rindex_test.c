/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2018
** File description:
** rindex_test.c
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include "load_sym.h"

static char *my_rindex(const char *s, char c)
{
    static char *(*sym)(const char *, char) = NULL;

    if (sym)
        return (sym(s, c));
    sym = load_sym("rindex");
    return (sym(s, c));
}

static void test_rindex(const char *s, char c)
{
    cr_assert_eq(my_rindex(s, c), rindex(s, c));
}

Test(my_rindex, found)
{
    test_rindex("", 0);
}
