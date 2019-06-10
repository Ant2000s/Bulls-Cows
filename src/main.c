#include "core.h"
#include <stdio.h>

int main()
{
    int i, h, kol, cows = 0, bulls = 0, num;
    FILE *p;
    p = fopen("../src/rules.txt", "rt");
    while (1) {
	print_menu();
        h = choose_point(4);
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
            kol = choose_point(3);
            kol = kol + 3;
            num = random_n(kol);
            do {
                printf("Input your number: ");
                i = scans(kol);
                bulls = how_much_bulls(i, num, kol);
                cows = how_much_cows(i, num, kol);
                printf("bulls: %d\n cows: %d\n", bulls, cows);
            } while (bulls != kol);
            printf("Congratulations! You won!");
        }
        if (h==4) {
            printf("Choose the difficultness:\n");
            printf("\t1. Easy\n");
            printf("\t2. Medium\n");
            printf("\t3. Difficult\n");
            printf("Input value: ");
            kol = choose_point(3);
            kol = kol + 3;
            int H = 1;
            num = random_n(kol);
            do {
                H++;
                printf("   Player %d \ninput your number: ",(H%2)+1);
                i = scans(kol);
                bulls = how_much_bulls(i, num, kol);
                cows = how_much_cows(i, num, kol);
                printf("bulls: %d\n cows: %d\n", bulls, cows);
            } while (bulls != kol);
            printf("Congratulations! Player %d won!",(H%2)+1);
        }
        if (h == 3) {
            return 0;
        }
    //print_menu();
    }
}
