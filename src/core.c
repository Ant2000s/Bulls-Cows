#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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

void print_menu() {
    printf("\n\tBulls and Cows\n\n");
    printf("Touch \"1\" to choose the difficultness\n");
    printf("Touch \"2\" to show rules\n");
    printf("Touch \"3\" to exit\n");
    printf("Select: ");
}

int choose_point() { //рабочий вариант, итог
    int kol, i;
    char *c = NULL;
    size_t len = 0;
    for(;;) {
        getline(&c, &len, stdin);
        for(i = 0; c[i] != '\n'; i++);
        kol = atoi(c);
        if ((kol != 0) && (i == 1) && ((kol == 1) ||(kol == 2) || (kol == 3))) {
        return kol;
        }
        printf("Incorrect input, try again\n");
    }
}

int scans(int kol) {
    int num, i;
    char *c = NULL;
    size_t len = 0;
    printf("Input your picked number: "); //не оптимальный, но полностью рабочий
    for (;;) {
        //scanf("%d\n", &num);
        //printf("num: %d\n", num);
        getline(&c, &len, stdin);
        for (i = 0; c[i] != '\n'; i++);
        num = atoi(c);
        //printf("i = %d\n", i);
        //printf("num = %d\n", num);
        if ((i == kol) /*(num != 0)*/ && (((num/pow(10, kol - 1) < 10) && (num/pow(10, kol - 1) >= 1)))) {
            return num;
        }
        printf("Incorrect value, try again\n");
        //while(getchar() != '\n');
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
