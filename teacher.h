#pragma once
#include <stdlib.h>
#include <stdio.h>
typedef struct teacher_t* pteacher_t;
typedef struct teacher_t {
	int teacher_no;
	char* f_name;
}teacher_t;

pteacher_t create_teacher(int teacher_no, char f_name);
void destroy_eacher(pteacher_t teacher);
void set_teacher_num(teacher_t teacher, int teacher_no);
void set_teacher_name(pteacher_t teacher, char f_name);
int get_teacherNo(pteacher_t teacher);
char get_teacherFName(pteacher_t teacher);
void print_teacher_info(pteacher_t teacher);