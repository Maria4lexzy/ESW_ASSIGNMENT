#include <stdio.h>
#include "linked_list.h"
#include <malloc.h>

typedef struct list_t {
	int size;
	pnode_t last;
	pnode_t head;
}list_t;


plist_t linked_list_create() {
	plist_t new_list = malloc(sizeof(list_t));
	new_list->head = NULL;
	new_list->last = NULL;
	new_list->size = 0;
	return new_list;
}

int no_of_items_in_list(plist_t list){}

int add_item_to_list(plist_t list, void* item){}

pnode_t search(plist_t list, plist_t node, void* item){}

pnode_t get_before(plist_t list, plist_t current, const plist_t node){}
int remove_item_from_list(plist_t list, void* item){}

void linked_list_destroy(plist_t self){}

void* get_element_from_list(plist_t self, int i){}