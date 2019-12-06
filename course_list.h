#pragma once
#include "course.h"


struct course_list
{
	pcourse_t* el_course;
	struct pcourse_t* next_course;
};
typedef struct course_list course_list_node;

pcourse_t* get_course_by_index(uint16_t index);

pcourse_t* get_course_by_course_number(pcourse_t* course_value);

int no_of_courses();

int remove_course_from_list(pcourse_t* course_value);

int add_course_to_list(pcourse_t* course_value);

void setCourseListSize(uint16_t listSize);

int getCourseListSize();

void printCourseList();




