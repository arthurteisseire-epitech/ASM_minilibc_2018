/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** open_asm.c
*/

#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

static void *open_asm()
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }
    return (handle);
}

void *load_sym(const char *sym)
{
    return (dlsym(open_asm(), sym));
}

