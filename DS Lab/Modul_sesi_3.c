#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CLEAN_SCREEN "cls"

struct node{
    char nama[100];
    int umur;
    char id[100];
    char deskripsi[100];
    char kode[100];
    struct node *next;
};

void insertLast(struct node **head, char nama[], int umur, char id[], char deskripsi[], char kode[]){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    strcpy(temp->nama, nama);
    temp->umur = umur;
    strcpy(temp->id, id);
    strcpy(temp->deskripsi, deskripsi);
    strcpy(temp->kode, kode);
    temp->next = NULL;
    if(*head == NULL){
        *head = temp;
    }
    else{
        struct node *temp2 = *head;
        while(temp2->next != NULL){
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
}

int cekid(struct node *headR, struct node *headY, struct node *headG, char id[]){
    int unik = 0;
    struct node *temp = headR;
    while(temp != NULL){
        if(strcmp(temp->id, id) == 0){
            unik = 1;
            break;
        }
        temp = temp->next;
    }
    temp = headY;
    while(temp != NULL){
        if(strcmp(temp->id, id) == 0){
            unik = 1;
            break;
        }
        temp = temp->next;
    }
    temp = headG;
    while(temp != NULL){
        if(strcmp(temp->id, id) == 0){
            unik = 1;
            break;
        }
        temp = temp->next;
    }
    if(unik == 1){
        printf("ID already exist !\n");
    }
    return unik;
}

void viewList(struct node *headR, struct node *headG, struct node *headY){
    struct node *temp = headR;
    int no = 1;
    if(temp == NULL){
        temp = headY;
        if(temp == NULL){
            temp = headG;
            if(temp == NULL){
                printf("There is no queue yet !\n");
                printf("Press any key to continue...");
                getchar();
                getchar();
                system("cls");
                return;
            }
        }
    }
    printf("Patient List\n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("| No  | Name                     | Age | ID       | Description                             | Code     |\n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    temp = headR;
    while(temp != NULL){
        printf("| %-4d| %-25s| %-4d| %-9s| %-40s| %-9s|\n", no, temp->nama, temp->umur, temp->id, temp->deskripsi, temp->kode);
        no++;
        temp = temp->next;
    }
    temp = headY;
    while(temp != NULL){
        printf("| %-4d| %-25s| %-4d| %-9s| %-40s| %-9s|\n", no, temp->nama, temp->umur, temp->id, temp->deskripsi, temp->kode);
        no++;
        temp = temp->next;
    }
    temp = headG;
    while(temp != NULL){
        printf("| %-4d| %-25s| %-4d| %-9s| %-40s| %-9s|\n", no, temp->nama, temp->umur, temp->id, temp->deskripsi, temp->kode);
        no++;
        temp = temp->next;
    }
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("\n");
    printf("Press any key to continue...");
    getchar();
    getchar();
    system("cls");
    
}

void nextQueue(struct node **headR, struct node **headG, struct node **headY){
    if(*headR != NULL){
        struct node *temp = *headR;
        *headR = (*headR)->next;
        printf("The next patient is:\n");
        printf("Name            : %s\n", temp->nama);
        printf("Age             : %d\n", temp->umur);
        printf("ID              : %s\n", temp->id);
        printf("Description     : %s\n", temp->deskripsi);
        printf("Code            : %s\n", temp->kode);
        printf("Press any key to continue...");
        getchar();
        getchar();
        system("cls");
        free(temp);
    }
    else if(*headY != NULL){
        struct node *temp = *headY;
        *headY = (*headY)->next;
        printf("The next patient is:\n");
        printf("Name            : %s\n", temp->nama);
        printf("Age             : %d\n", temp->umur);
        printf("ID              : %s\n", temp->id);
        printf("Description     : %s\n", temp->deskripsi);
        printf("Code            : %s\n", temp->kode);
        printf("Press any key to continue...");
        getchar();
        getchar();
        system("cls");
        free(temp);
    }
    else if(*headG != NULL){
        struct node *temp = *headG;
        *headG = (*headG)->next;
        printf("The next patient is:\n");
        printf("Name            : %s\n", temp->nama);
        printf("Age             : %d\n", temp->umur);
        printf("ID              : %s\n", temp->id);
        printf("Description     : %s\n", temp->deskripsi);
        printf("Code            : %s\n", temp->kode);
        printf("Press any key to continue...");
        getchar();
        getchar();
        system("cls");
        free(temp);
    }
    else{
        printf("There is no queue yet !\n");
        printf("Press any key to continue...");
        getchar();
        getchar();
        system("cls");
    }
}


int main(){
    struct node *headR = NULL;
    struct node *headG = NULL;
    struct node *headY = NULL;

    int pilihan;
    do{
        printf("Sunib Patient Entry\n");
        printf("=====================\n");
        printf("[1] Insert Patient\n");
        printf("[2] View List\n");
        printf("[3] Next Queue\n");
        printf("[4] Exit\n");
        printf(">>> ");
        scanf("%d", &pilihan);
        if(pilihan == 1){
            char nama[100];
            int umur;
            char id[100];
            char deskripsi[100];
            char kode[100];
            do{
                printf("Input Patient Name[4-25]: ");
                scanf(" %[^\n]", nama);
            }while(strlen(nama) < 4 || strlen(nama) > 25);
            do{
                printf("Input Patient Age[>=0]: ");
                scanf("%d", &umur);
            }while(umur < 0);
            do{
                printf("Input Patient ID[5]: ");
                scanf(" %[^\n]", id);
                
            }while(strlen(id) != 5 || cekid(headR, headY, headG, id) == 1);
            do{
                printf("Input Patient Description[>= 6 characters]: ");
                scanf(" %[^\n]", deskripsi);
            }while(strlen(deskripsi) < 6);
            do{
                printf("Input Patient Code[Red|Yellow|Green]: ");
                scanf(" %[^\n]", kode);
            }while(strcmp(kode, "Red") != 0 && strcmp(kode, "Green") != 0 && strcmp(kode, "Yellow") != 0);
            if(strcmp(kode, "Red") == 0){
                insertLast(&headR, nama, umur, id, deskripsi, kode);
            }
            else if(strcmp(kode, "Green") == 0){
                insertLast(&headG, nama, umur, id, deskripsi, kode);
            }
            else if(strcmp(kode, "Yellow") == 0){
                insertLast(&headY, nama, umur, id, deskripsi, kode);
            }
            printf("Insert Success !\n");
            printf("Press any key to continue...");
            getchar();
            getchar();
            system("cls");
        }
        else if(pilihan == 2){
            viewList(headR, headG, headY);
        }
        else if(pilihan == 3){
            nextQueue(&headR, &headG, &headY);
        }
        else if(pilihan == 4){
            printf("Thank you for using Sunib Patient Entry\n");
        }
        else{
            printf("Invalid input\n");
        }
    }while(pilihan != 4);
    return 0;
}
