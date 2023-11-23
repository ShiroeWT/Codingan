#include <stdio.h>
#include <string.h>

struct data
{
    char namaKota[1001];
    float suhu;
    char derajat[2];
};


int main()
{
    struct data kota[1001];
    struct data temp;
    char huruf[2];
    huruf[0] = 'F';
    int i = 0;
    FILE *file = fopen("./testdata.in", "r");

    if(file == NULL)
    {
        printf("File tidak ada\n");
        return 1;
    }

    while(fscanf(file, " %[^#]#%f#%s", kota[i].namaKota, &kota[i].suhu, kota[i].derajat) != EOF)
    {
        i++;
    }

    fclose(file);


    for(int j = 0; j<i-1; j++)
    {
        for(int n = 0; n<i-1; n++)
        {
            float suhu1 = kota[n].derajat[0] == huruf[0] ? (kota[n].suhu - 32) * 5.0/9 : kota[n].suhu;
            float suhu2 = kota[n+1].derajat[0] == huruf[0] ? (kota[n+1].suhu - 32) * 5.0/9 : kota[n+1].suhu;

            if(suhu1 > suhu2)
            {
                temp = kota[n];
                kota[n] = kota[n+1];
                kota[n+1] = temp;

            }
            else if(suhu1 == suhu2)
            {
                if(strcmp(kota[n].namaKota, kota[n+1].namaKota) > 0)
                {
                    temp = kota[n];
                    kota[n] = kota[n+1];
                    kota[n+1] = temp;
                }
            }
        }
    }

    for(int k = 0; k<i; k++)
    {
        printf("%s is %.2f%s\n", kota[k].namaKota, kota[k].suhu, kota[k].derajat);
    }

    return 0;
}