/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2018
** File description:
** strlen_test.c
*/

#include <criterion/criterion.h>

Test(my_strlen, basic)
{
    cr_assert_eq(strlen("1"), 1);
}
