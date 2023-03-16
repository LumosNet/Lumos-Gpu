#include "utest.h"

void test_run(char *msg)
{
    fprintf(stderr, "[ RUN       ] %s\n", msg);
}

void test_res(int flag, char *msg)
{
    switch (flag)
    {
    case SUCCESS:
        fprintf(stderr, "[        \e[0;32mOK\e[0m ] %s\n", msg);
        break;
    case ERROR:
        fprintf(stderr, "[      \e[0;31mFAIL\e[0m ] %s\n", msg);
        break;
    default:
        break;
    }
}

void test_msg(char *msg)
{
    fprintf(stderr, "  %s\n", msg);
}

void test_msg_pass(char *msg)
{
    fprintf(stderr, "   %s \e[0;32mPASS\e[0m\n", msg);
}

void test_msg_error(char *msg)
{
    fprintf(stderr, "   %s \e[0;31mFAIL\e[0m\n", msg);
}
