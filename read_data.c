
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "read_data.h"
FILE* fp;
char buff[255];
int student_num,  teacher_num,course_num, semester_num;

void read_data_from_file(char* filename)
{
	// we use pointer to the file to read it
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		exit(EXIT_FAILURE);
	}

	// as long as it's not the end of the file(eof) we check the format and act on it
	while (!feof(fp))
	{
		if (sscanf(fp, "S %d %s\n", &student_num, buff) == 2)
		{
			//addStudent(student_number, buff);
		}
		else if (sscanf(fp, "T %d %s\n", &teacher_num, buff) == 2)
		{
			//addTeacher(teacher_number, buff);
		}
		else if (sscanf(fp, "C %d %s %d\n", &course_num, buff, &semester_num) == 3)
		{
			//addCourse(course_number, buff, semester_number);
		}
		else if (sscanf(fp, "E %d %d\n", &student_num, &course_num) == 2)
		{
			//enrolStudent(student_number, course_number);
		}
		else if (fscanf(fp, "A %d %d\n", &teacher_num, &course_num) == 2)
		{
			//assignTeacher(teacher_number, course_number);
		}
		else
		{
			fgets(buff, sizeof(buff), fp);
		}
	}
	fclose(fp);
}