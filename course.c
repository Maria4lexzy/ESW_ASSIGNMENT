#include <stdio.h>
#include <malloc.h>
#include "course.h"
#include <string.h>
#include <stdlib.h>

pcourse_t* create_course(int course_no, char* course_name, int semester_no)
{
	pcourse_t* courseV = ((pcourse_t*)malloc(sizeof(pcourse_t)));
	if (courseV == NULL) {
		return NULL;
	}
	else {
		courseV->course_num = course_no;
		courseV->course_name = course_name;
		courseV->semester_num = semester_no;
		return courseV;
	}
}

void destroy_course(pcourse_t* course)
{
	free(course);
	course = NULL;
}

int get_course_num(pcourse_t course)
{
	return course.course_num;
}
char* get_course_name(pcourse_t course)
{
	return course.course_name;
}
int get_semester_num(pcourse_t course)
{
	return course.semester_num;
}
void print_course_info(pcourse_t* course) 
{
	printf("T \t %d\t %s \t %d\n", course->semester_num, course->course_name, course->course_num);
}
