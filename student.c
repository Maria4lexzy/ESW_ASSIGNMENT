#include <stdio.h>
#include "student.h"
struct student {
	int student_num;
int first_name;
student_t next;
};

student_t create_student(int student_num, char* first_name) {

}
int get_student_numb(student_t s_num) {
}

char* get_student_name(student_t s_name) {
}
void destroy_student(student_t student) {
}
//we maybe need this
student_t get_next_student_address(student_t self) {}
void set_next_student_address(student_t self, student_t next) {}