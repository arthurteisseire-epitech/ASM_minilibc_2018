/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2018
** File description:
** strlen_test.c
*/

#include <criterion/criterion.h>
#include "lib.h"

Test(my_strlen, basic)
{
    cr_assert_eq(my_strlen("a"), 1);
    cr_assert_eq(my_strlen(""), 0);
}
