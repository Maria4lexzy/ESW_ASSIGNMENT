#include <stdio.h>
#include "student.h"
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

//creating student - return 0 if success, else -1
pstudent_t create_student(int student_num, char* first_name) 
{
	pstudent_t studentV = ((pstudent_t)malloc(sizeof(student_t)));
	if (studentV == NULL) {
		return NULL;
	}
	else {
		studentV->student_num = student_num;
		studentV->first_name = first_name;
		return studentV;
	}
}
int get_student_numb(student_t self) 
{
	return self.student_num;
}

char* get_student_name(student_t self) 
{
	return self.first_name;
}

void destroy_student(pstudent_t self) 
{
	free(self);
	self = NULL;
}

void print_student_info(pstudent_t self) 
{
	printf("S \t %d\t %s\n", self->student_num, self->first_name);
}