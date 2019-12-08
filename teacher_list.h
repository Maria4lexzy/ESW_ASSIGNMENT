#pragma once
#include "teacher.h"

void add_teacher(p_teacher_t teacher);
p_teacher_t get_teacher(int teacher_no);
void remove_teacher_from_list(p_teacher_t teacher);
plist_t get_teacher_list();
plist_t create_teacher_list();
