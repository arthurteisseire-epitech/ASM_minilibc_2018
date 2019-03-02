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

void *load_sym(const char *sym_name)
{
    void *sym = dlsym(open_asm(), sym_name);
    const char *format = "\n-----\n\n";

    if (sym == NULL) {
        fprintf(stderr, "%s%s symbol doesn't exists, missing in Makefile?\n%s",
            format, sym_name, format);
        exit(EXIT_FAILURE);
    }
    return (dlsym(open_asm(), sym_name));
}

