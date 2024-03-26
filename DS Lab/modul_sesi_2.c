#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLEAN_SCREEN "cls"

struct node{
    char data[50];
    struct node *next;
};

struct node *head = 0;

void insertFirst(char *obat){
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    strcpy(new_node->data, obat);
    new_node->next = head;
    head = new_node;
}

void deleteFirst(){
    struct node *delete = head;
    head = head->next;
    free(delete);
}

void printList(struct node *list){
    int i = 1;
    while(list != NULL){
        printf("Take Medicine #%d: %s\n", i, list->data);
        list = list->next;
        i++;
    }
}

void deleteAll(){
    struct node *delete;
    while(head != NULL){
        delete = head;
        head = head->next;
        free(delete);
    }
}

int main(){
    int counter = 0;
    char data[50], pilihan[10];
    do{
        printf("Sunib Hospital\n");
        printf("******************\n");
        do{
            printf("Enter the medicine name [minimun 5 medicine] (\'done\'): ");
            scanf(" %[^\n]", data); getchar();
            if(strcmp(data, "done") == 0){
                continue;
            }
            else{
                insertFirst(data);
                printf("Medicine %s added to the prescription\n", data);
                counter++;
            }
        }while (counter < 5 || (counter >= 5 && strcmp(data, "done") != 0));
        printf("\n");
        printList(head);
        printf("do you want to continue ? (yes/no): ");
        scanf("%s", pilihan);
        system("cls");
        counter = 0;
        deleteAll();
    } while(strcmp(pilihan, "no") != 0);
    return 0;
}
