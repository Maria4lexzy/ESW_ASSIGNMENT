#pragma once

typedef struct course_t{
int course_no;
char* course_name;
int semester_no;
}course_t;

typedef struct course_t* p_course_t;

p_course_t create_course(int course_no, char* course_name, int semester_no);

void destroy_course(p_course_t course);
void set_coure_num(p_course_t course, int course_no);
void set_course_name(p_course_t course, char* course_name);
void set_semester_num(p_course_t course, int semester_no);
int get_course_num(p_course_t course);
char* get_course_name(p_course_t course);
int get_semeter_num(p_course_t course);
void print_course_info(p_course_t course);



