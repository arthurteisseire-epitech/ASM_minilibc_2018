/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2018
** File description:
** strlen_test.c
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <stdio.h>
#include "load_sym.h"

static size_t my_strlen(const char *s)
{
    static size_t (*sym)(const char *) = NULL;

    if (sym)
        return (sym(s));
    sym = load_sym("strlen");
    return (sym(s));
}

static void test_strlen(const char *s)
{
    cr_assert_eq(my_strlen(s), strlen(s));
}

Test(my_strlen, basic)
{
    test_strlen("");
    test_strlen("a");
    test_strlen("abcd");
    test_strlen("abfdjsajfdsahfpoiewhvds;ajf;a");
}
