#pragma once
#include <stdlib.h>
#include <stdio.h>
typedef struct student_t* pstudent_t;

struct student {
	int student_num;
	int first_name;

}student_t;

pstudent_t create_student(int student_num, char* self);
int get_student_numb(pstudent_t self);
char* get_student_name(pstudent_t self);
void destroy_student(pstudent_t self);
//we maybe need this
pstudent_t get_next_student_address(pstudent_t self);
void set_next_student_addressp(pstudent_t self, pstudent_t next);
void print_student_info(pstudent_t student);
