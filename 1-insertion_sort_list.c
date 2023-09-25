#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: The list to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insertion_point, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		insertion_point = current->prev;

		while (insertion_point != NULL && insertion_point->n > current->n)
		{
			temp = current->next;

			if (temp != NULL)
				temp->prev = insertion_point;

			insertion_point->next = temp;

			if (insertion_point->prev == NULL)
			{
				insertion_point->prev = current;
				*list = current;
				current->prev = NULL;
			}
			else
			{
				current->prev = insertion_point->prev;
				insertion_point->prev->next = current;
				insertion_point->prev = current;
			}

			current->next = insertion_point;
			insertion_point = current->prev;
			print_list(*list);
		}

		current = current->next;
	}
}
