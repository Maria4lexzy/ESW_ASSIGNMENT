#pragma once
#include <stdio.h>
#include <stdbool.h>
#include "teacher.h"
#include "course.h"

typedef struct assignment_t {
	pcourse_t course;
	pteacher_t teacher;
}assignment_t;
typedef struct assignment_t* passignment_t;

passignment_t create_assignment(pcourse_t course, pteacher_t teacher);
void destroy_assignment(passignment_t assignment);
void set_assignment_course(passignment_t assignment, pcourse_t course);
void set_assignment_teacher(passignment_t assignment, pteacher_t teacher);
pcourse_t get_assignment_course(passignment_t assignment);
pteacher_t get_assignment_teacher(passignment_t assignment);
void print_assignment_info(passignment_t assignment);
