#include <stdio.h>
#include "course_list.h"
#include <malloc.h>
#include "course.h"

course_list_node* head_course = NULL;
course_list_node* current_course = NULL;
uint16_t number_of_nodes_course = 0;
uint16_t list_size_course = 0;

void printCourseList() {

	course_list_node* tempP = (course_list_node*)malloc(sizeof(course_list_node));
	tempP = head_course;
	printf("The list contains: (");
	int temp_no_of_nodes = number_of_nodes_course;
	while (tempP && temp_no_of_nodes > 0)
	{
		pcourse_t* course_value = (course_list_node*)tempP->el_course;
		printf("[%d \t %s\t %d]", course_value->course_num, course_value->course_name, course_value->semester_num);
		tempP = (course_list_node*)(tempP->next_course);	//shifting to the next node in the linked list
		temp_no_of_nodes--;
	}
	free(tempP);
	tempP = NULL;
	printf(")\n");
}

void setCourseListSize(uint16_t listSize) {
	list_size_course = listSize;
}

int getCourseListSize() {
	if (list_size_course != 0)
		return list_size_course;
	else
		return 0;
}

pcourse_t* get_course_by_index(uint16_t index)
{
	if (number_of_nodes_course && index >= 0 && index < number_of_nodes_course)
	{
		course_list_node* headTemp = head_course;				// starting from first node
		if (index == 0)
			return headTemp->el_course;
		else
			for (uint16_t i = 0; i < index; i++)
				headTemp = (course_list_node*)(headTemp->next_course);	// moving to next node

		return headTemp->el_course;							// returning wanted item
	}
	return NULL;
}

pcourse_t* get_course_by_course_number(pcourse_t* course_value)
{
	if (number_of_nodes_course >= 0 && course_value != NULL)
	{
		course_list_node* headTemp = head_course;				// starting from first node

		for (uint16_t i = 0; i < number_of_nodes_course; i++)
		{
			if (headTemp->el_course->course_num == course_value->course_num) //check if student numbers match
				return headTemp->el_course;

			headTemp = (course_list_node*)headTemp->next_course;
		}
	}
	return NULL;
}

int no_of_courses()
{
	return number_of_nodes_course;
}

int add_course_to_list(pcourse_t* course_value)
{
	course_list_node* new_node = (course_list_node*)malloc(sizeof(course_list_node));
	if (course_value == NULL)
		return -1;
	else if (!number_of_nodes_course && list_size_course >= 1 && new_node)	// if no items in the linked list exists then we create the first one which has a special process different from the others to follow
	{
		new_node->el_course = course_value;
		new_node->next_course = NULL;
		head_course = new_node;
		current_course = new_node;
		number_of_nodes_course++;
		return 0;
	}
	else if (number_of_nodes_course < list_size_course && new_node)
	{
		new_node->el_course = course_value;
		new_node->next_course = NULL;
		current_course->next_course = new_node;					// set previous item in the linkedList point to the newely created item
		current_course = (course_list_node*)current_course->next_course;
		current_course->next_course = NULL;						// we move the permanent pointer to the newely created item in the linked list										
		number_of_nodes_course++;

		return 0;
	}
	else
		return -1;
}

int remove_course_from_list(pcourse_t* course_value)
{
	course_list_node* new_node = (course_list_node*)malloc(sizeof(course_list_node));
	course_list_node* headTemp = head_course;
	if (course_value == NULL)
		return -1;

	/* if the node is the first node */
	if (headTemp->el_course->course_num == course_value->course_num)
		return remove_first_course(head_course);

	/* if the node is in the middle */
	while (headTemp != NULL)
	{
		if (headTemp->el_course->course_num == course_value->course_num)
			break;
		headTemp = headTemp->next_course;
	}

	/* if the node is the last node */
	if (headTemp->next_course == NULL)
		return remove_last_course(head_course);

	if (headTemp != NULL)
	{
		course_list_node* tmp = headTemp->next_course;
		headTemp->next_course = tmp->next_course;
		tmp->next_course = NULL;
		free(tmp);
	}
	number_of_nodes_course--;
	return 0;
}
//remove node from the front of list(return 0 if succes, else -1)
int remove_first_course(course_list_node* headValue)
{
	if (headValue == NULL)
		return NULL;
	course_list_node* front = headValue;
	headValue = headValue->next_course;
	front->next_course = NULL;
	if (front == headValue)//check if it is the last node in the list
	{
		headValue = NULL;
	}
	free(front);
	number_of_nodes_course--;
	head_course = headValue;
	return 0;
}

//remove node from the back of the list(return 0 if succes, else -1)
int remove_last_course(course_list_node* headValue)
{
	if (headValue == NULL)
		return -1;
	course_list_node* cursor = headValue;
	course_list_node* back = NULL;
	while (cursor->next_course != NULL)
	{
		back = cursor;
		cursor = cursor->next_course;
	}
	if (back != NULL)
		back->next_course = NULL;
	/* if this is the last node in the list*/
	if (cursor == headValue)
		headValue = NULL;
	free(cursor);
	head_course = headValue;
	number_of_nodes_course--;
	return 0;
}