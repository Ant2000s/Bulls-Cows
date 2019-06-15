#include "../src/core.h"
#include "../thirdparty/ctest.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int h = 0;
char *hchar = NULL;
char ichar[11];

CTEST(inputdata, choose_point)
{
    hchar = malloc(10);
    strcpy(hchar, "1"); // Right input
    int c1 = choose_point(4, hchar, &h);

    /*strcpy(hchar, "12"); //Input beyond limits 
    int c2 = choose_point(4, hchar, &h);

    strcpy(hchar, ""); // no data
    int c3 = choose_point(4, hchar, &h);

    strcpy(hchar, "E2E9"); // mixed input
    int c4 = choose_point(4, hchar, &h);

    strcpy(hchar, "h"); // Input not num
    int c5 = choose_point(4, hchar, &h);*/

    const int exp1 = 1;
    /*const int exp2 = 0;
    const int exp3 = 0;
    const int exp4 = 0;
    const int exp5 = 0;*/

    ASSERT_EQUAL(exp1, c1);
    /*ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);*/
}
