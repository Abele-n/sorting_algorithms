#include "sort.h"

/**
 * swaps_nodes - swaps two nodes inside listint_t doubly-linked liat
 * @h: pointer to head of the linked list
 * @node1: pointer to first node to swap
 * @node2: the second node to swap
 */

void swaps_nodes(listint_t **h, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*h = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - sorts doubly linked list of integers
 * By insertion sort
 * @list: pointer to head of the list
 *
 * Description: After each swap, a list is printed
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *my_iter, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (my_iter = (*list)->next; my_iter != NULL; my_iter = temp)
	{
		temp = my_iter->next;
		insert = my_iter->prev;
		while (insert != NULL && my_iter->n < insert->n)
		{
			swaps_nodes(list, &insert, my_iter);
			print_list((const listint_t *)*list);
		}
	}
}
