//
//  main.c
//  lab10
//
//  Created by Ульяна Тозик on 16.02.24.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Header.h"

 
int main(void)
{
    
    struct students_data *data;
    int num_students=4;
    data=(struct students_data*)malloc(sizeof(struct students_data));
    //динамическое выделение памяти под структуры
    static int k=0;
    
    
    if (data==NULL)
    {
        printf("Memory allocation error.\n");
        return 1;
    }
    
    int choice;
    do
    {
        
        printf("\nMenu:\n");
        printf("1. Enter information about students\n");
        printf("2. Print information about students\n");
        printf("3. Sort information (print information about students whose surname starts with letter B\n");
        printf("4. Print information about student by surname\n");
        printf("5. Read data from file\n");
        printf("6. Write data to file\n");
        printf("7. End the programm\n");
        
        scanf("%d", &choice);
        if (choice==1){
            enter_data(data, num_students);
            k=1;
        }
        else if(choice==5){
            read_file(data, num_students);
            k=1;
        }
        else{
            printf("You have not entered any information yet!\n");
        }
    }while(k==0);
        
        do{
            
            printf("\nMenu:\n");
            printf("1. Enter information about students\n");
            printf("2. Print information about students\n");
            printf("3. Sort information (print information about students whose surname starts with letter B\n");
            printf("4. Print information about student by surname\n");
            printf("5. Read data from file\n");
            printf("6. Write data to file\n");
            printf("7. End the programm\n");
            printf("Your choice?\n");
            
            scanf("%d", &choice);
            switch (choice){
                case 1: {enter_data(data, num_students);
                    break;}
                case 2: {print_data(data, num_students);
                    break;}
                case 3: {sort_data(data, num_students);
                    break;}
                case 4: {read_data1(data, num_students);
                    break;}
                case 5: {read_file(data, num_students);
                    break;}
                case 6: {write_file(data, num_students);
                        break;}
                case 7: return 0;
                default: printf("Wrong choice. Try again\n");
            }
        } while(choice!=7);
        
        free(data);
    }
    
 




