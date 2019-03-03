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
    const char *mine = my_rindex(s, c);
    const char *other = rindex(s, c);

    cr_assert_eq(mine, other, "actual: '%s', expected '%s'\n", mine, other);
}

Test(my_rindex, found)
{
    test_rindex("", 0);
    test_rindex("abc", 'c');
    test_rindex("abcef", 'c');
    test_rindex("abcef", 0);
    test_rindex("afsadfdsa", ';');
}
