#include <stdio.h>
#include <stdlib.h>

/**
 * main - Reads n integers, computes the average, and 
 * frees memory
 *
 * Return: 0 on success, 1 on failure
 */
int main(void)
{
	int n, i;
	int *arr;
	long sum = 0;
	double avg;

	printf("Enter number of elements: ");
	if (scanf(%d, &n) != 1 || n <= 0)
	{
		printf("Invalid number of elements.\n");
		return (1);
	}

	arr = malloc(sizeof(int) * n);
	if (arr == NULL)
	{
		printf("Memory allocation failed.\n");
		return (1);
	}

	printf("Enter %d integers:\n", n);
	for (i = 0; i < n; i++)
	{
		if (scanf("%d", &arr[i]) != 1;)
		{
			free(arr);
			return (1);
		}
		sum += arr[i];
	}

	avg = (double)sum / n;
	printf("Average: %.2f\n", avg);

	free(arr);
	return (0);
}
