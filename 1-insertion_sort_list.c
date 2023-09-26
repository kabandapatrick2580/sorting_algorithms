#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort
 * @list: Pointer to a pointer to the head of the list
 *
 * Description:
 *     Prints the list after each swap
 *     Uses the insertion sort algorithm
 *     Only swaps nodes (including their pointers) and their values
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *updated_iterator, *updated_insert, *updated_tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (updated_iterator = (*list)->next; updated_iterator != NULL;
			updated_iterator = updated_tmp)
	{
		updated_tmp = updated_iterator->next;
		updated_insert = updated_iterator->prev;

		while (updated_insert != NULL && updated_iterator->n < updated_insert->n)
		{
			if (updated_iterator->next != NULL)
				updated_iterator->next->prev = updated_insert;
			updated_insert->next = updated_iterator->next;

			updated_iterator->next = updated_insert;
			updated_iterator->prev = updated_insert->prev;

			if (updated_insert->prev != NULL)
				updated_insert->prev->next = updated_iterator;
			else
				*list = updated_iterator;
			updated_insert->prev = updated_iterator;

			updated_insert = updated_iterator->prev;

			print_list((const listint_t *)*list);
		}
	}
}
