//
//  function.c
//  lab10
//
//  Created by Ульяна Тозик on 16.02.24.
//

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <stdlib.h>
#include "Header.h"


static int contain_digit(const char* str){
    while(*str){
        if(isdigit(*str)){
            return 1;
        }
        str++;
    }
    return 0;
}

void write_file(struct students_data data[], int num_students){
    FILE *file=fopen("data1.txt", "w");
    if(file==NULL){
        printf("Error opening file\n");
        return;
    }
    for(int i=0;i<num_students;i++){
        fprintf(file, "%s %s %d %d %d %d %d\n", data[i].surname, data[i].initials, data[i].year_birth, data[i].year_entrance, data[i].mark_physics, data[i].mark_math, data[i].mark_inform);
    }
    printf("Information is written from file\n");
    
    fclose(file);
}

void read_file(struct students_data data[], int num_students){
    FILE *file=fopen("data1.txt", "r");
    if (file==NULL){
        printf("Error opening file\n");
        return;
    }
    
    for(int i=0;i<num_students;i++){
        fscanf(file, "%s %s %d %d %d %d %d\n", data[i].surname, data[i].initials, &data[i].year_birth, &data[i].year_entrance, &data[i].mark_physics, &data[i].mark_math, &data[i].mark_inform);
    }
    
    printf("Information is read from file\n");
    
    fclose(file);
    
}


extern void enter_data(struct students_data data[], int num_students) //функция ввода
{
    
    register int i;
    for(i=0;i<num_students;i++){
        printf("\nEnter information for 4 students\n");
        printf("Enter surname\n");
        scanf("%s", data[i].surname);
        if(contain_digit(data[i].surname)){
            printf("The entered value is invalid. Try again\n");
            return;
        }
        printf("Enter initials\n");
        scanf("%s", data[i].initials);
        if(contain_digit(data[i].initials)){
            printf("The entered value is invalid. Try again\n");
            return;
        }
        printf("Enter birth year\n");
        int year_birth;
        if (scanf("%d", &year_birth) == 1)
        {
            if (year_birth >= 1947 && year_birth <= 2007)
            {
                data[i].year_birth = year_birth;
            }
            else
            {
                printf("Invalid value. Value must be in range 1947-2007\n");
                return;
                
            }
        }
        else
        {
            printf("Invalid value. Enter a number\n");
            return;
        }
            
       
        
        printf("Enter BSUIR year entrance\n");
        int year_entrance;
        if (scanf("%d", &year_entrance) == 1) {
            if (year_entrance >= 1964 && year_entrance <= 2023) {
                data[i].year_entrance = year_entrance;
        
            } else {
                printf("Invalid value. Value must be in range 1967-2023\n");
                return;
                
            }
        } else {
            printf("Invalid value. Enter a number\n");
            return;
        }
        
        printf("Enter physics mark\n");
        int mark_physics;
        if (scanf("%d", &mark_physics) == 1) {
            if (mark_physics >0  && mark_physics <= 10) {
                data[i].mark_physics = mark_physics;
                 
            } else {
                printf("Invalid value. Value must be in range 1-10\n");
                return;
                
            }
        } else {
            printf("Invalid value. Enter a number\n");
            return;
        }
         
        printf("Enter math mark\n");
        int mark_math;
        if (scanf("%d", &mark_math) == 1) {
            if (mark_math >0  && mark_math <= 10) {
                data[i].mark_math = mark_math;
  
            } else {
                printf("Invalid value. Value must be in range 1-10\n");
                return;
                
            }
        } else {
            printf("Invalid value. Enter a number\n");
            return;
        }
         
        printf("Enter computer science mark\n");
        int mark_inform;
        if (scanf("%d", &mark_inform) == 1) {
            if (mark_inform >0  && mark_inform <= 10) {
                data[i].mark_inform = mark_inform;
                 
            } else {
                printf("Invalid value. Value must be in range 1-10\n");
                return;
                
            }
        } else {
            printf("Invalid value. Enter a number\n");
            return;
        }
         
    }
    printf("Data written to file\n");
}

extern void print_data(struct students_data* data, int num_students) //функция вывода
{
    printf("\n");
        printf("***********************************************************************************************************************************************\n");
        printf("| # |   Surname   |    Initials     | Year birth | BSUIR year entrance|         First semester grades          |               \n");
        printf("***********************************************************************************************************************************************\n");
        printf("|   |             |                 |              |                        |   math   |  physics  | computer science| \n");
        printf("***********************************************************************************************************************************************\n");
        for (int i = 0;i < num_students;i++)
        {
             
            printf("%3d   %-11s     %-10s  %10d  %17d  %18.0d  %14.0d  %13.0d  \n", i+1, data[i].surname, data[i].initials, data[i].year_birth, data[i].year_entrance, data[i].mark_physics, data[i].mark_math, data[i].mark_inform);
            printf("***********************************************************************************************************************************************\n");
        }
        printf("\n");

}

extern int read_data1(struct students_data* data, int num_students) //функция выведения информации о студенте по его фамилии
{
    register int i;
    char s[10];
    int flag1=0;
    printf("\nEnter student's surname\n");
    scanf("%s", s);
    for (i=0;i<num_students;i++)
    {
        if(strcmp(data[i].surname, s)==0)
        {
            flag1=1;
            printf("\nInformation about student is found\n");
            printf("Surname and initials: %s %s\n", data[i].surname, data[i].initials);
            printf("Birth year: %d\n", data[i].year_birth);
            printf("BSUIR year entrance: %d\n", data[i].year_entrance);
            printf("Physics mark: %d\n", data[i].mark_physics);
            printf("Math mark: %d\n", data[i].mark_math);
            printf("Computer science mark: %d\n", data[i].mark_inform);
        }
    }
    if(flag1==0)
    {
        printf("\nNo student with such surname\n");
         
    }
    return 0;
}



