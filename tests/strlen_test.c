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
    my_strlen = (size_t (*)(const char *)) dlsym(handle, "strlen");
    return (0);
}

Test(my_strlen, basic)
{
    load_symbol("");
    cr_assert_eq(load_symbol(""), strlen(""));
    cr_assert_eq(load_symbol("a"), strlen("a"));
    cr_assert_eq(load_symbol("abcd"), 4);
    cr_assert_eq(load_symbol("abcdefghijklmnopqrstuvwxyz\n"), 27);
}
