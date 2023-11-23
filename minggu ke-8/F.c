#include <stdio.h>

int main()
{
    int kereta[501], sementara;
    int skor = 0, gerbong, waktu, kasus;
    scanf("%d", &kasus);
    for(int i = 0; i<kasus; i++)
    {
        scanf("%d %d", &gerbong, &waktu);
        for(int j = 0; j<gerbong; j++)
        {
            scanf("%d", &kereta[j]);
        }
        for(int j = 0; j<gerbong; j++)
        {
            for(int k = 0; k<gerbong-1; k++)
            {
                if(kereta[k] >= kereta[k+1])
                {
                    sementara = kereta[k];
                    kereta[k] = kereta[k+1];
                    kereta[k+1] = sementara;
                    skor++;
                }
                else
                {
                    continue;
                }
            }
        }
        printf("Case #%d: %d\n", i+1, skor*waktu);
        skor = 0;
    }
    return 0;
}