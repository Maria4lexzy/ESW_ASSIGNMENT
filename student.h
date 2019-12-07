#pragma once
#include "stdint.h"


typedef struct student_t {
	pcourse_t course_obj;
	int student_num;
	char* first_name;

}student_t;
typedef struct student_t* pstudent_t;

pstudent_t create_student(int student_num, char* self);
int get_student_numb(student_t self);
char* get_student_name(student_t self);
void destroy_student(pstudent_t self);
void print_student_info(pstudent_t student);
