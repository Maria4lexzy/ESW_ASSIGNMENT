//
// Created by Alicja Siudak on 03/12/2019.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linked_list.h"
#include "student.h"
#include "enrolment.h"

#pragma warning(disable : 4996)

static p_list_t student_list;

p_list_t create_student_list(){
    student_list = linked_list_create();
    return student_list;
}

p_student_t createStudent(int student_no, char* f_name){
	p_student_t student = (p_student_t)malloc(sizeof(student_t));
    if(student == NULL){
        return NULL;
    }
    else{
        student->student_no=student_no;
        student->f_name = strdup(f_name);
        return student;
    }
}

void destroyStudent(p_student_t student){
    free(student->f_name);
    //make sure nobody will use it
    char* f_name = NULL;
    free(student);
}

void setStudentNo(p_student_t student, int student_no){
    student->student_no=student_no;
}

void setStudentFName(p_student_t student, char* f_name){
    student->f_name = f_name;
}

int getStudentNo(p_student_t student){
    return student->student_no;
}

char* getStudentFName(p_student_t student){
    return student->f_name;
}

void print_Student_Information(p_student_t student)
{
    printf("S \t %s\t %d\n", student->f_name, student->student_no);
}

student_t* get_student_from_list(int student_no)
{
	for (int i = 0; i < no_of_items_in_list(student_list); i++) {
		if (((p_student_t)get_element_from_list(student_list, i))->student_no == student_no) {
			return ((p_student_t)get_element_from_list(student_list, i));
		}
	}
	return NULL;
}

void add_student_to_list(p_student_t student){
if(student_list == NULL){
    student_list = create_student_list();
}
    add_item_to_list(student_list, student);
}

void remove_student_from_list(p_student_t student){
    remove_item_from_list(student_list, student);
	p_list_t enrolments_list = get_enrolment_list();
	for (int i = 0; i < no_of_items_in_list(enrolments_list); i++) {
		p_enrolment_t enrolment = get_element_from_list(enrolments_list, i);
		if (getStudentOfEnrolment(enrolment) == student) {
			remove_enrolment_from_list(enrolment);
		}
	}
	
}

p_list_t get_student_list(){
    return student_list;
}

