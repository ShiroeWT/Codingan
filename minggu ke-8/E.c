#include <stdio.h>
#include <string.h>

struct tugas
{
    char nama[11];
    int tenggat;
};

int main()
{
    int counter;
    struct tugas sementara;
    scanf("%d", &counter);
    struct tugas lili[counter];
    for(int i = 0; i < counter; i++)
    {
        scanf("%s %d", lili[i].nama, &lili[i].tenggat);
    }
    
    for(int i = 0; i<counter-1; i++)
    {
        for(int j = 0; j<counter-1; j++)
        {
            if(lili[j].tenggat > lili[j+1].tenggat)
            {
                sementara = lili[j];
                lili[j] = lili[j+1];
                lili[j+1] = sementara;
            }
            else if(lili[j].tenggat == lili[j+1].tenggat)
            {
                if(strcmp(lili[j].nama, lili[j+1].nama) > 0)
                {
                    sementara = lili[j];
                    lili[j] = lili[j+1];
                    lili[j+1] = sementara;
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
    for(int i = 0; i < counter; i++)
    {
        printf("%s\n", lili[i].nama);
    }
    return 0;
}
