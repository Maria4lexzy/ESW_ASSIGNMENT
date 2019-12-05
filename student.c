#include <stdio.h>
#include "student.h"


pstudent_t create_student(int student_num, char* first_name) {
	pstudent_t student = (pstudent_t)malloc(sizeof(student_t));
	if (student == NULL) {
		return NULL;
	}
	else {
		student->student_ = student_no;
		student->f_name = strdup(f_name);
		return student;
	}
}
int get_student_numb(student_t self) {
}

char* get_student_name(student_t self) {
}
void destroy_student(student_t self) {
}
//we maybe need this
student_t get_next_student_address(student_t self) {}
void set_next_student_address(student_t self, student_t next) {}