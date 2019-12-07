#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "course.h"
#include "student.h"
#include "enrollment.h"


penrolment_t enrol_student(pcourse_t course, pcourse_t student) {
	enrolment_t *enrolmentV = ((penrolment_t)malloc(sizeof(enrolment_t)));
	if (enrolmentV == NULL) {
		return NULL;
	}
	else {
		enrolmentV->course = course;
		enrolmentV->student = student;
		return enrolmentV;
	}

	}
void destroy_enrolment(penrolment_t enrolment) {
	free(enrolment);
	enrolment = NULL;
}
pcourse_t getCourseOfEnrolment(penrolment_t enrolment) {

}
pcourse_t getStudentOfEnrolmentp(penrolment_t enrolment) {

}
void print_enrolment_info(penrolment_t enrolment) {
	printf("S \t %s\t %s\n", enrolment->course, enrolment->student);

}