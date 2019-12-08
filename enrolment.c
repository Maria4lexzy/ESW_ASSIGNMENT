//
// Created by Alicja Siudak on 03/12/2019.
//
#include <string.h>
#include "course.h"
#include "student.h"
#include "enrolment.h"
#include "linked_list.h"
#include <stdio.h>
#include <malloc.h>
static plist_t enrolment_list;

p_enrolment_t create_enrolment(p_course_t course, p_student_t student){
    p_enrolment_t enrolment = (p_enrolment_t)malloc(sizeof(enrolment_t));
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
void destroy_enrolment(p_enrolment_t enrolment){
    free(enrolment);
}
void set_course_to_enrolment(p_enrolment_t enrolment, p_course_t course){
    enrolment->course = course;
}
void set_student_to_enrolment(p_enrolment_t enrolment, p_student_t student){
    enrolment->student = student;
}
p_course_t get_course_of_enrolment(p_enrolment_t enrolment){
    return enrolment->course;
}
p_student_t get_student_of_enrolment(p_enrolment_t enrolment){
    return enrolment->student;
}
void print_enrolment_info(p_enrolment_t enrolment){
    printf("\t\tE \t %d\t %d\n", enrolment->student->student_no, enrolment->course->course_no);
}

plist_t create_enrolment_list()
{
	enrolment_list = creatae_linked_list();
	return enrolment_list;
}

plist_t get_enrolment_list()
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


