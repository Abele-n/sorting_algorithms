#include "sort.h"

void swaps_behind_node(listint_t **list, listint_t **tail, listint_t **shaker);
void swaps_ahead_node(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swaps_ahead_node - it swaps the node in listint_t  doubly linked list
 * Of the list of ints with the node ahead of it
 * @list: pointer to head of doubly linked list of ints
 * @tail: pointer to tail of doubly-linked list
 * @shaker: current swapping node pointer of cocktail shaker algorithm
 */

void swaps_ahead_node(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *temp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*shaker)->prev;
	(*shaker)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = temp;
	temp->next = *shaker;
	*shaker = temp;
}

/**
 * swaps_behind_node - it swaps node in listint_t doubly linked
 * lists of ints with behind node
 * @list: pointer to head of the doubly linked list of ints
 * @tail: pointer to tail of doubly linked list of ints
 * @shaker: pointer to current swapping node of cocktail shaker algorithm
 */

void swaps_behind_node(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *temp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = temp;
	else
		*tail = temp;
	temp->next = (*shaker)->next;
	(*shaker)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = temp;
	temp->prev = *shaker;
	*shaker = temp;
}

/**
 * cocktail_sort_list - sorts listint_t doubly linked lists of ints
 * Using cocktail shaker algorithm in ascending order
 * @list: pointer to head of listint_t doubly linked list
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool not_shaken_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (not_shaken_stirred == false)
	{
		not_shaken_stirred = true;
		for (shaker = *list; shaker != tail;
				shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swaps_ahead_node(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				not_shaken_stirred = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list; shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swaps_behind_node(list, &tail, &shaker);
				print_list((const listint_t *)*list)
					not_shaken_stirred = false;
			}
		}
	}
}
