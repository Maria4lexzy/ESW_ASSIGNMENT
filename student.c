#include <stdio.h>
#include "student.h"

//creating student - return 0 if success, else -1
pstudent_t* create_student(int student_num, char* first_name) {
	pstudent_t* student = (pstudent_t*)malloc(sizeof(pstudent_t));
	if (student == NULL) {
		return NULL;
	}
	else {
		student->student_num = student_num;
		student->first_name = first_name;
		return student;
	}
}
int get_student_numb(pstudent_t self) 
{
	return self.student_num;
}

char* get_student_name(pstudent_t self) 
{
	return self.first_name;
}

void destroy_student(pstudent_t* self) 
{
	free(self);
	self = NULL;
}

void print_student_info(pstudent_t self) {

	printf("S \t %s\t %d\n", self.student_num, self.first_name);
}