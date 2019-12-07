#include <malloc.h>
#include <stdio.h>
#include "student.h"
#include "teacher_list.h"
p_teacher_list_node head_teacher = NULL;
p_teacher_list_node current_teacher = NULL;
uint16_t number_of_nodes_teacher = 0;
uint16_t list_size_teacher = 0;

pteacher_t get_teacher_by_index(uint16_t index) {
	if (number_of_nodes_teacher && index >= 0 && index < number_of_nodes_teacher)
	{
		p_teacher_list_node headTemp = head_teacher;				// starting from first node
		if (index == 0)
			return headTemp->el_teacher;
		else
			for (uint16_t i = 0; i < index; i++)
				headTemp = (p_teacher_list_node)(headTemp->next_teacher);	// moving to next node

		return headTemp->el_teacher;							// returning wanted item
	}
	return NULL;
}
pteacher_t get_teacher_by_teacher_number(pteacher_t teacher_value) {
	if (number_of_nodes_teacher >= 0 && teacher_value != NULL)
	{
		p_teacher_list_node headTemp = head_teacher;				// starting from first node

		for (uint16_t i = 0; i < number_of_nodes_teacher; i++)
		{
			if (headTemp->el_teacher->teacher_no == teacher_value->teacher_no) //check if teacher numbers match
				return headTemp->el_teacher;
				return headTemp->el_teacher;

			headTemp = (p_teacher_list_node)headTemp->next_teacher;
		}
	}
}

int no_of_teachers() {
	return number_of_nodes_teacher;

}

int remove_teacher_from_list(pteacher_t teacher_value) {

	p_teacher_list_node new_node = (p_teacher_list_node)malloc(sizeof(teacher_list_t));
	p_teacher_list_node headTemp = head_teacher;
	if (teacher_value == NULL)
		return -1;

	/* if the node is the first node */
	if (headTemp->el_teacher->teacher_no == teacher_value->teacher_no)
		return remove_first_teacher(head_teacher);

	/* if the node is in the middle */
	while (headTemp != NULL)
	{
		if (headTemp->el_teacher->teacher_no == teacher_value->teacher_no)
			break;
		headTemp = headTemp->next_teacher;
	}

	/* if the node is the last node */
	if (headTemp->next_teacher == NULL)
		return remove_last_teacher(head_teacher);

	if (headTemp != NULL)
	{
		p_teacher_list_node tmp = headTemp->next_teacher;
		headTemp->next_teacher = tmp->next_teacher;
		tmp->next_teacher = NULL;
		free(tmp);
	}
	number_of_nodes_teacher--;
	return 0;
}

int add_teacher_to_list(pteacher_t teacher_value) {

	p_teacher_list_node new_node = (p_teacher_list_node)malloc(sizeof(teacher_list_t));
	if (teacher_value == NULL)
		return -1;
	else if (!number_of_nodes_teacher && list_size_teacher >= 1 && new_node)	// if no items in the linked list exists then we create the first one which has a special process different from the others to follow
	{
		new_node->el_teacher = teacher_value;
		new_node->next_teacher = NULL;
		head_teacher = new_node;
		current_teacher = new_node;
		number_of_nodes_teacher++;
		return 0;
	}
	else if (number_of_nodes_teacher < list_size_teacher && new_node)
	{
		new_node->el_teacher = teacher_value;
		new_node->next_teacher = NULL;
		current_teacher->next_teacher = new_node;					// set previous item in the linkedList point to the newely created item
		current_teacher = (p_teacher_list_node)current_teacher->next_teacher;
		current_teacher->next_teacher = NULL;						// we move the permanent pointer to the newely created item in the linked list										
		number_of_nodes_teacher++;

		return 0;
	}
	else
		return -1;
}

void set_teacher_list_size(uint16_t listSize) {
list_size_teacher = listSize;
}

int get_teacher_list_size() {
	if (list_size_teacher != 0)
		return list_size_teacher;
	else
		return 0;
}

void print_teacher_list() {
	p_teacher_list_node tempP = (p_teacher_list_node)malloc(sizeof(teacher_list_t));
	tempP = head_teacher;
	printf("The list contains: (");
	int temp_no_of_nodes = number_of_nodes_teacher;
	while (tempP && temp_no_of_nodes > 0)
	{
		pteacher_t teacher_value = (p_teacher_list_node)tempP->el_teacher;
		printf("[%d \t %s]", teacher_value->teacher_no, teacher_value->f_name);
		tempP = (p_teacher_list_node)(tempP->next_teacher);	//shifting to the next node in the linked list
		temp_no_of_nodes--;
	}
	printf(")\n");

}
int remove_last_teacher(p_teacher_list_node headValue)
{
	if (headValue == NULL)
		return -1;
	p_teacher_list_node cursor = headValue;
	p_teacher_list_node back = NULL;
	while (cursor->next_teacher != NULL)
	{
		back = cursor;
		cursor = cursor->next_teacher;
	}
	if (back != NULL)
		back->next_teacher = NULL;
	/* if this is the last node in the list*/
	if (cursor == headValue)
		headValue = NULL;
	free(cursor);
	head_teacher = headValue;
	number_of_nodes_teacher--;
	return 0;
}
//remove node from the front of list(return 0 if succes, else -1)
int remove_first_teacher(p_teacher_list_node headValue)
{
	if (headValue == NULL)
		return NULL;
	p_teacher_list_node front = headValue;
	headValue = headValue->next_teacher;
	front->next_teacher = NULL;
	if (front == headValue)//check if it is the last node in the list
	{
		headValue = NULL;
	}
	free(front);
	number_of_nodes_teacher--;
	head_teacher = headValue;
	return 0;
}

