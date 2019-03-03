/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2018
** File description:
** strstr_test.c
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include "load_sym.h"

static char *my_strstr(const char *s1, const char *s2)
{
    static char *(*sym)(const char *, const char *) = NULL;

    if (sym)
        return (sym(s1, s2));
    sym = load_sym("strstr");
    return (sym(s1, s2));
}

static void test_strstr(const char *s1, const char *s2)
{
    char *mine = my_strstr(s1, s2);
    char *other = strstr(s1, s2);

    cr_expect_str_eq(mine, other, "actual: %s, expected: %s", mine, other);
}

Test(my_strstr, not_found)
{
    test_strstr("", "");
}
