#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define CLEAR_SCREEN system("cls")

struct node{
    char nama[100];
    char nomor[100];
    char email[100];
    int visit;

    struct node *left;
    struct node *right;
};

struct obat{
    char namaObat[100];
    int harga;
};

struct order{
    char obat[100];
    int quantity;
    int harga;
};

struct obat obat[5];

struct node *root = NULL;

void insert(char nama[], char nomor[], char email[]){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *current = root;
    if(root == NULL){
        strcpy(temp -> nama, nama);
        strcpy(temp -> nomor, nomor);
        strcpy(temp -> email, email);
        temp -> visit = 1;
        temp -> left = NULL;
        temp -> right = NULL;
        root = temp;
    }
    else{
        while(1){
            if(strcmp(nomor, current -> nomor) < 0){
                if(current -> left == NULL){
                    strcpy(temp -> nama, nama);
                    strcpy(temp -> nomor, nomor);
                    strcpy(temp -> email, email);
                    temp -> visit = 1;
                    temp -> left = NULL;
                    temp -> right = NULL;
                    current -> left = temp;
                    break;
                }
                else{
                    current = current -> left;
                }
            }
            else if(strcmp(nomor, current -> nomor) > 0){
                if(current -> right == NULL){
                    strcpy(temp -> nama, nama);
                    strcpy(temp -> nomor, nomor);
                    strcpy(temp -> email, email);
                    temp -> visit = 1;
                    temp -> left = NULL;
                    temp -> right = NULL;
                    current -> right = temp;
                    break;
                }
                else{
                    current = current -> right;
                }
            }
            else{
                current -> visit++;
                break;
            }
        }
    }
}

int cekNomor(char nomor[]){
    struct node *current = root;
    while(current != NULL){
        if(strcmp(nomor, current -> nomor) < 0){
            current = current -> left;
        }
        else if(strcmp(nomor, current -> nomor) > 0){
            current = current -> right;
        }
        else{
            return 1;
        }
    }
    return 0;
}

void viewAllCustomer(struct node *current){
    if(current != NULL){
        viewAllCustomer(current -> left);
        printf("| %-20s | %-15s | %-30s | %-5d |\n", current -> nama, current -> nomor, current -> email, current -> visit);
        viewAllCustomer(current -> right);
    }
}

void deleteNomor(char nomor[]){
    struct node *current = root;
    struct node *prev = NULL;
    while(current != NULL){
        if(strcmp(nomor, current -> nomor) < 0){
            prev = current;
            current = current -> left;
        }
        else if(strcmp(nomor, current -> nomor) > 0){
            prev = current;
            current = current -> right;
        }
        else{
            if(current->left == NULL && current->right == NULL){
                if(prev == NULL){
                    current = NULL;
                    root = NULL;
                }
                else if(prev->left == current){
                    prev->left = NULL;
                    current = NULL;
                }
                else{
                    prev->right = NULL;
                    current = NULL;
                }
                return;
            }
            else if(current->left == NULL && current->right != NULL){
                if(prev == NULL){
                    root = current->right;
                    current = NULL;
                }
                else if(prev->left == current){
                    prev->left = current->right;
                    current = NULL;
                }
                else{
                    prev->right = current->right;
                    current = NULL;
                }
                return;
            }
            else if(current->left != NULL && current->right == NULL){
                if(prev == NULL){
                    root = current->left;
                    current = NULL;
                }
                else if(prev->left == current){
                    prev->left = current->left;
                    current = NULL;
                }
                else{
                    prev->right = current->left;
                    current = NULL;
                }
                return;
            }
            else{
                struct node *temp = current->left;
                struct node *parentOfTemp = current;
                while(temp->right != NULL){
                    parentOfTemp = temp;
                    temp = temp->right;
                }
                strcpy(current->nama, temp->nama);
                strcpy(current->nomor, temp->nomor);
                strcpy(current->email, temp->email);
                current->visit = temp->visit;
                if(parentOfTemp->left == temp){
                    parentOfTemp->left = temp->left;
                }
                else{
                    parentOfTemp->right = temp->left;
                }
                return;
            }
        }
    }
}

