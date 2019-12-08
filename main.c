#include <stdio.h>
#include "main.h"
#include "enrolment.h"
#include "read_txt/read_data.h"
#include "linked_list.h"
#include "student.h"
#include "assignment.h"
#include "enrolment.h"


int main(void) {
	printf("\n");
	read_data_from_file("course_database.txt");
	get_students_enrolled_in_course(get_course_from_list(11));
	print_students();
	get_courses_list_by_teacher(get_teacher(123456));
	get_courses_by_student(get_student(123456));
	get_teachers_by_student(get_student(123456));
	print_enrolments();
	remove_student_from_list(get_student(123456));
	print_enrolments();
}

void get_students_enrolled_in_course(p_course_t course)
{
	printf("\t\tStudents enrolled in %s\n\n", get_course_name(course));
	plist_t enrolment_list = get_enrolment_list();
	for (int i = 0; i < size(enrolment_list); i++) {
		p_enrolment_t enrolment = get_element_from_list(enrolment_list, i);
		if (get_course_of_enrolment(enrolment) == course) {
			print_student_info(get_student_of_enrolment(enrolment));
		}
	}
	print_divider();
}

void get_courses_list_by_teacher(p_teacher_t teacher) {
	printf("\t\tCourses assigned to %s\n\n", get_teacher_name(teacher));
	plist_t assignment_list = get_assignment_list();
	for (int i = 0; i < size(assignment_list); i++) {
		p_assignment_t assignment = get_element_from_list(assignment_list, i);
		if (get_teacher_assignment(assignment) == teacher) {
			print_course_info(get_course_assignment(assignment));
		}
	}
	print_divider();
}

void get_courses_by_student(p_student_t student) {
	printf("\t\tCourses enrolled by %s\n\n", get_student_name(student));
	plist_t enrolment_list = get_enrolment_list();
	for (int i = 0; i < size(enrolment_list); i++) {
		p_enrolment_t enrolment = get_element_from_list(enrolment_list, i);
		if (get_student_of_enrolment(enrolment) == student) {
			print_course_info(get_course_of_enrolment(enrolment));
		}
	}
	print_divider();
}

void get_teachers_by_student(p_student_t student) {
		printf("\n----------------------HARD CODED QUERY------------------------\n");

	printf("\t\t%s had the following teachers:\n\n", get_student_name(student));
	plist_t enrolment_list = get_enrolment_list();
	plist_t assignment_list = get_assignment_list();
	for (int i = 0; i < size(enrolment_list); i++) {
		p_enrolment_t enrolment = get_element_from_list(enrolment_list, i);
		if (get_student_of_enrolment(enrolment) == student){
			for (int j = 0; j < size(assignment_list); j++) {
				p_assignment_t assignment = get_element_from_list(assignment_list, j);
				if (get_course_assignment(assignment)==get_course_of_enrolment(enrolment)) {
					print_teacher_info(get_teacher_assignment(assignment));
				}
			}
		}
	}
	print_divider();
}


void print_students() {
	printf("\t\tStudents\n\n");
	plist_t alfred = get_student_list();
	for (int i = 0; i < size(alfred); i++) {
		p_student_t student = get_element_from_list(get_student_list(), i);
		print_student_info(student);
	}
	print_divider();
}

void print_enrolments() {
	printf("\t\tEnrollments\n\n");
	for (int i = 0; i < size(get_enrolment_list()); i++) {
		p_enrolment_t enrolment = get_element_from_list(get_enrolment_list(), i);
		print_enrolment_info(enrolment);
	}
	print_divider();
}

void print_divider() {
	printf("\n------------------------------------------------------------\n");
}

	
