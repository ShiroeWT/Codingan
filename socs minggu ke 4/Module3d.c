#include <stdio.h>

int main()
{
    int n, m, k;
    scanf("%d", &m); // input ada brp siswa
    char tabel[3][m][1000]; // [0 nim, 1 nama, 2 umur][jumlah siswa][panjang string]
    for (int i = 0; i < m; i++)
    {
        printf("Nama : ");
        scanf("%s", &tabel[0][i]);
        printf("NIM : ");
        scanf("%s", &tabel[1][i]);
        printf("Umur : ");
        scanf("%s", &tabel[2][i]);
    }
    for (int i = 0; i < m; i++)
    {
        printf("nama : %s\n", tabel[0][i]);
        printf("nim : %s\n", tabel[1][i]);
        printf("umur : %s\n", tabel[2][i]);
    }
    return 0;
}