#include <stdio.h>
#include "assignment.h"
#include <malloc.h>

struct assignment{
int teacher_num;
int course_num;
assignment_t next; };

// Constructor
assignment_t create_assignment(int teacher_number, int course_number) {
	assignment_t new_assignment = (assignment_t)malloc(sizeof(struct assignment));

}

void destroy_assignment(assignment_t self) {}

int get_assigned_teacher_num(assignment_t self) {}

int get_assigned_course_num(assignment_t self) {}
assignment_t getNextAssignmentAddress(assignment_t self) {}
void setNexAddress(assignment_t self, assignment_t next) {}


