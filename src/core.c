#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
int random_n(int kol) {
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

int how_much_bulls(int number, int gen, int kol) {
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

int how_much_cows(int number, int gen, int kol) {
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
  } else {
    while ((c = fgetc(p)) != EOF) {
      putc(c, stdout);
    }
  }
}

void print_menu() {
  printf("%100s", "Bulls and Cows\n\n");
  printf("%110s", "Touch \"1\" to start playing(one player)\n");
  printf("%111s", "Touch \"2\" to start playing(two players)\n");
  printf("%104s", "Touch \"3\" to show rules\n");
  printf("%100s", "Touch \"4\" to exit\n");
  printf("%95s", "Select: ");
}

int choose_point(int L, char *c, int *kole) { //рабочий вариант, итог
  int kol, i;
  for (i = 0; c[i] != '\n'; i++)
    ;
  kol = atoi(c);
  *kole = kol;
  if ((kol != 0) && (i == 1) && (L == 3) &&
      ((kol == 1) || (kol == 2) || (kol == 3))) {
    return 1;
  }
  if ((kol != 0) && (i == 1) && (L == 4) &&
      ((kol == 1) || (kol == 2) || (kol == 3) || (kol == 4))) {
    return 1;
  }

  return 0;
}

int scans(int kol, char *c, int *nume) {
  int i, num, zero = 0, reit = 0;
  for (i = 0; c[i] != '\n'; i++)
    ;
  if (c[0] == '0') {
    zero = 1;
  }
  for (int l = 0; l < i; l++) {
    for (int a = i; a > l; a--) {
      if (c[l] == c[a])
        reit = 1;
    }
  }
  num = atoi(c);
  *nume = num;
  if (zero == 0) {
    if ((i == kol) && (reit == 0) &&
        (((num / pow(10, kol - 1) < 10) && (num / pow(10, kol - 1) >= 1)))) {
      return 1;
    }
  }
  if (zero == 1) {
    if ((i == kol) && (reit == 0) &&
        (((num / pow(10, kol - 2) < 10) && (num / pow(10, kol - 2) >= 1)))) {
      return 1;
    }
  }
  reit = 0;
  zero = 0;
  return 0;
}
