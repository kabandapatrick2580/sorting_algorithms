#include "sort.h"

/**
 * swap_list_nodes - swaps nodes of a linked list
 * @list: pointer to the head of the list
 * @a: first node to swap
 * @b: second node to swap
 */
void swap_list_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	listint_t *prev_a = a->prev;
	listint_t *prev_b = b->prev;

	if (prev_a)
		prev_a->next = b;
	else
		*list = b;

	if (prev_b)
		prev_b->next = a;
	else
		*list = a;

	a->prev = prev_b;
	b->prev = prev_a;

	if (a->next)
		a->next->prev = a;

	if (b->next)
		b->next->prev = b;

	a->next = b->next;
	b->next = a;
}

/**
 * cocktail_sort_list - sorts a linked list using cocktail sorting
 * @list: pointer to the head of the linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current_start = NULL, *current_node;
	int is_swapped = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		is_swapped = 0;
		for (current_node = *list; current_node->next != current_start;
				current_node = current_node->next)
		{
			if (current_node->n > current_node->next->n)
			{
				swap_list_nodes(list, current_node, current_node->next);
				print_list((const listint_t *)*list);
				is_swapped = 1;
			}
		}

		if (is_swapped == 0)
			break;

		is_swapped = 0;
		for (current_node = current_node->prev; current_node != current_start;
				current_node = current_node->prev)
		{
			if (current_node->n < current_node->prev->n)
			{
				swap_list_nodes(list, current_node->prev, current_node);
				print_list((const listint_t *)*list);
				is_swapped = 1;
			}
		}

		current_start = current_node->next;
	} while (is_swapped && current_start != NULL);
}
