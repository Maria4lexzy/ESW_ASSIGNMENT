#include "student_list.h"
#include <malloc.h>
#include "student.h"
#include <stdio.h>

student_list_node* head = NULL;
student_list_node* current = NULL;
uint16_t number_of_nodes = 0;
uint16_t list_size = 0;

int setStudentListSize(uint16_t listSize) {
	list_size = listSize;
}

int getStudentListSize() {
	if (list_size != NULL)
		return list_size;
	else
		return 0;
}

void* get_student_by_index(uint16_t index)
{
	if (number_of_nodes && index >= 0 && index < number_of_nodes)
	{
		student_list_node* headTemp = head;				// starting from first node
		if (index == 0)
			return headTemp;
		else
			for (uint16_t i = 0; i < index; i++)
				headTemp = headTemp->next;	// moving to next node

		return headTemp;							// returning wanted item
	}
	return NULL;
}

void* get_student_by_stuent_number(void* student)
{
	if (number_of_nodes >= 0 && student != NULL)
	{
		student_list_node* headTemp = head;				// starting from first node

		for (uint16_t i = 0; i < number_of_nodes; i++)
		{
			if (((pstudent_t*)headTemp->student)->student_num == ((pstudent_t*)student)->student_num) //check if student numbers match
				return headTemp->student;
			headTemp = headTemp->next;
		}
	}
	return NULL;
}

int no_of_students()
{
	
}

void student_list_destroy()
{

}

int remove_student_from_list(void* student)
{
	
}

int add_student_to_list(void* student)
{
	student_list_node* new_node = NULL;
	if (student == NULL)
		return -1;
	else if (!number_of_nodes && list_size >= 1)	// if no items in the linked list exists then we create the first one which has a special process different from the others to follow
	{
		new_node->student = student;
		new_node->next = NULL;
		head = new_node;
		current = new_node;
		number_of_nodes++;
		return 0;
	}
	else if (number_of_nodes < list_size)
	{
		new_node->student = student;
		new_node->next = NULL;
		current->next = new_node;					// set previous item in the linkedList point to the newely created item
		current = current->next;
		current->next = NULL;						// we move the permanent pointer to the newely created item in the linked list										
		number_of_nodes++;

		return 0;
	}
	else
		return -1;
}