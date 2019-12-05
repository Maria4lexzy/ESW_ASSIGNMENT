#include <stdio.h>
#include <cstdint>
#include "student.h"



void main() {
	int nrOfItems;
	printf("Enter total number nodes: ");
	scanf_s("%d", &nrOfItems);
	setListSize(nrOfItems);
	int i = 1;
	int elementInt;
	element* tempCursor;
	//setting nodes to the linked list
	while (nrOfItems)
	{
		printf("Enter LinkedListObject number %d: ", i);
		scanf_s("%d", &elementInt);

		tempCursor = (element*)malloc(sizeof(element));
		if (tempCursor)   															 // avoiding "warning C6011: dereferencing NULL pointer"
		{
			tempCursor->data = student_t;
			addItem(tempCursor);
		}

		nrOfItems--;
		if (nrOfItems == 0)
			continue;
		i++;
	}
	printList(); //printing out all items from the linkedList
	printf("Test: Number of items in linked list is: %d \n", noOfItems());
	tempCursor = getItem(0);
	printf("Test: Item in position 0 is: %d \n", tempCursor->data);
	removeItem(getItem(1));
	printList();


}
