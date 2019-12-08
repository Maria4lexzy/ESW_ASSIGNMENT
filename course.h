#pragma once
#include "linked_list.h"

typedef struct course_t* p_course_t;

typedef struct course_t{
int course_no;
char* course_name;
int semester_no;
}course_t;

p_course_t create_course(int course_no, char* course_name, int semester_no);
void destroy_course(p_course_t course);
void set_coure_num(p_course_t course, int course_no);
void set_course_name(p_course_t course, char* course_name);
void set_semester_num(p_course_t course, int semester_no);
int getCourseNo(p_course_t course);
char* getCourseName(p_course_t course);
int get_semeter_num(p_course_t course);
void print_Course_Information(p_course_t course);
p_list_t create_course_list();
void remove_course_from_list(p_course_t course);
p_course_t get_course_from_list(int course_no);
void add_course(p_course_t course);
p_list_t get_course_list();


