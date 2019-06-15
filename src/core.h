#ifndef CORE_H
#define CORE_H
#include <stdio.h>
//#include <math.h>

int random_n(int kol);
int how_much_bulls(int number, int gen, int kol);
int how_much_cows(int number, int gen, int kol);
void print_txt(FILE *p);
int scans(int kol, char *c, int *nume);
int choose_point(int L, char *c, int *kole);
void print_menu();

#endif
