#pragma once
#include "stdint.h"

typedef struct teacher_t {
	int teacher_no;
	char* f_name;
}teacher_t;
typedef struct teacher_t* pteacher_t;

pteacher_t create_teacher(int teacher_no, char* f_name);
int get_teacherNo(teacher_t teacher);
char* get_teacher_name(teacher_t self);
void destroy_teacher(pteacher_t self);
void print_teacher_info(teacher_t teacher);