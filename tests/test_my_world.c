/*
** EPITECH PROJECT, 2020
** Unit_Test_Criterion
** File description:
** Test File
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(function, t01, .init = redirect_all_stdout)
{

    cr_assert_stderr_eq_str("");
}

Test(function, t01)
{

    cr_assert_str_eq("", "");
}
