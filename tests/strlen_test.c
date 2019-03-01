/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2018
** File description:
** strlen_test.c
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <stdio.h>
#include "lib.h"

static size_t load_symbol(const char *s)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    static size_t (*my_strlen)(const char *) = NULL;

    if (my_strlen != NULL)
        return (my_strlen(s));
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }
    my_strlen = dlsym(handle, "strlen");
    return (0);
}

static void test_strlen(const char *s)
{
    cr_assert_eq(load_symbol(s), strlen(s));
}

Test(my_strlen, basic)
{
    load_symbol("");
    test_strlen("");
    test_strlen("a");
    test_strlen("abcd");
    test_strlen("abfdjsajfdsahfpoiewhvds;ajf;a");
}
