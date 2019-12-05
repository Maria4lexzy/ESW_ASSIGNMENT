#pragma once
#include "student.h"

typedef struct student_list* pstudent_list_t;

struct student_list_t{
   //plist_t list;
} student_list_t;
pstudent_list_t student_list_create();

pstudent_t get_student_from_list(pstudent_list_t self, int i);

int no_of_students(pstudent_list_t self);

int remove_student_from_list(pstudent_list_t self, pstudent_t student);

int add_student_to_list(pstudent_list_t self, pstudent_t student);

void student_list_destroy(pstudent_list_t self);



