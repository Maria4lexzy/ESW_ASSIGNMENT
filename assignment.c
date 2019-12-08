
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "assignment.h"
#include "course.h"
#include "teacher.h"


static plist_t assignment_list;

plist_t create_assignment_list() {
	assignment_list = creatae_linked_list();
	return assignment_list;
}

p_assignment_t create_assignment(p_course_t course, p_teacher_t teacher) {
	p_assignment_t assignment = (p_assignment_t)malloc(sizeof(assignment_t));
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

void destroy_assignment(p_assignment_t assignment) {
	free(assignment);
	assignment = NULL;
}
void set_course_to_assignment(p_assignment_t assignment, p_course_t course) {
	assignment->course = course;
}
void set_teacher_to_assignment(p_assignment_t assignment, p_teacher_t teacher) {
	assignment->teacher = teacher;
}

p_course_t get_course_assignment(p_assignment_t assignment) {
	return assignment->course;
}
p_teacher_t get_teacher_assignment(p_assignment_t assignment) {
	return assignment->teacher;
}
void print_assignment_info(p_assignment_t assignment) {
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

plist_t get_assignment_list() {
	return assignment_list;
}