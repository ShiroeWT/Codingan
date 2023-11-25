#include <stdio.h>
#include <string.h>

struct person
{
    char nama[101];
    int umur;
    char jurusan[101];
};

int main ()
{
    struct person orang[104];
    strcpy(orang[0].nama, "Caca");
    orang[0].umur = 19;
    strcpy(orang[0].jurusan, "Informatika");
    strcpy(orang[1].nama, "Budi");
    orang[1].umur = 20;
    strcpy(orang[1].jurusan, "Informatika");
    strcpy(orang[2].nama, "Aldi");
    orang[2].umur = 21;
    strcpy(orang[2].jurusan, "Informatika");
    int pilihan;
    int bykData = 3;
    do
    {
        printf("====================================\n");
        printf("                MENU                \n");
        printf("====================================\n");
        printf("1. Input data\n");
        printf("2. Tampilkan data\n");
        printf("3. Sortir Berdasarkan Umur\n");
        printf("4. Sortir Berdasarkan Huruf Pertama Nama\n");
        printf("5. Exit\n");
        printf(">> ");
        scanf("%d", &pilihan); getchar();

        if(pilihan == 1)
        {
            int ngulang;
            printf("====================================\n");
            printf("Masukkan jumlah data yang ingin diinput: ");
            scanf("%d", &ngulang); getchar();
            for(int j = 0; j<ngulang; j++)
            {
                printf("Data ke-%d\n", j+1);
                printf("Masukkan Nama: ");
                scanf("%[^\n]", &orang[bykData].nama); getchar();
                printf("Masukkan Umur(angka): ");
                scanf("%d", &orang[bykData].umur); getchar();
                printf("Masukkan Jurusan: ");
                scanf("%[^\n]", &orang[bykData].jurusan); getchar();
                bykData++;
            }
            printf("\n");
            printf("tekan enter untuk kembali ke menu\n");
            getchar();
        }

        else if(pilihan == 2)
        {
            printf("====================================\n");
            for(int j = 0; j < bykData; j++)
            {
                printf("%d. %s %d %s\n", j+1, orang[j].nama, orang[j].umur, orang[j].jurusan);
            }
            printf("\n");
            printf("tekan enter untuk kembali ke menu\n");
            getchar();
        }   

        else if(pilihan == 3)
        {
            for(int n = 0; n<bykData-1; n++)
            {
                for(int m = 0; m<bykData-1; m++)
                {
                    if(orang[m].umur > orang[m+1].umur)
                    {
                        struct person temp = orang[m];
                        orang[m] = orang[m+1];
                        orang[m+1] = temp;
                    }
                }
            }
            printf("====================================\n");
            printf("Data telah diurutkan berdasarkan umur\n");
            printf("\n");
            printf("tekan enter untuk kembali ke menu\n");
            getchar();
        }

        else if(pilihan == 4)
        {
            for(int n = 0; n<bykData-1; n++)
            {
                for(int m = 0; m<bykData-1; m++)
                {
                    if(orang[m].nama[0] > orang[m+1].nama[0])
                    {
                        struct person temp = orang[m];
                        orang[m] = orang[m+1];
                        orang[m+1] = temp;
                    }
                }
            }
            printf("====================================\n");
            printf("Data telah diurutkan berdasarkan huruf depan nama\n");
            printf("\n");
            printf("tekan enter untuk kembali ke menu\n");
            getchar();

        }
        else if(pilihan == 5)
        {
            printf("====================================\n");
            printf("Terima kasih telah menggunakan program ini\n");
        }   

        else
        {
            printf("\n");
            printf("Pilihan tidak tersedia\n");
        }

        printf("\n");

    } while(pilihan != 5);


    return 0;
}