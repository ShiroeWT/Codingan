#include <stdio.h>

struct data 
{
    char nama[101];
    char nim[10];
    int umur;
    char kodepos[7];
    char tempatLahir[101];
    char tanggalLahir[101];
    char almamaterSMA[101];
    int jumlahsaudara;
    int tinggiBadan;
    char nomorRekening[101];
};

int main()
{
    int baris;
    scanf("%d", &baris);
    struct data mahasiswa[baris];
    for(int i = 0; i<baris; i++)
    {
        scanf("%s", mahasiswa[i].nama); getchar();
        scanf("%s", mahasiswa[i].nim); getchar();
        scanf("%d", &mahasiswa[i].umur); getchar();
        scanf("%s", mahasiswa[i].kodepos); getchar();
        scanf("%s", mahasiswa[i].tempatLahir); getchar();
        scanf("%s", mahasiswa[i].tanggalLahir); getchar();
        scanf("%[^\n]", mahasiswa[i].almamaterSMA); getchar();
        scanf("%d", &mahasiswa[i].jumlahsaudara); getchar();
        scanf("%d", &mahasiswa[i].tinggiBadan); getchar();
        scanf("%s", &mahasiswa[i].nomorRekening); getchar();
    }

    for(int j = 0; j<baris; j++)
    {
        printf("Mahasiswa ke-%d:\n", j+1);
        printf("Nama: %s\n", mahasiswa[j].nama);
        printf("NIM: %s\n", mahasiswa[j].nim);
        printf("Umur: %d\n", mahasiswa[j].umur);
        printf("Kode Pos: %s\n", mahasiswa[j].kodepos);
        printf("Tempat Lahir: %s\n", mahasiswa[j].tempatLahir);
        printf("Tanggal Lahir: %s\n", mahasiswa[j].tanggalLahir);
        printf("Almamater SMA: %s\n", mahasiswa[j].almamaterSMA);
        printf("Jumlah Saudara Kandung: %d\n", mahasiswa[j].jumlahsaudara);
        printf("Tinggi Badan: %d\n", mahasiswa[j].tinggiBadan);
        printf("NOMOR REKENING: %s\n", mahasiswa[j].nomorRekening);
    }

    return 0;
}