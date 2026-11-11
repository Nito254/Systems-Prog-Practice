#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct student - Singly linked list node for a student
 * @id: Student ID
 * @name: Student name
 * @gpa: Student GPA
 * @next: Pointer to the next node in the list
 */
typedef struct student
{
	int id;
	char name[50];
	float gpa;
	struct student *next;
} student_t;

student_t *insert_sorted(student_t **head, int id, const char *name, float gpa);
student_t *find_student(student_t *head, int id);
int remove_student(student_t **head, int id);
void print_list(const student_t *head);
void free_list(student_t **head);

#endif /* STUDENT_H */
