#include <stdio.h>
#include "course.h"



pcourse_t createCourse(int course_no, char* course_name, int semester_no){}
void destroy_course(pcourse_t course){}
void set_cours_num(pcourse_t course, int course_num){}
void set_course_name(pcourse_t course, char* course_name){}
void set_semester_num(pcourse_t course, int semester_num){}
int get_course_num(pcourse_t course){}
char get_course_name(pcourse_t course){}
int get_semester_num(pcourse_t course){}
void print_course_info(pcourse_t course) {
	printf("T \t %s\t %d\n", course->course_name, course->course_num);

}
