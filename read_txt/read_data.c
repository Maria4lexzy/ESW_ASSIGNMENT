
#include "read_data.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "..//course.h"
#include "..//enrolment.h"
#include "..//student.h"
#include "..//teacher.h"
#include "..//assignment.h"

#define MAX_NAME_LENGTH 100
FILE* fp;
char buff[100]; //The buffer is a large character string where the text read from the file can be stored
int  teacher_num, course_num, semester_num, student_num;
char student_name[MAX_NAME_LENGTH], teacher_name[MAX_NAME_LENGTH], course_name[MAX_NAME_LENGTH];

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
		fgets(buff, 100, fp);
		if ((sscanf_s(buff, "S %d %s", &student_num, student_name, (unsigned)_countof(student_name))) == 2)
		{
			
			p_student_t student = create_student(student_num, student_name);
			add_student(student);


		}
		else if ((sscanf_s(buff, "T %d %s", &teacher_num, &teacher_name, (unsigned)_countof(teacher_name))) == 2)
		{
			p_teacher_t teacher = create_teacher(teacher_num, teacher_name);
			add_teacher(teacher);

		}
		else if ((sscanf_s(buff, "C %d %s %d", &course_num, course_name, (unsigned)_countof(course_name), &semester_num)) == 3)
		{
			char* space_course_name;
			space_course_name = malloc(sizeof(char) * (strlen(course_name) + 1));
			strcpy(space_course_name, course_name);
			p_course_t course = create_course(course_num, space_course_name, semester_num);
			add_course(course);

		}
		else if ((sscanf_s(buff, "E %d %d", &student_num, &course_num)) == 2)
		{
			p_student_t student = get_student(student_num);
			p_course_t course = get_course_from_list(course_num);
			p_enrolment_t enrolment = create_enrolment(course, student);
			add_enrolment_to_list(enrolment);
		}
		else if ((sscanf_s(buff, "A %d %d", &teacher_num, &course_num)) == 2)
		{
			p_teacher_t teacher = get_teacher(teacher_num);
			p_course_t course = get_course_from_list(course_num);
			p_assignment_t assignment = create_assignment(course, teacher);
			add_assignment_to_list(assignment);
		}

	}
	fclose(fp);

}
