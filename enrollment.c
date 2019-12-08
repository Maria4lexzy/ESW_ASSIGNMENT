#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "course.h"
#include "student.h"
#include "enrollment.h"

include <string.h>
#include "course.h"
#include "student.h"
#include "enrollment.h"
#include "linked_list.h"
#include <stdio.h>

static p_list_t enrolment_list;

enrolment_t* constructEnrolment(course_t* course, student_t* student) {
    enrolment_t* enrolment = (enrolment_t*)malloc(sizeof(enrolment_t));
    if (enrolment == NULL)
    {
        return NULL;
    }
    else
    {
        enrolment->course = course;
        enrolment->student = student;
        return enrolment;
    }
}
void destroyEnrolment(enrolment_t* enrolment) {
    free(enrolment);
}
void setEnrolmentCourse(enrolment_t* enrolment, course_t* course) {
    enrolment->course = course;
}
void setEnrolmentStudent(enrolment_t* enrolment, student_t* student) {
    enrolment->student = student;
}
course_t* getCourseOfEnrolment(enrolment_t* enrolment) {
    return enrolment->course;
}
student_t* getStudentOfEnrolment(enrolment_t* enrolment) {
    return enrolment->student;
}
void printEnrolmentInformation(enrolment_t* enrolment) {
    printf("E \t %d\t %d\n", enrolment->student->student_no, enrolment->course->course_no);
}

p_list_t create_enrolment_list()
{
    enrolment_list = linked_list_create();
    return enrolment_list;
}

p_list_t get_enrolment_list()
{
    return enrolment_list;
}

void remove_enrolment_from_list(p_enrolment_t enrolment)
{
    remove_item_from_list(enrolment_list, enrolment);
}

void add_enrolment_to_list(p_enrolment_t enrolment)
{
    if (enrolment_list == NULL) {
        enrolment_list = create_enrolment_list();
    }
    add_item_to_list(enrolment_list, enrolment);
}
