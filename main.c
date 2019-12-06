#include <stdio.h>
#include "student.h"
#include "student_list.h"


void main() {

	//creating list
	int nrOfItems;
	printf("Enter total number students: ");
	scanf_s("%d", &nrOfItems);
	setStudentListSize(nrOfItems);

	//adding student
	add_student_to_list(create_student(123456, "Jakub"));

	//checking functionality
	printStudentList(); //printing out all items from the linkedList
	pstudent_t* student_val= get_student_by_index(0);
	printf("0 POS: %d   %s ", student_val->student_num,student_val->first_name);
	student_val = get_student_by_stuent_number(student_val);
	printf("0 POS: %d   %s ", student_val->student_num, student_val->first_name);


}
