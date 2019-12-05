#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef struct course_t* pcourse_t;

typedef struct course_t {
	//C course_number course_name semester_number
	int course_num;
	char* course_name;
	int semester_num;
	//	pcourse_t next;
}course_t;

pcourse_t createCourse(int course_num, char* course_name, int semester_no);
void destroy_course(pcourse_t course);
void set_cours_num(pcourse_t course, int course_num);
void set_course_name(pcourse_t course, char* course_name);
void set_semester_num(pcourse_t course, int semester_num);
int get_course_num(pcourse_t course);
char get_course_name(pcourse_t course);
int get_semester_num(pcourse_t course);
void print_course_info(pcourse_t course);