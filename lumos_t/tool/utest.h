#ifndef UTEST_H
#define UTEST_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS            0
#define ERROR              1

#ifdef __cplusplus
extern "C" {
#endif

void test_run(char *msg);
void test_res(int flag, char *msg);
void test_msg(char *msg);
void test_msg_pass(char *msg);
void test_msg_error(char *msg);

#ifdef __cplusplus
}
#endif

#endif