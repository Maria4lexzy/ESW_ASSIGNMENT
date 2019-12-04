#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef struct course* course_t;

course_t create_course(int course_num, char* course_name, int semester_num);

void destroy_course(course_t self);

int get_course_numb(course_t self);
int get_semester_num(course_t self);
char* ge_course_name(course_t self);
course_t get_nextCourse_address(course_t self);
void set_nextCourse_address(course_t self, course_t next);
