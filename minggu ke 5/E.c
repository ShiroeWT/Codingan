#include <stdio.h>

int fibonacci(int urutan, int angka1, int angka2)
{
    if(urutan == 0)
    {

        return angka1;
    }
    else if(urutan == 1)
    {

        return angka2;
    }
    else
    {
        int fibo = fibonacci(urutan - 1, angka1, angka2) + fibonacci(urutan - 2, angka1, angka2);
        return fibo;
    }
}
int main ()
{
    int angka1, angka2, urutan;
    scanf("%d %d",&angka1, &angka2);
    scanf("%d", &urutan);
    int hasil = fibonacci(urutan, angka1, angka2);
    printf("%d\n", hasil);

    return 0;
}