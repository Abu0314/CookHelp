#include <ctype.h>
#include <stdio.h>
#include "conversion.h"
#include "shoppinglist.h"
#include "portion.h"


int main(){

    double g;
    char ingredient;
    int option;
    int list_option, ps, og, af;
    char item[40];
    char *ingredients[MAX_SIZE];
    double sizes[MAX_SIZE];
    int size = 0;
    char pi[50];

    
    while(1){
    
        printf("\nWhich would you like to choose?\n1. Conversion\n2. Shopping List\n3. Portion calculator\n4. Exit\n");
        scanf("%d", &option);

        getchar();

        switch (option){
            case 1: 
                ingredient = '\0';
                while(ingredient != 'L'){
                    printf("\nWhich ingredient\nF: flour\nS: sugar\nL: leave conversion\n");
                    scanf(" %c", &ingredient);
                    ingredient = toupper(ingredient);

                     if (ingredient == 'L') {
                        printf("Exiting conversion..\n");
                        break;
                     }
                     
                    printf("\nEnter grams you want to use: ");
                    scanf("%lf", &g);

                    double result = convert_to_ml(g, ingredient);
                    if (result != -1 ){
                        printf("%.2f ml\n", result);
                    }else{
                        printf("Not a number\n");
                    }
                }
                break;
                
            case 2:
            while(list_option != 4){
                printf("\n1. Read list\n2. Add item\n3. Clear list\n4. Exit shop list\n");
                scanf("%d", &list_option);

                switch(list_option){
                    case 1:
                        read_list();
                        break;
                    case 2:
                        printf("\nWhat item would you like to add: ");
                        scanf("%s", item);
                        add_item(item);
                        break;
                    case 3:
                        clear_list();
                        break;
                        
                    case 4:
                        printf("Exiting shopping list...\n");
                        break;
                    default:
                        printf("Not an option for list\n");
                        break;
                }
            }
                break;

                case 3:
                list_option = 0;
                while(list_option != 3){
                    printf("\n1. Add item to calculate\n2. Calculate\n3. Exit\n");
                    scanf("%d", &list_option);

                    switch (list_option){
                        case 1:
                            printf("\nWhat item would you like to add?\n");
                            scanf("%s", pi);
                            printf("\nHow much would you like to calculate?\n");
                            scanf("%d", &ps);
                            add_ing(pi, ps, ingredients, sizes, &size);
                            break;
                        case 2:
                            printf("\nHow many portions does the recipie have?\n");
                            scanf("%d", &og);
                            printf("\nHow many portions do you want?\n");
                            scanf("%d", &af);
                            calculate_ps(ingredients, sizes, &size, og, af);
                            break;
                        case 3:
                            printf("Exiting Portion Calculator...\n");
                            break;
                    default:
                            printf("Not an option for portion calculator\n");
                            break;
                    }
                    
                }
                break;
                case 4:
                    printf("Exiting...\n");
                    return 0;
                    
                default:
                    printf("Not an option\n");
                    break;        
        }
    }
}
