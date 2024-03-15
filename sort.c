//
//  sort.c
//  lab10
//
//  Created by Ульяна Тозик on 28.02.24.
//

#include <stdio.h>
#include "Header.h"


extern void sort_data(struct students_data* data, int num_students) //сортировка и вывод информации о студентах, фамилия которых начинается с буквы "Б"
{
    register int i;
    int flag=0;
    for (i=0;i<num_students;i++)
    {
        if (data[i].surname[0]=='B')
        {
            flag=1;
            printf("\nInformation about student found\n");
            printf("Surname and initials: %s %s\n", data[i].surname, data[i].initials);
            printf("Birth year: %d\n", data[i].year_birth);
            printf("BSUIR entrance year: %d\n", data[i].year_entrance);
            printf("Physics mark: %d\n", data[i].mark_physics);
            printf("Math mark: %d\n", data[i].mark_math);
            printf("Computer science mark: %d\n", data[i].mark_inform);
            printf("\n");
             
        }
    }
    if(flag==0)
    {
            printf("\nNo students whose surnmame starts with letter B on the list");
        }
}
