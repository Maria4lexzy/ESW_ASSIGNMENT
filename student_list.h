#pragma once
#include "student.h"

typedef struct student_list_t* p_student_list_node;
typedef struct student_list_t
{
	pstudent_t el_student;
	p_student_list_node next;
}student_list_t;


pstudent_t get_student_by_index(uint16_t index);

pstudent_t get_student_by_stuent_number(pstudent_t student_value);

int no_of_students();

int remove_student_from_list(pstudent_t student_value);

int add_student_to_list(pstudent_t student_value);

void setStudentListSize(uint16_t listSize);

int getStudentListSize();

void printStudentList();




