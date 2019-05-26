#include <math.h>
#include <stdio.h>
#include <stdlib.h>
//#include "core.h"

int random_n(int kol)
{
    int n, ind, numb = 0, m;
    for (int i = 1; i <= kol; i++) {
        do {
            ind = 1;
            n = rand() % 10;
            for (int b = 1; b < i; b++) {
                m = numb / (pow(10, b - 1));
                if (n == (m % 10))
                    ind = 0;
            }
        } while (ind == 0);
        numb = numb + (n * pow(10, i - 1));
    }
    return numb;
}

int how_much_bulls(int number, int gen, int kol)
{
    int num = number, m = gen, bulls = 0;
    for (int i = kol; i >= 1; i--) {
        if ((num % 10) == (m % 10)) {
            bulls++;
        }
        num = num / 10;
        m = m / 10;
    }
    return bulls;
}

int how_much_cows(int number, int gen, int kol)
{
    int num = number, m = gen, cows = 0, mm;
    for (int i = 1; i <= kol; i++) {
        if ((num % 10) != (m % 10)) {
            for (int k = 0; k < kol; k++) {
                mm = gen / (pow(10, k));
                if ((num % 10) == (mm % 10)) {
                    cows++;
                    break;
                }
            }
        }
        num = num / 10;
        m = m / 10;
    }
    return cows;
}

void print_txt(FILE *p) {
    int c;
    if (p == NULL) {
        printf("Cannot open file\n");
    }else{
        while((c = fgetc(p)) != EOF){
            putc(c, stdout);
        }
    }
}

/*int main()
{
int i,kol,num,cows=0,bulls=0;
scanf("%d",&kol);
kol=kol+3;
num=random_n(kol);
do {
scanf("%d",&i);
bulls=how_much_bulls(i,num,kol);
cows=how_much_cows(i,num,kol);
printf("%d %d %d",num,bulls,cows);
} while (bulls!=kol);
}*/
