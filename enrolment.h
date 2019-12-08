#pragma once
#include "student.h"
#include "course.h"
typedef struct enrolment_t* p_enrolment_t;

typedef struct enrolment_t {
    course_t *course;
    student_t *student;
}enrolment_t;

p_enrolment_t create_enrolment(p_course_t course, p_student_t student);
void destroy_enrolment(p_enrolment_t enrolment);
void set_course_to_enrolment(p_enrolment_t enrolment, p_course_t course);
void set_student_to_enrolment(p_enrolment_t enrolment, p_student_t student);
p_course_t get_course_of_enrolment(p_enrolment_t enrolment);
p_student_t get_student_of_enrolment(p_enrolment_t enrolment);
void print_enrolment_info(p_enrolment_t enrolment);
plist_t create_enrolment_list();
plist_t get_enrolment_list();
void remove_enrolment_from_list(p_enrolment_t enrolment);
void add_enrolment_to_list(p_enrolment_t enrolment);

