#include "../src/core.h"
#include "../thirdparty/ctest.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int h, kol, i = 0;
char *hchar = NULL;
char *ichar = NULL;


CTEST(input, choose_point)
{
    hchar = malloc(100);
    strcpy(hchar, "1"); // Right input
    hchar[1] = '\n';
    int c1 = choose_point(4, hchar, &h);

    strcpy(hchar, "12"); //Input beyond limits
    hchar[2] = '\n';
    int c2 = choose_point(4, hchar, &h);

    hchar[0] = '\n';
    int c3 = choose_point(4, hchar, &h);

    strcpy(hchar, "E2E9"); // mixed input
    hchar[4] = '\n';
    int c4 = choose_point(4, hchar, &h);

    strcpy(hchar, "h"); // Input not num
    hchar[1] = '\n';
    int c5 = choose_point(4, hchar, &h);

    const int exp1 = 1;
    const int exp2 = 0;
    const int exp3 = 0;
    const int exp4 = 0;
    const int exp5 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
}

CTEST(input, scan_number)
{
    ichar = malloc(100);
    kol = 4;
    strcpy(ichar, "1234"); // Right input
    ichar[4] = '\n';
    int c1 = scans(kol, ichar, &i);

    kol = 5;
    strcpy(ichar, "12345"); // Right input
    ichar[5] = '\n';
    int c2 = scans(kol, ichar, &i);
    kol = 6;
    strcpy(ichar, "123456"); // Right input
    ichar[6] = '\n';
    int c3 = scans(kol, ichar, &i);

    kol = 3;
    strcpy(ichar, "1234"); //i != kol
    ichar[4] = '\n';
    int c4 = scans(kol, ichar, &i);

    kol = 4;
    ichar[0] = '\n'; //no data
    int c5 = scans(kol, ichar, &i);

    kol = 4;
    strcpy(ichar, "2eE9"); // wrong input
    ichar[4] = '\n';
    int c6 = scans(kol, ichar, &i);

    strcpy(ichar, "1"); // Number less than kol
    ichar[1] = '\n';
    int c7 = scans(4, hchar, &i);

    strcpy(ichar, "1112"); // Number is repeteated
    ichar[1] = '\n';
    int c8 = scans(4, hchar, &i);

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 1;
    const int exp4 = 0;
    const int exp5 = 0;
    const int exp6 = 0;
    const int exp7 = 0;
    const int exp8 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);
    ASSERT_EQUAL(exp7, c7);
    ASSERT_EQUAL(exp8, c8);
}
