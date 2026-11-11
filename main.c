#include "student.h"

/**
 * free_list - Frees all nodes in the student linked list
 * @head: Double pointer to the head of the student list
 */
void free_list(student_t **head)
{
	student_t *temp;

	if (head == NULL)
		return;

	while (*head != NULL)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
}

/**
 * load_from_file - Reads student records from a file into a sorted list
 * @filename: Name of the file to read
 * @head: Double pointer to the head of the student list
 *
 * Return: Number of records loaded, or -1 on file error
 */
int load_from_file(const char *filename, student_t **head)
{
	FILE *fp;
	int id, count = 0;
	char name[50];
	float gpa;

	fp = fopen(filename, "r");
	if (fp == NULL)
		return (-1);

	while (fscanf(fp, "%d %49s %f", &id, name, &gpa) == 3)
	{
		if (insert_sorted(head, id, name, gpa) != NULL)
			count++;
	}

	fclose(fp);
	return (count);
}

/**
 * main - Entry point to test student linked list operations
 *
 * Return: 0 on success, 1 on error
 */
int main(void)
{
	student_t *head = NULL;
	student_t *found = NULL;

	if (load_from_file("students.txt", &head) == -1)
	{
		printf("Could not open students.txt\n");
		return (1);
	}

	printf("--- Sorted Student List ---\n");
	print_list(head);

	printf("\n--- Searching for ID 102 ---\n");
	found = find_student(head, 102);
	if (found != NULL)
		printf("Found: %s (GPA: %.2f)\n", found->name, found->gpa);
	else
		printf("Student 102 not found.\n");

	printf("\n--- Removing ID 102 ---\n");
	if (remove_student(&head, 102))
		printf("Removed ID 102 successfully.\n");
	print_list(head);

	free_list(&head);
	return (0);
}
