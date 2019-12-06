#pragma once
#include "stdint.h"

struct course_t {
	int course_num;
	char* course_name;
	int semester_num;
};
typedef struct course_t pcourse_t;

pcourse_t* create_course(int course_num, char* course_name, int semester_no);
void destroy_course(pcourse_t* course);
int get_course_num(pcourse_t course);
char* get_course_name(pcourse_t course);
int get_semester_num(pcourse_t course);
void print_course_info(pcourse_t* course);