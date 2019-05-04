#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
int random_n(int kol)
{
    srand(time(NULL));
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

int main()
{
}
