#pragma once
#include "student.h"
#include "course.h"

typedef struct enrolment_t* penrolment_t;

typedef struct enrolment_t {
	pcourse_t course;
	pstudent_t student;
}enrolment_t;

penrolment_t enrol_student(pcourse_t course, pstudent_t student);
void destroy_enrolment(penrolment_t enrolment);
pcourse_t getCourseOfEnrolment(penrolment_t enrolment);
pcourse_t getStudentOfEnrolment(penrolment_t enrolment);
void print_enrolment_info(penrolment_t enrolment);
