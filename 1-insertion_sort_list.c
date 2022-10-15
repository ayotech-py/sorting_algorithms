#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @main_node: The node to be swapped.
 * @right_node: Pointer to the node main_node
 *              would be swappped with.
 */
void swap_nodes(listint_t **h, listint_t *main_node, listint_t **right_node)
{
	(*right_node)->next = main_node->next;
	if (main_node->next != NULL)
		main_node->next->prev = *right_node;
	main_node->prev = (*right_node)->prev;
	main_node->next = *right_node;
	if ((*right_node)->prev != NULL)
		(*right_node)->prev->next = main_node;
	else
		*h = main_node;
	(*right_node)->prev = main_node;
	*right_node = main_node->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *sorted_iter, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		sorted_iter = iter->prev;
		while (sorted_iter != NULL && iter->n < sorted_iter->n)
		{
			swap_nodes(list, iter, &sorted_iter);
			print_list((const listint_t *)*list);
		}
	}
}
