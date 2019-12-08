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
	p_list_t enrolment_list = get_enrolment_list();
	for (int i = 0; i < no_of_items_in_list(enrolment_list); i++) {
		p_enrolment_t enrolment = get_element_from_list(enrolment_list, i);
		if (getCourseOfEnrolment(enrolment) == course) {
			print_Student_Information(getStudentOfEnrolment(enrolment));
		}
	}
	printLine();
}

void print_students() {
	printf("Students\n\n");
	p_list_t alfred= get_student_list();
	for (int i = 0; i < no_of_items_in_list(alfred); i++) {
		student_t* student = get_element_from_list(get_student_list(), i);
		print_Student_Information(student);
	}
	printLine();
}

void print_enrolments() {
	printf("Enrollments\n\n");
	for (int i = 0; i < no_of_items_in_list(get_enrolment_list()); i++) {
		enrolment_t* enrolment = get_element_from_list(get_enrolment_list(), i);
		printEnrolmentInformation(enrolment);
	}
	printLine();
}

void get_courses_list_by_teacher(teacher_t* teacher) {
	printf("Courses assigned to %s\n\n", getTeacherFName(teacher));
	p_list_t assignment_list = get_assignment_list();
	for (int i = 0; i < no_of_items_in_list(assignment_list); i++) {
		p_assignment_t assignment = get_element_from_list(assignment_list, i);
		if (getAssignmentTeacher(assignment) == teacher) {
			print_Course_Information(getAssignmentCourse(assignment));
		}
	}
	printLine();
}


void get_courses_by_student(student_t* student) {
	printf("Courses enrolled by %s\n\n", getStudentFName(student));
	p_list_t enrolment_list = get_enrolment_list();
	for (int i = 0; i < no_of_items_in_list(enrolment_list); i++) {
		p_enrolment_t enrolment = get_element_from_list(enrolment_list, i);
		if (getStudentOfEnrolment(enrolment) == student) {
			print_Course_Information(getCourseOfEnrolment(enrolment));
		}
	}
	printLine();
}


void get_teachers_by_student(student_t* student) {
	printf("Teacher teaching %s (hard)\n\n", getStudentFName(student));
	p_list_t enrolment_list = get_enrolment_list();
	p_list_t assignment_list = get_assignment_list();
	for (int i = 0; i < no_of_items_in_list(enrolment_list); i++) {
		p_enrolment_t enrolment = get_element_from_list(enrolment_list, i);
		if (getStudentOfEnrolment(enrolment) == student){
			for (int j = 0; j < no_of_items_in_list(assignment_list); j++) {
				p_assignment_t assignment = get_element_from_list(assignment_list, j);
				if (getAssignmentCourse(assignment)==getCourseOfEnrolment(enrolment)) {
					print_Teacher_Information(getAssignmentTeacher(assignment));
				}
			}
		}
	}
	printLine();
}
	


int main(void) {
	printLine();
	read_from_file("CMakeLists.txt");
	get_students_enrolled_in_course(get_course_from_list(21));
	print_students();
	get_courses_list_by_teacher(get_teacher_from_list(123456));
	get_courses_by_student(get_student_from_list(654321));
	get_teachers_by_student(get_student_from_list(123456));
	print_enrolments();
	remove_student_from_list(get_student_from_list(654321));
	print_enrolments();
}
