#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define CLEAN_SCREEN "cls"
struct stock
{
    char code[10];
    char name[50];
    char penyakit[50];
    int stock;
    int price;
};

void add_stock(struct stock *pointer)
{
    char code[10];
    int quantity;
    int found = 0;
    int i;
    do
    {
        do
        {
            printf("Enter medicine code: ");
            scanf("%s", code);
            for(i = 0; i<4; i++)
            {
                if(strcmp(code, pointer[i].code) == 0)
                {
                    found = 1;
                    break;
                }
            }
            if(found == 0)
            {
                printf("Medicine not found\n");
            }
        } while (found == 0);
        
        for(i = 0; i<4; i++)
        {
            if(strcmp(code, pointer[i].code) == 0)
            {
                do
                {
                    printf("Enter quantity[1-100]: ");
                    scanf("%d", &quantity);
                } while (quantity < 1 || quantity > 100);
                pointer[i].stock += quantity;
                printf("Stock updated\n");
                break;
            }
            else
            {
                printf("Medicine not found\n");
            }
        }
    } while (strcmp(code, pointer[i].code) != 0);
}

void sell(struct stock *pointer)
{
    char code[10];
    int quantity;
    int found = 0;
    int i;
    do
    {
        do
        {
            printf("Enter medicine code: ");
            scanf("%s", code);
            for(i = 0; i<4; i++)
            {
                if(strcmp(code, pointer[i].code) == 0)
                {
                    found = 1;
                    break;
                }
            }
            if(found == 0)
            {
                printf("Medicine not found\n");
            }
        } while (found == 0);
        
        for(i = 0; i<4; i++)
        {
            if(strcmp(code, pointer[i].code) == 0)
            {
                do
                {
                    printf("Enter quantity[1-%d]: ", pointer[i].stock);
                    scanf("%d", &quantity);
                } while (quantity < 1 || quantity > pointer[i].stock);
                pointer[i].stock -= quantity;
                break;
            }
            else
            {
                printf("Medicine not found\n");
            }
        }
    } while (strcmp(code, pointer[i].code) != 0);
    printf("+----Total Price----+\n");
    printf("%d\n", pointer[i].price);
    printf("Quantity: %d\n", quantity);
    printf("-------------------X\n");
    printf("Total: %d\n", pointer[i].price * quantity);
    printf("+-------------------+\n");
    printf("\n\n");
    printf("-- Thank you --\n");
}

int main()
{
    int pilihan;
    struct stock obat[5] = {
        {"DIZ001", "Paramex", "Dizziesness", 120, 14000},
        {"FLU001", "Panadol", "Flu & Fever", 57, 8000},
        {"DIA001", "Diatabs", "Diarrhea", 10, 6500},
        {"DIA002", "Diapet", "Diarrhea", 18, 6000}
    };
    do
    {
        printf("             +----------------------------------------+\n");
        printf("             |              Sunib Hospital            |\n");
        printf("             +----------------------------------------+\n");
        printf("\n");
        printf("+---------------------------------------------------------------------+\n");
        printf("|No.| Medicine Code   | Medicine Name         | Stock | Price         |\n");
        printf("+---------------------------------------------------------------------+\n");
        for(int i = 0; i<4; i++)
        {
            printf("|%d  | %-15s | %-21s | %-4d | %-14d |\n", i+1, obat[i].code, obat[i].name, obat[i].stock, obat[i].price);
        }
        printf("+---------------------------------------------------------------------+\n");
        printf("1. Add Stock\n");
        printf("2. sell\n");
        printf("3. exit\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        if(pilihan == 1)
        {
            add_stock(obat);
            printf("Press Enter to Continue....\n");
            getchar();
            getchar();
            system("cls");
        }
        else if(pilihan == 2)
        {
            sell(obat);
            printf("Press Enter to continue....\n");
            getchar();
            getchar();
            system("cls");
        }
        else if(pilihan == 3)
        {
            system("cls");
            printf("Terima kasih\n");
        }
        else
        {
            printf("Pilihan tidak ada\n");
        }
    } while (pilihan != 3);
    
    
    

    return 0;
}
