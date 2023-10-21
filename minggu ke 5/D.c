#include <stdio.h>

int count = 0;

int a(int angka)
{
    count++;
    if(angka == 0)
    {

        return 0;
    }
    else if(angka == 1)
    {

        return 1;
    }
    else
    {
        int fibo = a(angka-1) + a(angka-2);
        return fibo;
    }
}

int main ()
{
    int loop, angka;
    scanf("%d", &loop);
    for(int i = 0; i<loop; i++)
    {
        scanf("%d", &angka);
        printf("Case #%d:", i+1);
        int hasil = a(angka);
        printf(" %d\n", count);
        count = 0;
    }
}