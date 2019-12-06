#pragma once
#include "stdint.h"


struct student_t {
	int student_num;
	char* first_name;

};
typedef struct student_t pstudent_t;

pstudent_t* create_student(int student_num, char* self);
int get_student_numb(pstudent_t self);
char* get_student_name(pstudent_t self);
void destroy_student(pstudent_t* self);
void print_student_info(pstudent_t student);
