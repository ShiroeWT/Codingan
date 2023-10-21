#include <stdio.h>

int fibonacci(int urutan, char huruf1, char huruf2)
{
    if(urutan == 0)
    {
        printf("%c", huruf1);
        return huruf1;
    }
    else if(urutan == 1)
    {
        printf("%c", huruf2);
        return huruf2;
    }
    else
    {
        int fibo = fibonacci(urutan-1, huruf1, huruf2) + fibonacci(urutan-2, huruf1, huruf2);
        return fibo;
    }
}
int main ()
{
    int loop, urutan;
    char huruf1, huruf2;
    scanf("%d", &loop);
    for(int i = 0; i<loop; i++)
    {
        scanf("%d %c %c", &urutan, &huruf1, &huruf2);
        printf("Case #%d: ", i+1);
        int hasil = fibonacci(urutan, huruf1, huruf2);
        printf("\n");
    }
}