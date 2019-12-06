#include <stdio.h>
#include "student.h"
#include "student_list.h"
#include "teacher.h"
#include "teacher_list.h"

void main() {
	//list size for all list
	int nrOfItems;
	//creating student list

	printf("Enter total number students: ");
	scanf_s("%d", &nrOfItems);
	setStudentListSize(nrOfItems);
	
	//creating teacher list
	set_teacher_list_size(nrOfItems);
	//adding student
	add_student_to_list(create_student(123461, "Jakub"));
	add_student_to_list(create_student(723462, "Feri"));
	
	//adding teacher
	add_teacher_to_list(create_teacher(123461, "Jakubino"));
	add_teacher_to_list(create_teacher(723462, "Ferino"));

	//checking student functionality
	printStudentList(); //printing out all items from the linkedList
	pstudent_t* student_val= get_student_by_index(0);
	printf("0 POS: %d   %s ", student_val->student_num,student_val->first_name);
	student_val = get_student_by_stuent_number(student_val);
	printf("0 POS: %d   %s ", student_val->student_num, student_val->first_name);
	remove_student_from_list(student_val);
	destroy_student(student_val);
	printStudentList();

	//checking teacherfunctionality
	print_teacher_list(); //printing out all items from the linkedList
	pteacher_t* teacher_val = get_teacher_by_index(0);
	printf("0 POS: %d   %s ", teacher_val->teacher_no, teacher_val->f_name);
	teacher_val = get_teacher_list_size(teacher_val);
	printf("0 POS: %d   %s ", teacher_val->teacher_no, teacher_val->f_name);
	remove_teacher_from_list(teacher_val);
	destroy_teacher(teacher_val);
	print_teacher_list();




}
