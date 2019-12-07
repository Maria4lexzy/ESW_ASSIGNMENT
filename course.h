#pragma once
#include "stdint.h"
#include "student.h"
#include "student_list.h"
typedef struct course_t {
	p_student_list_node  students;
	int course_num;
	char* course_name;
	int semester_num;
	
} course_t;
typedef struct course_t* pcourse_t;

pcourse_t create_course(int course_num, char* course_name, int semester_no);
void destroy_course(pcourse_t course);
int get_course_num(course_t course);
char* get_course_name(course_t course);
int get_semester_num(course_t course);
void print_course_info(pcourse_t course);