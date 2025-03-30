#include "portion.h"
#include <string.h>
#include <stdio.h>


void add_ing(char ing[], int v, char *arr1[], double arr2[], int *size){
    for(int i = 0; i < *size; i++){
        if(strcmp(arr1[i], ing) == 0){
            arr2[i] = v;
            return;
        }
    }

    if(*size >= MAX_SIZE){
        printf("List is full");
    }
    arr1[*size] = strdup(ing);
    arr2[*size] = v;
    (*size)++;
        
}

void calculate_ps(char *arr1[], double arr2[], int *size, int og, int af){
    for(int i = 0; i < *size; i++){
        printf("%s should be %.2f\n", arr1[i], (arr2[i]/og)*af);
    }
}
