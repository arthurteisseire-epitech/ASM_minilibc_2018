/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** strchr_test.c
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include "lib.h"

static char *my_strchr(const char *s, char c)
{
    static char *(*sym)(const char *, char) = NULL;

    if (sym)
        return (sym(s, c));
    sym = dlsym(open_asm(), "strchr");
    return (sym(s, c));
}

static void test_strchr(const char *s, char c)
{
    cr_assert_eq(my_strchr(s, c), strchr(s, c));
}

Test(my_strchr, basic)
{
    test_strchr("", 0);
}
