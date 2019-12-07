
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "read_data.h"
#include "student.h"
#include "student_list.h"
#include "teacher.h"
#include "teacher_list.h"
#include "course.h"
#include "course_list.h"

#define MAX_LENGTH 1000
#define MAX_NAME_LENGTH 20
//TESTING FILE READ
////main.c
//#include<stdio.h>
//#include "read_data.h"
//
//char* filename = "course_database.txt";
//
//int main() {
//	read_data_from_file(filename);
//
//}
FILE* fp; //file pointer
char buff[10000]; //The buffer is a large character string where the text read from the file can be stored
int  teacher_num, course_num, semester_num, student_num;
char student_name[MAX_NAME_LENGTH], teacher_name[MAX_NAME_LENGTH], course_name[MAX_NAME_LENGTH];
char* tempString=student_name;

void read_data_from_file(char* filename)
{

	// we use pointer to the file to read it
	fopen_s(&fp, filename, "r");
	if (fp == NULL)
	{
		exit(EXIT_FAILURE);
	}
	//Data has been read from a file until feof does not return 0. (eof stands for end of file)
	while (!feof(fp))
	{
		fgets(buff, 10000, fp);
		//printf("%d", ret);
		if ((sscanf_s(buff, "S%d%10s", &student_num, tempString ,sizeof(student_name))) == 2)
		{
			//tempString = student_name;
			printf("studnet name: %s student num: %d added to list\n", student_name, student_num);

			add_student_to_list(create_student(student_num, tempString));



		}
		else if ((sscanf_s(buff, "T%d%10s", &teacher_num, &teacher_name, (unsigned)_countof(teacher_name))) == 2)
		{
			printf("Teacher name: %s , Teacher num: %d added to list\n", teacher_name, teacher_num);
			add_teacher_to_list(create_teacher(teacher_num, &teacher_name));

		}
		else if ((sscanf_s(buff, "C %d %4s %d", &course_num, course_name, (unsigned)_countof(course_name), &semester_num)) == 3)
		{
			//printf("Course name: %s , Course num: %d , semester number: %d", course_name, course_num, semester_num);
		//	add_course_to_list(create_course(course_num, course_name, semester_num));

		}
		else if ((sscanf_s(buff, "E %d %d", &student_num, &course_num)) == 2)
		{
			//enrolStudent(student_number, course_number);
			printf("student: %d assigned to course %d\n", student_num, course_num);
		}
		else if ((sscanf_s(buff, "A %d %d", &teacher_num, &course_num)) == 2)
		{
			//printf("Teacher: %d ,  assigned to course: %d\n", teacher_num, course_num);
			//assignTeacher(teacher_number, course_number);
		}

	}
	fclose(fp);

}