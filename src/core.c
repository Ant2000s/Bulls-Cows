#include <stdio.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
int random_n(int kol)
{
    srand(time(NULL));
    int n,ind,numb = 0,m;
    for (int i=1;i<=kol;i++) {
        ind=1;
        do {
            n=rand() % 10;
            for (int b=1; b<i;b++) {
                m=numb/(pow(10,b-1));
//              printf("--%d--%d--\n",m,numb);
                if (n == (m%10))
                    ind=0;
            }
        } while(ind==0);
        numb=numb + (n*pow(10,i-1));
        printf("%d %d\n",numb,n);
    }
    return numb;
}

int main()
{
int kol;
scanf("%d",&kol);
printf("\n %d",random_n(kol+3));
}
