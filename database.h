#pragma once
#include "linked_list.h"
#include "course.h"
#include "teacher.h"
#include "assignment.h"
#include "student.h"

void get_students_enrolled_in_course(course_t* course);

void get_courses_list_by_teacher(teacher_t* teacher);

void get_courses_by_student(student_t* student);

void get_teachers_by_student(student_t* student);