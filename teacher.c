//
// Created by Alicja Siudak on 03/12/2019.
//

#include <string.h>
#include <stdio.h>
#include "teacher.h"
#include "linked_list.h"
#include <malloc.h>
#pragma warning(disable : 4996)

static p_list_t teacher_list;


p_list_t create_teacher_list() {
	teacher_list = linked_list_create();
	return teacher_list;
}

teacher_t* createTeacher(int teacher_no, char *f_name){
    teacher_t* teacher = (teacher_t*)malloc(sizeof(teacher_t));
    if(teacher == NULL){
        return NULL;
    }
    else{
        teacher->teacher_no = teacher_no;
        teacher->f_name = strdup(f_name);
        return teacher;
    }
}

void destroyTeacher(teacher_t* teacher){
    free(teacher->f_name);
    char* f_name=NULL;
    free(teacher);

}
void setTeacherNo(teacher_t* teacher, int teacher_no){
 teacher->teacher_no = teacher_no;
}

void setTeacherFName(teacher_t* teacher, char *f_name){
    teacher->f_name = f_name;
}

int getTeacherNo(teacher_t* teacher){
    return teacher->teacher_no;
}

char* getTeacherFName(teacher_t* teacher){
    return teacher->f_name;
}

void print_Teacher_Information(teacher_t* teacher){
    printf("T \t %s\t %d\n", teacher->f_name, teacher->teacher_no);
}

void add_teacher_to_list(p_teacher_t teacher) {
	if (teacher_list == NULL) {
		teacher_list = create_teacher_list();
	}
	add_item_to_list(teacher_list, teacher);
}

teacher_t* get_teacher_from_list(int teacher_no)
{
	for (int i = 0; i < no_of_items_in_list; i++) {
		if (((p_teacher_t)get_element_from_list(teacher_list, i))->teacher_no == teacher_no) {
			return ((p_teacher_t)get_element_from_list(teacher_list, i));
		}
	}
	return NULL;
}

void remove_teacher_from_list(p_teacher_t teacher) {
	remove_item_from_list(teacher_list, teacher);
}

p_list_t get_teacher_list() {
	return teacher_list;
}


