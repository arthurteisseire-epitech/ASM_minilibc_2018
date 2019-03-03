/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2018
** File description:
** strcasecmp.c
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include "load_sym.h"

static int my_strcasecmp(const char *s1, const char *s2)
{
    static int (*sym)(const char *, const char *) = NULL;

    if (sym)
        return (sym(s1, s2));
    sym = load_sym("strcasecmp");
    return (sym(s1, s2));
}

static void test_strcasecmp(const char *s1, const char *s2)
{
    int mine = my_strcasecmp(s1, s2);
    int other = strcasecmp(s1, s2);

    cr_expect_eq(mine, other, "actual: %d, expected: %d", mine, other);
}

Test(my_strcasecmp, basic)
{
    test_strcasecmp("", "");
    test_strcasecmp("a", "");
    test_strcasecmp("a", "b");
    test_strcasecmp("abc", "abd");
    test_strcasecmp("abc", "ab");
    test_strcasecmp("", "abc");
}
