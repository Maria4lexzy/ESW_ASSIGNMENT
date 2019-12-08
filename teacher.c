#include <string.h>
#include <stdio.h>
#include "teacher.h"
#include "linked_list.h"
#include <malloc.h>

#pragma warning(disable : 4996)

static plist_t teacher_list;


plist_t create_teacher_list() {
	teacher_list = creatae_linked_list();
	return teacher_list;
}

p_teacher_t create_teacher(int teacher_no, char *f_name){
	p_teacher_t teacher = (p_teacher_t)malloc(sizeof(teacher_t));
    if(teacher == NULL){
        return NULL;
    }
    else{
        teacher->teacher_no = teacher_no;
        teacher->f_name = strdup(f_name);
        return teacher;
    }
}

void destroy_teacher(p_teacher_t teacher){
    free(teacher->f_name);
    char* f_name=NULL;
    free(teacher);

}
void set_teacher_num(p_teacher_t teacher, int teacher_no){
 teacher->teacher_no = teacher_no;
}

void set_teacher_name(p_teacher_t teacher, char *f_name){
    teacher->f_name = f_name;
}

int get_teacher_num(p_teacher_t teacher){
    return teacher->teacher_no;
}

char* get_teacher_name(p_teacher_t teacher){
    return teacher->f_name;
}

void print_teacher_info(p_teacher_t teacher){
    printf("T \t %s\t %d\n", teacher->f_name, teacher->teacher_no);
}

void add_teacher(p_teacher_t teacher) {
	if (teacher_list == NULL) {
		teacher_list = create_teacher_list();
	}
	add_item_to_list(teacher_list, teacher);
}

p_teacher_t get_teacher(int teacher_no)
{
	for (int i = 0; i < size; i++) {
		if (((p_teacher_t)get_element_from_list(teacher_list, i))->teacher_no == teacher_no) {
			return ((p_teacher_t)get_element_from_list(teacher_list, i));
		}
	}
	return NULL;
}

void remove_teacher_from_list(p_teacher_t teacher) {
	remove_item_from_list(teacher_list, teacher);
}

plist_t get_teacher_list() {
	return teacher_list;
}


