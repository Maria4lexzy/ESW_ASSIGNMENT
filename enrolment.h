//
// Created by Alicja Siudak on 03/12/2019.
//

#ifndef ESW_ASSIGNMENT_ENROLMENT_H
#define ESW_ASSIGNMENT_ENROLMENT_H

#include "student.h"
#include "course.h"

typedef struct enrolment_t* p_enrolment_t;

typedef struct enrolment_t {
    course_t *course;
    student_t *student;
}enrolment_t;

enrolment_t * constructEnrolment(course_t *course, student_t *student);
void destroyEnrolment(enrolment_t *enrolment);
void setEnrolmentCourse(enrolment_t *enrolment, course_t *course);
void setEnrolmentStudent(enrolment_t *enrolment, student_t *student);
course_t * getCourseOfEnrolment(enrolment_t *enrolment);
student_t * getStudentOfEnrolment(enrolment_t *enrolment);
void printEnrolmentInformation(enrolment_t *enrolment);
p_list_t create_enrolment_list();
p_list_t get_enrolment_list();
void remove_enrolment_from_list(p_enrolment_t enrolment);
void add_enrolment_to_list(p_enrolment_t enrolment);





#endif //ESW_ASSIGNMENT_ENROLMENT_H
