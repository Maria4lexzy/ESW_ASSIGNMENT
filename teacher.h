#pragma once
#include "linked_list.h"

typedef struct teacher_t {
    int teacher_no;
    char *f_name;
}teacher_t;

typedef struct teacher_t* p_teacher_t;


p_teacher_t create_teacher(int teacher_no, char *f_name);
void destroy_teacher(p_teacher_t teacher);
void set_teacher_num(p_teacher_t teacher, int teacher_no);
void set_teacher_name(p_teacher_t teacher, char *f_name);
int get_teacher_num(p_teacher_t teacher);
char* get_teacher_name(p_teacher_t teacher);
void print_teacher_info(p_teacher_t teacher);
void add_teacher(p_teacher_t teacher);
p_teacher_t get_teacher(int teacher_no);
void remove_teacher_from_list(p_teacher_t teacher);
p_list_t get_teacher_list();
p_list_t create_teacher_list();
