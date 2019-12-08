
#include <string.h>
#include <stdio.h>
#include "course.h"
#include "linked_list.h"
#include <malloc.h>
#pragma warning(disable : 4996)


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
int get_course_num(p_course_t course){
    return course->course_no;
}
char * get_course_name(p_course_t course){
    return course->course_name;
}
int get_semeter_num(p_course_t course){
    return course->semester_no;
}
void print_course_info(p_course_t course){
    printf("\t\tC \t %s\t %d\t %d\n", course->course_name, course->course_no, course->semester_no);
}




