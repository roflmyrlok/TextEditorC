//
// Created by Андрей Трибушной on 23.09.2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct CharNode{
    int index;
    char data;
    struct CharNode* next;
};

struct RowNode {
    int position;
    struct CharNode* head;
    struct RowNode* next;
};


struct RowNode* rowNodePointer;
struct RowNode* rowHead = NULL;
bool start = 0;
int lines = 0;


void newLine(){
   if (start == 0) {
       start = 1;
       rowNodePointer = (struct RowNode*) malloc(sizeof(struct RowNode));
       rowNodePointer->head = (struct CharNode*) malloc(sizeof(struct CharNode));
       lines = 1;
       rowNodePointer->position = lines;
       rowHead = rowNodePointer;
   }else{
       rowNodePointer->next = (struct RowNode*) malloc(sizeof(struct RowNode));
       rowNodePointer = rowNodePointer->next;
       rowNodePointer->head = (struct CharNode*) malloc(sizeof(struct CharNode));
       lines++;
       rowNodePointer->position = lines;
   }
}
void append(){
    if (start == 0){
        newLine();
    }
    struct CharNode* current = rowNodePointer->head;
    while (current->next != NULL){
        current = current->next;
    }

    char input[30];
    printf("enter text: ");
    scanf("%s", input);
    int i = 0;
    while(input[i] != 0){
        current->next = (struct CharNode*) malloc(sizeof(struct CharNode));
        current->next->index = current->index + 1;
        current = current->next;
        current->data = input[i];
        i++;
    }
    printf("done \n");
}
void workWithFile(){

};
void printAll(){
    struct RowNode* currentRow = rowHead;
    while(true){
        struct CharNode* currentChar = currentRow->head;
        while(true){
            if (currentChar->data == 0){
                if (currentChar->next == NULL){
                    break;
                }
                currentChar = currentChar->next;
                continue;
            }
            char a = currentChar->data;
            printf("%c", a);
            if (currentChar->next == NULL){
                break;
            }
            currentChar = currentChar->next;
        }
        printf("\n");
        if (currentRow->next == NULL) break;
        currentRow = currentRow->next;
    }
};
void insert(){
    //printf("insert\n");
};
void search(){
    //printf("search\n");
};
int main() {
    struct CharNode charNode = {.next = NULL};
    struct RowNode rowNode = {.next = NULL};
    while (1) {
            //char *p, s[100];
            int n;
            printf("Choose the command: ");
            if(scanf("%d", &n) == 0){
                printf("Must be an integer: ");
                fflush(stdin);
                continue;
            }
            if (!(n >= 0 && n <= 7)){
                printf("The command is not implemented! \n");
                continue;
            }
        switch (n) {
            case 1:
                append();
                break;
            case 2:
                newLine();
                break;
            case 3:
                workWithFile();
                break;
            case 4:
                printAll();
                break;
            case 5:
                insert();
                break;
            case 6:
                search();
                break;
            default:
                continue;
        }
        //system("clear");
    }
}
