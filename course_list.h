#pragma once
#include "course.h"


typedef struct course_list_t
{
	pcourse_t el_course;
	pcourse_t next_course;
} course_list_t;
typedef struct course_list_t* p_course_list_node;

pcourse_t get_course_by_index(uint16_t index);

pcourse_t get_course_by_course_number(pcourse_t course_value);

int no_of_courses();

int remove_course_from_list(pcourse_t course_value);

int add_course_to_list(pcourse_t course_value);

void setCourseListSize(uint16_t listSize);

int getCourseListSize();

void printCourseList();




