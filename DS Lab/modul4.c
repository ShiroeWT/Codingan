#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXN 1007
int counter = 1;

struct node{
    char id[50];
    char namaObat[55];
    char namaManufaktur[55];
    char regNum[15];
    int batch;
    struct node *next;
};

struct node *head[MAXN];

int sumAscii(char obat[]){
    int c = 0;
    for(int i = 0; obat[i] != '\0'; i++){
        c += obat[i];
    }
    return c;
}

void insertMed(char id[], char namaObat[], char namaManufaktur[], char regNum[], int batch){
    int key = sumAscii(id) % MAXN;
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(head[key] == NULL){
        head[key] = temp;
        strcpy(head[key]->id, id);
        strcpy(head[key]->namaObat, namaObat);
        strcpy(head[key]->namaManufaktur, namaManufaktur);
        strcpy(head[key]->regNum, regNum);
        head[key]->batch = batch;
        head[key]->next = NULL;
        return;
    }
    else{
        struct node *temp2 = (struct node*)malloc(sizeof(struct node));
        temp2 = head[key];
        while(temp2->next != NULL){
            temp2 = temp2->next;
        }
        strcpy(temp->id, id);
        strcpy(temp->namaObat, namaObat);
        strcpy(temp->namaManufaktur, namaManufaktur);
        strcpy(temp->regNum, regNum);
        temp->batch = batch;
        temp->next = NULL;
        temp2->next = temp;
        return;
    }
}

int cekNamaObat(char namaObat[]){
    for(int i = 0; i < MAXN; i++){
        struct node *temp = head[i];
        while(temp != NULL){
            if(strcmp(temp->namaObat, namaObat) == 0){
                return 0;
            }
            temp = temp->next;
        }
    }
    return 1;
}

void tampilkan(){
    int kosong = 0;
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    for(int i = 0; i < MAXN; i++){
        temp = head[i];
        if(head[i] != NULL){
            kosong = 1;
            break;
        }
    }
    if(kosong == 0){
        printf("Data Kosong\n");
        return;
    }
    printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| Medicine ID            | Medicine Name            | Manufacturer Name             | Registration Number           | Batch Number          |\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
    for(int i = 0; i < MAXN; i++){
        struct node *temp = head[i];
        while(temp != NULL){
            printf("| %-22s | %-24s | %-29s | %-29s | %-21d |\n", temp->id, temp->namaObat, temp->namaManufaktur, temp->regNum, temp->batch);
            printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
            temp = temp->next;
        }
    }
}

void removeMed(char id[]){
    int key = sumAscii(id) % MAXN;
    char pilihan;
    struct node *temp = head[key];
    struct node *prev = NULL;
    while(temp != NULL){
        if(strcmp(temp->id, id) == 0){
            printf("Medicine ID : %s\n", temp->id);
            printf("Medicine Name : %s\n", temp->namaObat);
            printf("Manufacturer Name : %s\n", temp->namaManufaktur);
            printf("Registration Number : %s\n", temp->regNum);
            printf("Batch/Lot : %d\n", temp->batch);
            do{
                printf("Are you sure ? [y|n]? ");
                scanf(" %c", &pilihan);
                if(strcmp(&pilihan, "n") == 0){
                    return;
                }
            } while(pilihan != 'y' && pilihan != 'n');
            if(prev == NULL){
                head[key] = temp->next;
            }
            else{
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Data tidak ditemukan\n");
    return;
}

int main(){
    for(int i = 0; i < MAXN; i++){
        head[i] = NULL;
    }
    int pilihan;
    do{
        printf("1. View Medicine\n");
        printf("2. Insert Medicine\n");
        printf("3. Remove Medicine\n");
        printf("4. Exit\n");
        printf(">> ");
        scanf("%d", &pilihan);
        if(pilihan == 1){
            tampilkan();
            printf("Press Any Key to Continue\n");
            getchar();
            getchar();
            system("cls");
        }
        else if(pilihan == 2){
            char namaObat[100];
            do{
                printf("Input Medicine Name [5-50][unique]: ");
                scanf(" %[^\n]", namaObat);
                if(strlen(namaObat) < 5 || strlen(namaObat) > 50){
                    printf("Invalid input\n");
                }
                if(cekNamaObat(namaObat) == 0){
                    printf("Nama Obat sudah ada\n");
                }
            } while(strlen(namaObat) < 5 || strlen(namaObat) > 50 || cekNamaObat(namaObat) == 0);
            char namaManufaktur[100];
            do{
                printf("Input Manufacturer Name [3-25][end with Ltd.]: ");
                scanf(" %[^\n]", namaManufaktur);
            } while(strlen(namaManufaktur) < 5 || strlen(namaManufaktur) > 50 || strcmp(namaManufaktur + strlen(namaManufaktur) - 4, "Ltd.") != 0);
            char regNum[100];
            do{
                printf("Input Registration Number [10][numeric]: ");
                scanf(" %[^\n]", regNum);
            } while(strlen(regNum) != 10 || atoi(regNum) == 0);
            int batch;
            do{
                printf("Input Batch / Lot Number [>=16]: ");
                scanf("%d", &batch);
            } while(batch < 16);
            char id[50];
            sprintf(id, "M%05d-%s-%c%c", counter, regNum, toupper(namaManufaktur[0]), toupper(namaObat[0]));
            counter++;
            insertMed(id, namaObat, namaManufaktur, regNum, batch);
            printf("Indek : %d\n", sumAscii(id) % MAXN);
            printf("\nInsert Success\n");
            printf("Press Any Key to Continue\n");
            getchar();
            getchar();
            system("cls");
        }
        else if(pilihan == 3){
            char id[50];
            printf("Input Medicine ID: ");
            scanf(" %[^\n]", id);
            removeMed(id);
            printf("Press Any Key to Continue\n");
            getchar();
            getchar();
            system("cls");
        }
        else if(pilihan == 4){
            printf("Thanks For Using This Program...\n");
        }
        else{
            printf("Invalid input\n");
        }
    } while(pilihan != 4);
    return 0;
}
