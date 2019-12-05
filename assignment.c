#include <stdio.h>
#include "assignment.h"
#include <malloc.h>
#include "course.h"
#include "teacher.h"



passignment_t create_assignment(pcourse_t course, pteacher_t teacher){}
void destroy_assignment(passignment_t assignment){}
void set_assignment_course(passignment_t assignment, pcourse_t course){}
void set_assignment_teacher(passignment_t assignment, pteacher_t teacher){}
pcourse_t get_assignment_course(passignment_t assignment){}
pteacher_t get_assignment_teacher(passignment_t assignment) {
	
}
void print_assignment_info(passignment_t assignment){
	printf("A \t %d\t %d\n", assignment->teacher->teacher_num ,assignment->course->course_num);
}


