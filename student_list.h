#pragma once
#include "student.h"
#include "stdint.h"
struct student_list
{
	void* student;
	student_list_node* next;
};
typedef struct student_list student_list_node;


void* get_student_from_list(uint16_t index);

int no_of_students();

int remove_student_from_list(void* student);

int add_student_to_list(void* student);




