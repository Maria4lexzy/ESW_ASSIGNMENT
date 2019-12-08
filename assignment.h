#pragma once
#include "linked_list.h"
#include "course.h"
#include "teacher.h"


typedef struct assignment_t {
	course_t* course;
	teacher_t* teacher;
}assignment_t;
typedef struct assignment_t* p_assignment_t;

plist_t create_assignment_list();
p_assignment_t create_assignment(p_course_t course, p_teacher_t teacher);
void destroy_assignment(p_assignment_t assignment);
void set_course_to_assignment(p_assignment_t assignment, p_course_t course);
void set_teacher_to_assignment(p_assignment_t assignment, p_teacher_t teacher);
p_course_t get_course_assignment(p_assignment_t assignment);
p_teacher_t get_teacher_assignment(p_assignment_t assignment);
void print_assignment_info(p_assignment_t assignment);
plist_t get_assignment_list();
void add_assignment_to_list(p_assignment_t assignment);
void remove_assignment_from_list(p_assignment_t assignment);
