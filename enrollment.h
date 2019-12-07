#pragma once
#include "student.h"
#include "course.h"

typedef struct enrolment_t* p_enrolment_t;

typedef struct enrolment_t {
	pcourse_t* course;
	pstudent_t* student;
}enrolment_t;

enrolment_t* enrol_student(pcourse_t* course, pcourse_t* student);
void destroy_enrolment(enrolment_t* enrolment);
pcourse_t* getCourseOfEnrolment(enrolment_t* enrolment);
pcourse_t* getStudentOfEnrolment(enrolment_t* enrolment);
void print_enrolment_info(enrolment_t* enrolment);
