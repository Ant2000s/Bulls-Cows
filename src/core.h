#ifndef CORE_H
#define CORE_H
#include <stdio.h>
//#include <math.h>

int random_n(int kol);
int how_much_bulls(int number, int gen, int kol);
int how_much_cows(int number, int gen, int kol);
void print_txt(FILE *p);
int scans(int kol);
int choose_point();
void print_menu();

#endif
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
