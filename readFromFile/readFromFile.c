//
// Created by Alicja Siudak on 04/12/2019.
//

#include "readFromFile.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "..//course.h"
#include "..//enrolment.h"
#include "..//student.h"
#include "..//teacher.h"
#include "..//assignment.h"

#pragma warning(disable : 4996)

FILE *fp;
char buff[255];
int student_number, course_number, teacher_number, semester_number;

void read_from_file(char *filename)
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
        if (fscanf(fp, "S %d %s\n", &student_number, buff) == 2)
        {
			p_student_t student = createStudent(student_number, buff);
			add_student_to_list(student);
		}
        else if (fscanf(fp, "T %d %s\n", &teacher_number, buff) == 2)
        {
			p_teacher_t teacher = createTeacher(teacher_number, buff);
			add_teacher_to_list(teacher);
		}
        else if (fscanf(fp, "C %d %s %d\n", &course_number, buff, &semester_number) == 3)
        {
			p_course_t course = createCourse(course_number, buff, semester_number);
			add_course_to_list(course);
		}
        else if (fscanf(fp, "E %d %d\n", &student_number, &course_number) == 2)
        {
			p_student_t student = get_student_from_list(student_number);
			p_course_t course = get_course_from_list(course_number);
			p_enrolment_t enrolment = constructEnrolment(course,student);
			add_enrolment_to_list(enrolment);
        }
        else if (fscanf(fp, "A %d %d\n", &teacher_number, &course_number) == 2)
        {
			p_teacher_t teacher = get_teacher_from_list(teacher_number);
			p_course_t course = get_course_from_list(course_number);
			p_assignment_t assignment = createAssignment(course, teacher);
			add_assignment_to_list(assignment);
		}
        else
        {
            fgets(buff, sizeof(buff), fp);
        }
    }
    fclose(fp);
}
