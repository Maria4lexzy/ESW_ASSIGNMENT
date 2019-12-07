#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "course.h"
#include "student.h"
#include "enrollment.h"


enrolment_t* enrol_student(pcourse_t* course, pcourse_t* student) {
	enrolment_t *enrolmentV = ((enrolment_t*)malloc(sizeof(enrolment_t)));
	if (enrolmentV == NULL) {
		return -1;
	}
	else {
		enrolmentV->course = course;
		enrolmentV->student = student;
		return enrolmentV;
	}

	}
void destroy_enrolment(enrolment_t* enrolment) {
	free(enrolment);
	enrolment = NULL;
}
pcourse_t* getCourseOfEnrolment(enrolment_t* enrolment) {

}
pcourse_t* getStudentOfEnrolment(enrolment_t* enrolment) {

}
void print_enrolment_info(enrolment_t* enrolment) {
	printf("S \t %s\t %s\n", enrolment->course, enrolment->student);

}