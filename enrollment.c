#include <stdio.h>
#include "course.h"
#include "student.h"
#include "enrollment.h"



p_enrollment_t* construct_enrollment(pcourse_t course, pstudent_t student) { return NULL; }
void destroy_enrollment(p_enrollment_t enrolment){}
void set_enrollment_course(p_enrollment_t enrollment, pcourse_t course){}
void set_enrollment_student(p_enrollment_t enrollment, pstudent_t student){}
pcourse_t* get_course_enrollment(p_enrollment_t enrolment) { return NULL; }
pstudent_t* get_enrolled_student(p_enrollment_t enrolment) { return NULL; }
void print_enrollmentInformation(p_enrollment_t enrolment){}
void remove_enrolment_from_list(p_enrollment_t enrolment){}
void add_enrolment_to_list(p_enrollment_t enrolment){}

//maybe
//p_list_t create_enrollment_list() {}
//p_list_t get_enrollment_list();