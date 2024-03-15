//
//  Header.h
//  lab10
//
//  Created by Ульяна Тозик on 16.02.24.
//

#ifndef Header_h
#define Header_h


struct students_data
{
    char surname[20];
    char initials[5];
    int year_birth;
    int year_entrance;
    int mark_physics;
    int mark_math;
    int mark_inform;
};
 

extern void enter_data(struct students_data* data, int num_students);
extern void print_data(struct students_data* data, int num_students);
extern void write_file(struct students_data data[], int num_students);
extern void read_file(struct students_data data[], int num_students);
extern int read_data1(struct students_data* data, int num_students);
extern void sort_data(struct students_data* data, int num_students);


#endif /* Header_h */
