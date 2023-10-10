#include <stdio.h>

int main ()
{
    int T, X, a, arr[101][101];
    scanf("%d", &T);

    for (int i = 0; i<T; i++)
    {
        scanf("%d", &X);
        for(int j = 0; j<X; j++)
        {
            for(int k = 0; k<X; k++)
            {
                scanf("%d", &arr[j][k]);
            }
        }
        printf("Case #%d:", i+1);
        for (int j = 0; j < X; j++)
        {
            int a = 0;
            for (int k = 0; k < X; k++)
            {
                a = a + arr[k][j];
            } 
            printf(" %d", a);
        }
        printf("\n");
    }
    return 0;
}