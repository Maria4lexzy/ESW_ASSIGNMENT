#include <stdio.h>
#include "database.h"
#include "enrolment.h"
#include "readFromFile/readFromFile.h"
#include "linked_list.h"
#include "student.h"
#include "assignment.h"
#include "enrolment.h"

void printLine() {
	printf("\n--------------------------------\n");
}

void get_students_enrolled_in_course(course_t* course)
{
	printf("Students enrolled in %s\n\n", getCourseName(course));
	plist_t enrolment_list = get_enrolment_list();
	for (int i = 0; i < size(enrolment_list); i++) {
		p_enrolment_t enrolment = get_element_from_list(enrolment_list, i);
		if (getCourseOfEnrolment(enrolment) == course) {
			print_student_info(getStudentOfEnrolment(enrolment));
		}
	}
	printLine();
}

void print_students() {
	printf("Students\n\n");
	plist_t alfred= get_student_list();
	for (int i = 0; i < size(alfred); i++) {
		student_t* student = get_element_from_list(get_student_list(), i);
		print_student_info(student);
	}
	printLine();
}

void print_enrolments() {
	printf("Enrollments\n\n");
	for (int i = 0; i < size(get_enrolment_list()); i++) {
		enrolment_t* enrolment = get_element_from_list(get_enrolment_list(), i);
		printEnrolmentInformation(enrolment);
	}
	printLine();
}

void get_courses_list_by_teacher(teacher_t* teacher) {
	printf("Courses assigned to %s\n\n", get_teacher_name(teacher));
	plist_t assignment_list = get_assignment_list();
	for (int i = 0; i < size(assignment_list); i++) {
		p_assignment_t assignment = get_element_from_list(assignment_list, i);
		if (getAssignmentTeacher(assignment) == teacher) {
			print_Course_Information(getAssignmentCourse(assignment));
		}
	}
	printLine();
}


void get_courses_by_student(student_t* student) {
	printf("Courses enrolled by %s\n\n", get_student_name(student));
	plist_t enrolment_list = get_enrolment_list();
	for (int i = 0; i < size(enrolment_list); i++) {
		p_enrolment_t enrolment = get_element_from_list(enrolment_list, i);
		if (getStudentOfEnrolment(enrolment) == student) {
			print_Course_Information(getCourseOfEnrolment(enrolment));
		}
	}
	printLine();
}


void get_teachers_by_student(student_t* student) {
	printf("Teacher teaching %s (hard)\n\n", get_student_name(student));
	plist_t enrolment_list = get_enrolment_list();
	plist_t assignment_list = get_assignment_list();
	for (int i = 0; i < size(enrolment_list); i++) {
		p_enrolment_t enrolment = get_element_from_list(enrolment_list, i);
		if (getStudentOfEnrolment(enrolment) == student){
			for (int j = 0; j < size(assignment_list); j++) {
				p_assignment_t assignment = get_element_from_list(assignment_list, j);
				if (getAssignmentCourse(assignment)==getCourseOfEnrolment(enrolment)) {
					print_teacher_info(getAssignmentTeacher(assignment));
				}
			}
		}
	}
	printLine();
}
	


int main(void) {
	printLine();
	read_data_from_file("CMakeLists.txt");
	get_students_enrolled_in_course(get_course_from_list(21));
	print_students();
	get_courses_list_by_teacher(get_teacher(123456));
	get_courses_by_student(get_student(654321));
	get_teachers_by_student(get_student(123456));
	print_enrolments();
	remove_student_from_list(get_student(654321));
	print_enrolments();
}
