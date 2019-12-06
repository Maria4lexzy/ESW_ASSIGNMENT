#include <stdio.h>
#include "student.h"
#include "student_list.h"
#include "course.h"
#include "course_list.h"


void main() {

	//creating list
	int nrOfItems;
	printf("Enter total number students: ");
	scanf_s("%d", &nrOfItems);
	setStudentListSize(nrOfItems);

	//adding student
	add_student_to_list(create_student(123456, "Jakub"));
	add_student_to_list(create_student(723456, "Feri"));

	//checking functionality
	printStudentList(); //printing out all items from the linkedList
	pstudent_t* student_val= get_student_by_index(0);
	printf("0 POS: %d   %s ", student_val->student_num,student_val->first_name);
	student_val = get_student_by_stuent_number(student_val);
	printf("0 POS: %d   %s ", student_val->student_num, student_val->first_name);
	remove_student_from_list(student_val);
	destroy_student(student_val);
	printStudentList();



	//creating list course
	int nrOfItems_course;
	printf("Enter total number courses: ");
	scanf_s("%d", &nrOfItems_course);
	setCourseListSize(nrOfItems_course);
	add_course_to_list(create_course(123456, "Jakub", 12));
	add_course_to_list(create_course(123456, "Feri", 12));
	//checking functionality course
	printCourseList(); //printing out all items from the linkedList
	/*pcourse_t* course_val = get_course_by_index(0);
	print_course_info(course_val);
	course_val = get_course_by_course_number(course_val);
	print_course_info(course_val);
	destroy_course(course_val);
	printCourseList();*/




}
