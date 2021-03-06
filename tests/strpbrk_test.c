/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2018
** File description:
** strpbrk_test.c
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include "load_sym.h"

static char *my_strpbrk(const char *s1, const char *s2)
{
    static char *(*sym)(const char *, const char *) = NULL;

    if (sym)
        return (sym(s1, s2));
    sym = load_sym("strpbrk");
    return (sym(s1, s2));
}

static void test_strpbrk(const char *s1, const char *s2)
{
    char *mine = my_strpbrk(s1, s2);
    char *other = strpbrk(s1, s2);

    if (mine == NULL && other == NULL)
        cr_expect_eq(mine, other);
    else
        cr_expect_str_eq(mine, other,
        "('%s', '%s') -> actual: '%s', expected: '%s'",
        s1, s2, mine, other);
}

Test(my_strpbrk, not_found)
{
    test_strpbrk("", "");
    test_strpbrk("", "a");
    test_strpbrk("abcd", "f");
    test_strpbrk("a", "");
}

Test(my_strpbrk, found_one_char)
{
    test_strpbrk("a", "a");
    test_strpbrk("ab", "b");
    test_strpbrk("abc", "b");
}

Test(my_strpbrk, found_string)
{
    test_strpbrk("b bc", "bc");
    test_strpbrk("b bc toto", "bc ");
    test_strpbrk("yyolo", "yolo");
    test_strpbrk("totota", "tota");
    test_strpbrk("o", "lo");
    test_strpbrk("hehlo", "lo");
    test_strpbrk("fdsadsf", "iuosj");
}
