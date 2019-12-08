#include "linked_list.h"
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>



plist_t creatae_linked_list()
{
	plist_t new_list = malloc(sizeof( list_t));
	if (new_list)
	{
		new_list->size = 0;
		new_list->current = NULL;
		new_list->head = NULL;
	}
	return new_list;
}

int size(plist_t list) {
	if (list != NULL) {
		return list->size;
	}
	else {
		return -1;
	}
}


int add_item_to_list(plist_t list, void* item) {
	if(list == NULL){
		list = creatae_linked_list(list);
		}
		pnode_t p_new_node;
		p_new_node = malloc(sizeof(node_t));
		if (list->current != NULL) {
			list->current->next = p_new_node;
		}
		list->current = p_new_node;
		p_new_node->element = item;
		p_new_node->next = NULL;
		list->size++;
		if (list->size == 1) {
			list->head = p_new_node;
		}
		return 0;
}

pnode_t get_list_node(plist_t list, pnode_t current, void*item) {
	if (current != NULL) {
		if (current->element == item) {
			return current;
		}
		else {
			get_list_node(list, current->next, item);
		}
	} else {
			return NULL;
	}
} 

//used to remove element in the later method
pnode_t get_previous_node(plist_t list, pnode_t current, const pnode_t next) {
	
	if (current->next != NULL) {
		if (current->next == next) {
			return current;
		}
		else {
			get_previous_node(list, current->next, next);
		}
	}
	else {
		return NULL;
	}
}



//
int remove_item_from_list(plist_t list, void* item) {
	pnode_t node = NULL;
	node = get_list_node(list, list->head, item);
	if (node != NULL ) {
		if (list->head == node) {
			if (node->next == NULL) {
				list->current = NULL;
				list->head = NULL;
			}
			else {
				list->head = node->next;
			}
		}
		else {
			pnode_t previous_node = NULL;
			previous_node = get_previous_node(list, list->head, node);
			if (previous_node != NULL) {
				previous_node->next = node->next;
				if (node->next == NULL) {
					list->current = previous_node;
				}
			}
		}
		free(node);
		node = NULL;
		list-> size--;
		return 0;
	}
	else {
		return -1;
	}

}

void destory_linked_list(plist_t self)
{
	free(self);
	self = NULL;
}

void* get_element_from_list(plist_t self, int i)
{
	pnode_t current = self->head;
	for (int j = 0; j < size(self); j++) {
		if (i == j) {
			return current->element;
		}
		else {
			current = current->next;
		}
	}
}
