#include <stdio.h>

int main()
{
    int T, N, A[100001], B[100001], hasil[100001];
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        scanf("%d", &N);
        for(int j = 0; j < N; j++)
        {
            scanf("%d", &A[j]);
        }
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &B[j]);
            hasil[j] = A[j] - B[j];
        }
        printf("Case #%d:", i+1);
        for(int j = 0; j < N; j++)
        {
            printf(" %d", hasil[j]);
        }
        printf("\n");

    }
    return 0;
}   