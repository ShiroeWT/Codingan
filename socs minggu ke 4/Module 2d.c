#include <stdio.h>

int main ()
{
    int n;
    scanf("%d", &n);
    char nama[n][100], nim[n][100], umur[n][100];
    for(int i=0; i<n; i++)
    {
        printf("Nama : ");
        scanf("%s", &nama[i]);
        printf("NIM : ");
        scanf("%s", &nim[i]);
        printf("Umur : ");
        scanf("%s", &umur[i]);
    }
    for(int i=0; i<n; i++)
    {
        printf("Nama : %s\n", nama[i]);
        printf("NIM : %s\n", nim[i]);
        printf("Umur : %s\n", umur[i]);
    }
    return 0;
}