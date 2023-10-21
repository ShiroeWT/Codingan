#include <stdio.h>

int count = 0;

int rekursif(int nilai)
{

    if (nilai == 0) 
    {
        return 1;
    }
    else if (nilai == 1)
    {
        return 2;
    }
    else if (nilai % 5 == 0)
    {
        if(nilai % 3 == 0)
        {
            count++;
        }
        return nilai * 2;
    }
    else
    {
        if(nilai % 3 == 0)
        {
            count++;
        }
        return rekursif(nilai - 1) + nilai + rekursif(nilai - 2) + nilai - 2;
    }
}


int main ()
{
    int nilai, counter;
    scanf("%d", &counter);
    for(int i = 0; i < counter; i++ )
    {
        scanf("%d", &nilai);
        int hasil = rekursif(nilai);
        printf("Case #%d: ", i+1);
        printf("%d %d\n", hasil, count);
        count = 0;
    }

    return 0;
}