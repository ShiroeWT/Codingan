#include <stdio.h>

void daun(int A[], int index, int ukuran, int jumlah)
{
    if (index >= ukuran)
    {
        return;
    }
    int IndexAnakKiri = 2 * index + 1;
    int IndexAnakKanan = 2 * index + 2;

    int jumlahSekarang = jumlah + A[index];

    if(IndexAnakKiri >= ukuran && IndexAnakKanan >= ukuran)
    {
        printf("%d\n", jumlahSekarang);
        return;
    }

    daun(A, IndexAnakKiri, ukuran, jumlahSekarang);
    daun(A, IndexAnakKanan, ukuran, jumlahSekarang);
}


int main ()
{
    int loop, ukuran;
    scanf("%d", &loop);
    for (int i = 0; i < loop; i++)
    {
        
        scanf("%d", &ukuran);
        int A[ukuran];
        for (int j = 0; j < ukuran; j++)
        {
            scanf("%d", &A[j]);
        }
        printf("Case #%d:\n", i+1);
        daun(A, 0, ukuran, 0);
    }
    return 0;
}