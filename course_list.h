#pragma once
#include "linked_list.h"
#include "course.h"


plist_t create_course_list();
void remove_course_from_list(p_course_t course);
p_course_t get_course_from_list(int course_no);
void add_course(p_course_t course);
plist_t get_course_list();