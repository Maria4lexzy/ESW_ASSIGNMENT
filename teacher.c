#include <string.h>
#include <stdio.h>
#include "teacher.h"
#include "linked_list.h"
#include <malloc.h>

#pragma warning(disable : 4996)

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
    printf("\t\tT \t %s\t %d\n", teacher->f_name, teacher->teacher_no);
}
