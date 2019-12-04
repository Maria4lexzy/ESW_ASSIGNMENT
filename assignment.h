#pragma once
#include <stdio.h>
#include <stdbool.h>

//pointer type
typedef struct assignment* assignment_t;

// Constructor
assignment_t create_assignment(int teacher_number, int course_number);

void destroy_assignment(assignment_t self);

int get_assigned_teacher_num(assignment_t self);

int get_assigned_course_num(assignment_t self);
assignment_t getNextAssignmentAddress(assignment_t self);
void setNexAddress(assignment_t self, assignment_t next);