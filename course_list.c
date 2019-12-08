#include <stdio.h>
#include "course_list.h"


static plist_t course_list;
#pragma warning(disable : 4996)

plist_t create_course_list() {
	course_list = creatae_linked_list();
	return course_list;
}

void add_course(p_course_t course) {
	if (course_list == NULL) {
		course_list = create_course_list();
	}
	add_item_to_list(course_list, course);
}

void remove_course_from_list(p_course_t course) {
	remove_item_from_list(course_list, course);
}


p_course_t get_course_from_list(int course_no)
{
	for (int i = 0; i < size(course_list); i++) {
		p_course_t course = get_element_from_list(course_list, i);
		if (course->course_no == course_no) {
			return course;
		}
	}
	return NULL;
}

plist_t get_course_list() {
	return course_list;
}
