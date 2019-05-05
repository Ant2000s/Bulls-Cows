#include "core.h"
#include <stdio.h>

int main()
{
    int i, kol, cows = 0, bulls = 0, num;
    scanf("%d", &kol);
    kol = kol + 3;
    num = random_n(kol);
    do {
        scanf("%d", &i);
        bulls = how_much_bulls(i, num, kol);
        cows = how_much_cows(i, num, kol);
        printf("%d %d %d", num, bulls, cows);
    } while (bulls != kol);
}
