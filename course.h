//
// Created by Alicja Siudak on 03/12/2019.
//
#ifndef ESW_ASSIGNMENT_COURSE_H
#define ESW_ASSIGNMENT_COURSE_H

#include "linked_list.h"

typedef struct course_t* p_course_t;

typedef struct course_t{
//C course_number course_name semester_number
int course_no;
char* course_name;
int semester_no;
}course_t;

course_t* createCourse(int course_no, char* course_name, int semester_no);
void destroyCourse(course_t* course);
void setCourseNo(course_t* course, int course_no);
void setCourseName(course_t* course, char* course_name);
void setSemesterNo(course_t* course, int semester_no);
int getCourseNo(course_t* course);
char* getCourseName(course_t* course);
int getSemesterNo(course_t* course);
void print_Course_Information(course_t *course);
p_list_t create_course_list();
void remove_course_from_list(p_course_t course);
course_t* get_course_from_list(int course_no);
void add_course_to_list(p_course_t course);
p_list_t get_course_list();


#endif //ESW_ASSIGNMENT_COURSE_H
