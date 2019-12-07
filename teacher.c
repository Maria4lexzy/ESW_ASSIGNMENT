#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "teacher.h"

pteacher_t create_teacher(int teacher_num, char* first_name) {
	pteacher_t teacherV = ((pteacher_t)malloc(sizeof(teacher_t)));
	if (teacherV == NULL) {
		return NULL;
	}
	else {
		teacherV->teacher_no = teacher_num;
		teacherV->f_name = first_name;
		return teacherV;
	}
}
int get_teacherNo(teacher_t self)
{
	return self.teacher_no;
}

char* get_teacher_name(teacher_t self)
{
	return self.f_name;
}

void destroy_teacher(pteacher_t self)
{
	free(self);
	self = NULL;
}


void print_teacher_info(teacher_t teacher) {

	printf("T \t %s\t %d\n", teacher.f_name, teacher.teacher_no);
}