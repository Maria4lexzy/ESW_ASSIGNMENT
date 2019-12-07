#include <stdio.h>
#include "student_list.h"
#include <malloc.h>
#include "student.h"

p_student_list_node head = NULL;
p_student_list_node current = NULL;
uint16_t number_of_nodes = 0;
uint16_t list_size = 0;

void printStudentList() {

	p_student_list_node tempP = (p_student_list_node)malloc(sizeof(student_list_t));
	tempP = head;
	printf("The list contains: (");
	int temp_no_of_nodes = number_of_nodes;
	while (tempP && temp_no_of_nodes > 0)
	{
		pstudent_t student_value = (p_student_list_node)tempP->el_student;
		printf("[%d \t %s]", student_value->student_num, student_value->first_name);
		tempP = (p_student_list_node)(tempP->next);	//shifting to the next node in the linked list
		temp_no_of_nodes--;
	}
	free(tempP);
	tempP = NULL;
	printf(")\n");
}

void setStudentListSize(uint16_t listSize) {
	list_size = listSize;
}

int getStudentListSize() {
	if (list_size != 0)
		return list_size;
	else
		return 0;
}

pstudent_t get_student_by_index(uint16_t index)
{
	if (number_of_nodes && index >= 0 && index < number_of_nodes)
	{
		p_student_list_node headTemp = head;				// starting from first node
		if (index == 0)
			return headTemp->el_student;
		else
			for (uint16_t i = 0; i < index; i++)
				headTemp = (p_student_list_node )(headTemp->next);	// moving to next node

		return headTemp->el_student;							// returning wanted item
	}
	return NULL;
}

pstudent_t get_student_by_stuent_number(pstudent_t student_value )
{
	if (number_of_nodes >= 0 && student_value != NULL)
	{
		p_student_list_node headTemp = head;				// starting from first node

		for (uint16_t i = 0; i < number_of_nodes; i++)
		{
			if (headTemp->el_student->student_num == student_value->student_num) //check if student numbers match
				return headTemp->el_student;

			headTemp = (p_student_list_node)headTemp->next;
		}
	}
	return NULL;
}

int no_of_students()
{
	return number_of_nodes;
}

int add_student_to_list(pstudent_t student_value)
{
	p_student_list_node new_node = (p_student_list_node)malloc(sizeof(student_list_t));
	if (student_value == NULL)
		return -1;
	else if (!number_of_nodes && list_size >= 1 && new_node)	// if no items in the linked list exists then we create the first one which has a special process different from the others to follow
	{
		new_node->el_student = student_value;
		new_node->next = NULL;
		head = new_node;
		current = new_node;
		number_of_nodes++;
		return 0;
	}
	else if (number_of_nodes < list_size && new_node)
	{
		new_node->el_student = student_value;
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

int remove_student_from_list(pstudent_t student_value)
{
	p_student_list_node new_node = (p_student_list_node)malloc(sizeof(student_list_t));
	p_student_list_node headTemp = head;
	if (student_value == NULL)
		return -1;

	/* if the node is the first node */
	if (headTemp->el_student->student_num == student_value->student_num)
		return remove_first(head);

	/* if the node is in the middle */
	while (headTemp != NULL)
	{
		if (headTemp->el_student->student_num == student_value->student_num)
			break;
		headTemp = headTemp->next;
	}

	/* if the node is the last node */
	if (headTemp->next == NULL)
		return remove_last(head);

	if (headTemp != NULL)
	{
		p_student_list_node tmp = headTemp->next;
		headTemp->next = tmp->next;
		tmp->next = NULL;
		free(tmp);
	}
	number_of_nodes--;
	return 0;
}
//remove node from the front of list(return 0 if succes, else -1)
int remove_first(p_student_list_node headValue)
{
	if (headValue == NULL)
		return NULL;
	p_student_list_node front = headValue;
	headValue = headValue->next;
	front->next = NULL;
	if (front == headValue)//check if it is the last node in the list
	{
		headValue = NULL;
	}
	free(front);
	number_of_nodes--;
	head = headValue;
	return 0;
}

//remove node from the back of the list(return 0 if succes, else -1)
int remove_last(p_student_list_node headValue)
{
	if (headValue == NULL)
		return -1;
	p_student_list_node cursor = headValue;
	p_student_list_node back = NULL;
	while (cursor->next != NULL)
	{
		back = cursor;
		cursor = cursor->next;
	}
	if (back != NULL)
		back->next = NULL;
	/* if this is the last node in the list*/
	if (cursor == headValue)
		headValue = NULL;
	free(cursor);
	head = headValue;
	number_of_nodes--;
	return 0;
}