#include <stdio.h>
#include "teacher.h"
#include "teacher_list.h"

#pragma warning(disable : 4996)

static plist_t teacher_list;


plist_t create_teacher_list() {
	teacher_list = creatae_linked_list();
	return teacher_list;
}


void add_teacher(p_teacher_t teacher) {
	if (teacher_list == NULL) {
		teacher_list = create_teacher_list();
	}
	add_item_to_list(teacher_list, teacher);
}

p_teacher_t get_teacher(int teacher_no)
{
	for (int i = 0; i < size; i++) {
		if (((p_teacher_t)get_element_from_list(teacher_list, i))->teacher_no == teacher_no) {
			return ((p_teacher_t)get_element_from_list(teacher_list, i));
		}
	}
	return NULL;
}

void remove_teacher_from_list(p_teacher_t teacher) {
	remove_item_from_list(teacher_list, teacher);
}

plist_t get_teacher_list() {
	return teacher_list;
}


