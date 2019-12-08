#pragma once

typedef struct node_t* pnode_t;
typedef struct list_t* plist_t;
typedef struct node_t {
	void* element;
	pnode_t next;
} node_t;


typedef struct list_t {
	int size;
	pnode_t current;
	pnode_t head
		;
}list_t;



plist_t creatae_linked_list();

int size(plist_t list);

int add_item_to_list(plist_t list, void* item);

pnode_t get_list_node(plist_t list, pnode_t node, void* item);

pnode_t get_previous_node(plist_t list,pnode_t current, const pnode_t node);

int remove_item_from_list(plist_t list, void* item);

void destory_linked_list(plist_t self);

void* get_element_from_list(plist_t self, int i);