int main(){
    int pilihan;
    char pil, pil2;
    struct obat obat[5];
    struct order order[10];
    strcpy(obat[0].namaObat, "Paracetamol");
    obat[0].harga = 5000;
    strcpy(obat[1].namaObat, "Diapet");
    obat[1].harga = 7000;
    strcpy(obat[2].namaObat, "Oralit");
    obat[2].harga = 3500;
    strcpy(obat[3].namaObat, "Paratusin");
    obat[3].harga = 5500;
    strcpy(obat[4].namaObat, "OB Herbal");
    obat[4].harga = 6000;
    do{
        printf("SUNIB\'S PHARMACY\n");
        printf("===================\n");
        printf("1. Process Order\n");
        printf("2. View All Customer\n");
        printf("3. Remove Customer\n");
        printf("4. Exit\n");
        printf(">> ");
        scanf("%d", &pilihan);
        if(pilihan == 1){
            char nomor[100];
            do{
                printf("Enter your phone number[10-13][numeric]: ");
                scanf("%s", nomor);
            }while(strlen(nomor) < 10 || strlen(nomor) > 13 || atoi(nomor) == 0);
            if(cekNomor(nomor) == 0){
                printf("Do you want to join membership? [y/n]: ");
                scanf(" %c", &pil);
                if(pil == 'y'){
                    char nama[100];
                    do{
                        printf("Input Name[5-25][Mr. | Mrs.]: ");
                        scanf(" %[^\n]", nama);
                    } while(strlen(nama) < 5 || strlen(nama) > 25 || (strstr(nama, "Mr.") == NULL && strstr(nama, "Mrs.") == NULL));
                    char email[100];
                    do{
                        printf("Input Email[10-20][email format]: "); // harus ada @ sama di akhiri dengan .com atau .co.id
                        scanf("%s", email);
                    }while(strlen(email) < 10 || strlen(email) > 20 || (strstr(email, "@") == NULL) || (strstr(email, ".com") == NULL && strstr(email, ".co.id") == NULL));
                    insert(nama, nomor, email);
                    printf("\n");
                    printf("Insert Success !\n");
                }
                else{
                    continue;
                }
            }
            else{
                insert("", nomor, "");
            }
            printf("--------------------------------------------------\n");
            printf("| No   | Nama Obat                  | Harga Obat |\n");
            printf("--------------------------------------------------\n");
            for(int i = 0; i < 5; i++){
                printf("| %-4d | %-26s | %-10d |\n", i+1, obat[i].namaObat, obat[i].harga);
            }
            printf("--------------------------------------------------\n");
            int count = 0;
            int totalHarga = 0;
            do{
                int obatBeli;
                do{
                    printf("Input Number of Medicine[1-5]: ");
                    scanf("%d", &obatBeli);
                    strcpy(order[count].obat, obat[obatBeli-1].namaObat);
                    order[count].harga = obat[obatBeli-1].harga;
                } while(obatBeli < 1 || obatBeli > 5);
                int quantity;
                do{
                    printf("Input Quantity[>=1]: ");
                    scanf("%d", &quantity);
                    order[count].quantity = quantity;
                } while(quantity < 1);
                printf("Do you want to buy another medicine? [y/n]: ");
                scanf(" %c", &pil2);
                count++;
            } while(pil2 != 'n');
            printf("order summary\n");
            for(int i = 0; i < count; i++){
                printf("%-8s - %dx  = %d\n", order[i].obat, order[i].quantity, order[i].harga);
                totalHarga += order[i].harga * order[i].quantity;
            }
            printf("Total = %d\n", totalHarga);
            printf("press any key to continue");
            getch();
            system("cls");
        }
        else if(pilihan == 2){
            if(root == NULL){
                printf("There is no data !\n");
                printf("Press any key to continue");
                getch();
                system("cls");
                continue;
            }
            printf("-----------------------------------------------------------------------------------\n");
            printf("| Name                 | Phone Number    | Email                          | Visit |\n");
            printf("----------------------------------------------------------------------------------\n");
            viewAllCustomer(root);
            printf("-----------------------------------------------------------------------------------\n");
            printf("\nPress any key to continue");
            getch();
            system("cls");

        }
        else if(pilihan == 3){
            char nomor[100];
            printf("Enter phone number to remove[10-13][numeric]: ");
            scanf("%s", nomor);
            if(cekNomor(nomor) == 0 || root == NULL || strlen(nomor) < 10 || strlen(nomor) > 13 || atoi(nomor) == 0){
                printf("Data invalid !\n");
                printf("Press any key to continue");
                getch();
                system("cls");
                continue;
            }
            else{
                deleteNomor(nomor);
                printf("Delete Success !\n");
                printf("Press any key to continue");
                getch();
                system("cls");
            }
        }
        else if(pilihan == 4){
            printf("Thank you for using this program\n");
        }
        else{
            printf("Invalid input\n");
        }
    }while(pilihan != 4);

    return 0;
}
