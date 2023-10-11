#include <stdio.h>
int main()
{
    int N, M, Q, X, Y, A;
    scanf("%d %d %d", &N, &M, &Q);
    int arr[N][M];
            
    for (int i = 0; i<N; i++)   // bikin array nya jadi 0 semua dulu, kalo ngga gini  bisa error (sumber pembimbing LAB)
    {
        for (int j = 0; j<M; j++)
        {
            arr [i][j] = 0;
        }
    }
    
    for (int i = 0; i<Q; i++)
    {
        scanf("%d %d %d", &X, &Y, &A);
        arr[X][Y] = A;
    }
    for (int i = 0; i<N; i++)
    {
        for (int j = 0; j<M; j++)
        {
            printf("%d", arr[i][j]);
            if(j<M-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}