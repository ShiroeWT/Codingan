#include <stdio.h>

struct keluarga
{
    char namaAyah[31];
    char namaIbu[31];
    int jumlahAnak;
};

struct mahasiswa
{
    char kodeMahasiswa[31];
    char namaMahasiswa[31];
    char kelaminMahasiswa[31];
    struct keluarga keluargaMahasiswa;
};

struct dosen
{
    char kodeDosen[31];
    char namaDosen[31];
    char kelaminDosen[31];
    int jumlahMahasiswa;
    struct mahasiswa mahasiswa[101];
};




int main()
{
    int jumlahDosen, pilihanDosen;
    scanf("%d", &jumlahDosen);
    struct dosen dosen[jumlahDosen];
    for(int i = 0; i<jumlahDosen; i++)
    {
        scanf("%s", &dosen[i].kodeDosen);
        scanf("%s", &dosen[i].namaDosen);
        scanf("%s", &dosen[i].kelaminDosen);
        scanf("%d", &dosen[i].jumlahMahasiswa);
        for(int j = 0; j<dosen[i].jumlahMahasiswa; j++)
        {
            scanf("%s", &dosen[i].mahasiswa[j].kodeMahasiswa);
            scanf("%s", &dosen[i].mahasiswa[j].namaMahasiswa);
            scanf("%s", &dosen[i].mahasiswa[j].kelaminMahasiswa);
            scanf("%s", &dosen[i].mahasiswa[j].keluargaMahasiswa.namaAyah);
            scanf("%s", &dosen[i].mahasiswa[j].keluargaMahasiswa.namaIbu);
            scanf("%d", &dosen[i].mahasiswa[j].keluargaMahasiswa.jumlahAnak);
        }
    }

    scanf("%d", &pilihanDosen);
    printf("Kode Dosen: %s\n", dosen[pilihanDosen-1].kodeDosen);
    printf("Nama Dosen: %s\n", dosen[pilihanDosen-1].namaDosen);
    printf("Gender Dosen: %s\n", dosen[pilihanDosen-1].kelaminDosen);
    printf("Jumlah Mahasiswa: %d\n", dosen[pilihanDosen-1].jumlahMahasiswa);
    for(int i = 0; i<dosen[pilihanDosen-1].jumlahMahasiswa; i++)
    {
        printf("Kode Mahasiswa: %s\n", dosen[pilihanDosen-1].mahasiswa[i].kodeMahasiswa);
        printf("Nama Mahasiswa: %s\n", dosen[pilihanDosen-1].mahasiswa[i].namaMahasiswa);
        printf("Gender Mahasiswa: %s\n", dosen[pilihanDosen-1].mahasiswa[i].kelaminMahasiswa);
        printf("Nama Ayah: %s\n", dosen[pilihanDosen-1].mahasiswa[i].keluargaMahasiswa.namaAyah);
        printf("Nama Ibu: %s\n", dosen[pilihanDosen-1].mahasiswa[i].keluargaMahasiswa.namaIbu);
        printf("Jumlah Saudara Kandung: %d\n", dosen[pilihanDosen-1].mahasiswa[i].keluargaMahasiswa.jumlahAnak);
    }

    return 0;
}