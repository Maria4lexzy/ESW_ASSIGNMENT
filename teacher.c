#include "teacher.h"

pteacher_t create_teacher(int teacher_num, char f_name){}
void destroy_eacher(pteacher_t teacher){}
void set_teacher_num(teacher_t teacher, int teacher_num){}
void set_teacher_name(pteacher_t teacher, char f_name){}
int get_teacherNo(pteacher_t teacher){}
char get_teacherFName(pteacher_t teacher){}
void print_teacher_info(pteacher_t teacher) {

	printf("T \t %s\t %d\n", teacher->first_name, teacher->teacher_num);
}