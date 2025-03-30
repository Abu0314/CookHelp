#include <stdio.h>
#include <stdlib.h>
#include "shoppinglist.h"


void read_list(){
    char content[1000];
    FILE* fptr = fopen(SHOPPING_LIST_FILE, "r");
    if (fptr != NULL){
        while(fgets(content, 1000, fptr)){
            printf("%s", content);
        }
        fclose(fptr);
    }else{
        printf("File doesnt exist");
    }
}

void add_item(const char *item){
    FILE* fptr = fopen(SHOPPING_LIST_FILE, "a");
    if (fptr != NULL){
        fprintf(fptr, "%s\n", item);
        fclose(fptr);
    }else{
        printf("File doesnt exist");
    }
}

void clear_list(){
    FILE* fptr = fopen(SHOPPING_LIST_FILE, "w");
    if (fptr != NULL){
        fclose(fptr);
    }else{
        printf("File doesnt exist");
    }
}


