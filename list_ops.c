#include "student.h"

/**
 * insert_sorted - Inserts a new student node sorted by ID in ascending order
 * @head: Double pointer to the head of the student list
 * @id: Student ID
 * @name: Student name
 * @gpa: Student GPA
 *
 * Return: Address of the new node, or NULL if allocation fails
 */
student_t *insert_sorted(student_t **head, int id, const char *name, float gpa)
{
	student_t *new_node, *current;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(student_t));
	if (new_node == NULL)
		return (NULL);

	new_node->id = id;
	strncpy(new_node->name, name, sizeof(new_node->name) - 1);
	new_node->name[sizeof(new_node->name) - 1] = '\0';
	new_node->gpa = gpa;
	new_node->next = NULL;

	if (*head == NULL || (*head)->id >= id)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	current = *head;
	while (current->next != NULL && current->next->id < id)
		current = current->next;

	new_node->next = current->next;
	current->next = new_node;

	return (new_node);
}

/**
 * find_student - Finds a student node by ID
 * @head: Pointer to the head of the student list
 * @id: Student ID to search for
 *
 * Return: Pointer to the found node, or NULL if not found
 */
student_t *find_student(student_t *head, int id)
{
	while (head != NULL)
	{
		if (head->id == id)
			return (head);
		head = head->next;
	}
	return (NULL);
}

/**
 * remove_student - Removes a student node with a matching ID from the list
 * @head: Double pointer to the head of the student list
 * @id: Student ID to remove
 *
 * Return: 1 if removed successfully, 0 if not found
 */
int remove_student(student_t **head, int id)
{
	student_t *temp, *prev;

	if (head == NULL || *head == NULL)
		return (0);

	temp = *head;
	if (temp->id == id)
	{
		*head = temp->next;
		free(temp);
		return (1);
	}

	while (temp != NULL && temp->id != id)
	{
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL)
		return (0);

	prev->next = temp->next;
	free(temp);
	return (1);
}

/**
 * print_list - Prints all nodes in the student linked list
 * @head: Pointer to the head of the student list
 */
void print_list(const student_t *head)
{
	while (head != NULL)
	{
		printf("ID: %d | Name: %-10s | GPA: %.2f\n",
			head->id, head->name, head->gpa);
		head = head->next;
	}
}
