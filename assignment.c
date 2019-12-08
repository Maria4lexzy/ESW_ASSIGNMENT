//
// Created by Alicja Siudak on 03/12/2019.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "assignment.h"
#include "course.h"
#include "teacher.h"


static p_list_t assignment_list;

p_list_t create_assignment_list() {
	assignment_list = linked_list_create();
	return assignment_list;
}

assignment_t* createAssignment(course_t* course, teacher_t* teacher) {
	assignment_t* assignment = (assignment_t*)malloc(sizeof(assignment_t));
	if (assignment == NULL) {
		return NULL;
	}
	else
	{
		assignment->course = course;
		assignment->teacher = teacher;
		return assignment;
	}
}

void destroyAssignment(assignment_t* assignment) {
	free(assignment);
	assignment = NULL;
}
void setAssignmentCourse(assignment_t* assignment, course_t* course) {
	assignment->course = course;
}
void setAssignmentTeacher(assignment_t* assignment, teacher_t* teacher) {
	assignment->teacher = teacher;
}

course_t* getAssignmentCourse(assignment_t* assignment) {
	return assignment->course;
}
teacher_t* getAssignmentTeacher(assignment_t* assignment) {
	return assignment->teacher;
}
void printAssignmentInformation(assignment_t* assignment) {
	printf("A \t %d\t %d\n", assignment->teacher->teacher_no, assignment->course->course_no);
}

void add_assignment_to_list(p_assignment_t assignment) {
	if (assignment_list == NULL) {
		assignment_list = create_assignment_list();
	}
	add_item_to_list(assignment_list, assignment);
}

void remove_assignment_from_list(p_assignment_t assignment) {
	remove_item_from_list(assignment_list, assignment);
}

p_list_t get_assignment_list() {
	return assignment_list;
}