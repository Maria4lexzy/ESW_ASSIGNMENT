#pragma once
#include "linked_list.h"

typedef struct student_t {
    int student_no;
    char *f_name;
}student_t;
typedef struct student_t* p_student_t;

p_student_t create_student(int student_no, char *f_name);
void destroy_student(p_student_t student);
void set_student_num(p_student_t student, int student_no);
void set_student_name(p_student_t student, char *f_name);
int get_student_number(p_student_t student);
char* get_student_name(p_student_t student);
void print_student_info(p_student_t student);
p_student_t get_student(int student_no);
void add_student(p_student_t student);
void remove_student_from_list(p_student_t);
plist_t create_student_list();
plist_t get_student_list();



