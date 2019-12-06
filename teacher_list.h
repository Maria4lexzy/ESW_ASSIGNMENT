#pragma once
#include "teacher.h"

struct teacher_list
{
	pteacher_t* el_teacher;
	struct teacher_list_node* next_teacher;
};
typedef struct teacher_list teacher_list_node;

pteacher_t* get_teacher_by_index(uint16_t index);
pteacher_t* get_teacher_by_teacher_number(pteacher_t* teacher_value);

int no_of_teachers();
int remove_teacher_from_list(pteacher_t* teacher_value);
int add_teacher_to_list(pteacher_t* teacher_value);
void set_teacher_list_size(uint16_t listSize);
int get_teacher_list_size();
void print_teacher_list();