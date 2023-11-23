#include <stdio.h>
#include <string.h>

struct nama
{
    char nama[100];
    int nomor;
};

int main()
{
    int test, baris;
    struct nama orang[100];
    struct nama sementara;
    scanf("%d", &test);
    for(int i = 0; i<test; i++)
    {
        scanf("%d", &baris);
        for(int j = 0; j<baris; j++)
        {
            scanf(" %[^#]#%d", &orang[j].nama, &orang[j].nomor);
        }
        
        for(int i = 0; i<baris-1; i++)
        {
            for(int j = 0; j<baris-1; j++)
            {
                if(orang[j].nomor < orang[j+1].nomor)
                {
                    sementara = orang[j];
                    orang[j] = orang[j+1];
                    orang[j+1] = sementara;
                }
                else if(orang[j].nomor == orang[j+1].nomor)
                {
                    if(strcmp(orang[j].nama, orang[j+1].nama) > 0)
                    {
                        sementara = orang[j];
                        orang[j] = orang[j+1];
                        orang[j+1] = sementara;
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    continue;
                }
            
            }
        }


        printf("Case #%d:\n", i+1);
        for(int j = 0; j<baris; j++)
        {
            printf("%s - %d\n", orang[j].nama, orang[j].nomor);
        }
    }
    return 0;
}