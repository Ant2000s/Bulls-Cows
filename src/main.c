#include "core.h"
#include <stdio.h>

int main()
{
    int i, h, kol, cows = 0, bulls = 0, num;
    FILE *p;
    //p = fopen("../src/rules.txt", "rt");
    while (1) {
	print_menu();
        h = choose_point();
        if (h == 2) {
            p = fopen("../src/rules.txt", "rt");
            print_txt(p);
            fclose(p);
        }
        if (h == 1) {
	    printf("Choose the difficultness:\n");
            printf("\t1. Easy\n");
            printf("\t2. Medium\n");
            printf("\t3. Difficult\n");
            printf("Input value: ");
            kol = choose_point();
            kol = kol + 3;
            num = random_n(kol);
            do {
                i = scans(kol);
                bulls = how_much_bulls(i, num, kol);
                cows = how_much_cows(i, num, kol);
                printf("%d %d %d\n", num, bulls, cows);
            } while (bulls != kol);
        }
        if (h == 3) {
            return 0;
        }
    //print_menu();
    }
}
