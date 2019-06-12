#include "core.h"
#include <stdio.h>
#include <stdlib.h>
int main() {
  int i, h = 0, kol, d, cows = 0, bulls = 0, num;
  FILE *p;
  size_t len;
  char *ichar = NULL;
  char *hchar = NULL;
  p = fopen("../src/rules.txt", "rt");
  while (1) {
    print_menu();
    for (;;) {
      getline(&hchar, &len, stdin);
      d = choose_point(4, hchar, &h);
      if (d == 1) {
        break;
      }
      printf("Incorrect value, try again: ");
    }
    if (h == 3) {
      system("clear");
      p = fopen("../src/rules.txt", "rt");
      print_txt(p);
      fclose(p);
    }
    if (h == 1) {
      system("clear");
      printf("%102s","Choose the difficultness:\n");
      printf("%93s","1. Easy\n");
      printf("%94s","2. Medium\n");
      printf("%96s","3. Difficult\n");
      printf("%96s","Input value: ");
      for (;;) {
        getline(&hchar, &len, stdin);
        d = choose_point(3, hchar, &kol);
        if (d == 1) {
          break;
        }
        printf("%103s","Incorrect value, try again: ");
        }
        kol = kol + 3;
        num = random_n(kol);
        do {
//          system("clear");
          printf("%98s","Input your number: ");
          for (;;) {
            getline(&ichar, &len, stdin);
            d = scans(kol, ichar, &i);
            if (d == 1) {
              break;
            }
            printf("%103s","Incorrect value, try again: ");
          }
          bulls = how_much_bulls(i, num, kol);
          cows = how_much_cows(i, num, kol);
          printf("%83s"," ");
          printf("bulls: %d cows: %d\n", bulls, cows);
        } while (bulls != kol);
        system("clear");
        printf("%105s","Congratulations! You won!\n");
      }
      if (h == 2) {
        printf("%100s","Choose the difficultness:\n");
      printf("%93s","1. Easy\n");
      printf("%94s","2. Medium\n");
      printf("%96s","3. Difficult\n");
      printf("%96s","Input value: ");
        for (;;) {
          getline(&hchar, &len, stdin);
          d = choose_point(3, hchar, &kol);
          if (d == 1) {
            break;
          }
          printf("%103s","Incorrect value, try again: ");
        }
        kol = kol + 3;
        int H = 1;
        num = random_n(kol);
        do {
          H++;
          printf("%86s"," ");
          printf("Player %d \n", (H % 2) + 1);
          printf("%98s","input your number: ");
          for (;;) {
            getline(&ichar, &len, stdin);
            d = scans(kol, ichar, &i);
            if (d == 1) {
              break;
            }
            printf("%103s","Incorrect value, try again: ");
          }
          bulls = how_much_bulls(i, num, kol);
          cows = how_much_cows(i, num, kol);
          printf("%83s"," ");
          printf("bulls: %d cows: %d\n", bulls, cows);
        } while (bulls != kol);
        printf("%74s"," ");
        printf("Congratulations! Player %d won!", (H % 2) + 1);
      }
      if (h == 4) {
        return 0;
      }
      // print_menu();
    }
  }
