#pragma once
#include "linked_list.h"
#include "course.h"
#include "teacher.h"
#include "assignment.h"
#include "student.h"

void get_students_enrolled_in_course(p_course_t course);

void get_courses_list_by_teacher(p_teacher_t teacher);

void get_courses_by_student(p_student_t student);

void get_teachers_by_student(p_student_t student);

void print_divider();

void print_students();

void print_enrolments();
