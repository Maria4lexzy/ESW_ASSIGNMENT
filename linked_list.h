#pragma once

typedef struct node* p_node_t;
typedef struct list* p_list_t;

p_list_t linked_list_create();

int no_of_items_in_list(p_list_t list);

int add_item_to_list(p_list_t list, void* item);

p_node_t search(p_list_t list, p_node_t node, void* item);

p_node_t get_before(p_list_t list,p_node_t current, const p_node_t node);

int remove_item_from_list(p_list_t list, void* item);

void linked_list_destroy(p_list_t self);

void* get_element_from_list(p_list_t self, int i);
