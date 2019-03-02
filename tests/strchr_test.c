/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** strchr_test.c
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include "load_sym.h"

static char *my_strchr(const char *s, char c)
{
    static char *(*sym)(const char *, char) = NULL;

    if (sym)
        return (sym(s, c));
    sym = load_sym("strchr");
    return (sym(s, c));
}

static void test_strchr(const char *s, char c)
{
    cr_assert_eq(my_strchr(s, c), strchr(s, c));
}

Test(my_strchr, found)
{
    test_strchr("", 0);
    test_strchr("a", 0);
    test_strchr("a", 'a');
    test_strchr("abcd", 'd');
    test_strchr("abcd", 'c');
}

Test(my_strchr, not_found)
{
    test_strchr("a", 'b');
    test_strchr("abcd", 'x');
}
