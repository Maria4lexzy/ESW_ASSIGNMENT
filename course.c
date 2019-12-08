//
// Created by Alicja Siudak on 03/12/2019.
//
#include <string.h>
#include <stdio.h>
#include "course.h"
#include "linked_list.h"
#include <malloc.h>
#pragma warning(disable : 4996)

static plist_t course_list;

plist_t create_course_list(){
    course_list = creatae_linked_list();
    return course_list;
}

p_course_t create_course(int course_no, char *course_name, int semester_no){
    p_course_t course = (course_t*)malloc(sizeof(course_t));
    if(course == NULL){
        return NULL;
    }
    else{
        course->course_no=course_no;
        course->course_name = strdup(course_name);
        course->semester_no=semester_no;
        return course;
    }
}

void destroy_course(p_course_t course){
    free(course->course_name);
    char *course_name = NULL;
    free(course);
}

void set_coure_num(p_course_t course, int course_no){
    course->course_no = course_no;
}
void set_course_name(p_course_t course, char *course_name){
    course->course_name=course_name;
}
void set_semester_num(p_course_t course, int semester_no){
    course->semester_no = semester_no;
}
int getCourseNo(p_course_t course){
    return course->course_no;
}
char * getCourseName(p_course_t course){
    return course->course_name;
}
int get_semeter_num(p_course_t course){
    return course->semester_no;
}
void print_Course_Information(p_course_t course){
    printf("C \t %s\t %d\t %d\n", course->course_name, course->course_no, course->semester_no);
}

void add_course(p_course_t course){
	if (course_list == NULL) {
		course_list = create_course_list();
	}
    add_item_to_list(course_list, course);
}

void remove_course_from_list(p_course_t course){
    remove_item_from_list(course_list, course);
}


p_course_t get_course_from_list(int course_no)
{
	for (int i = 0; i < size(course_list); i++) {
		p_course_t course = get_element_from_list(course_list, i);
		if (course->course_no == course_no) {
			return course;
		}
	}
	return NULL;
}

plist_t get_course_list(){
    return course_list;
}




