#include "sort.h"

/**
 * insertion_sort_list - using insertion sort to sort doubly linked list
 * @list: head of linked list
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *ip, *temp;

	if (list == NULL || (*list)->next == NULL || *list == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		temp = current->next;
		ip = current->prev;
		while (ip != NULL && ip->n > current->n)
		{
			ip->next = current->next;
			if (ip->next != NULL)
				current->next->prev = ip;
			current->prev = ip->prev;
			current->next = ip;
			if (ip->prev == NULL)
				*list = current;
			if (ip->prev != NULL)
				ip->prev->next = current;
			ip->prev = current;
			ip = current->prev;
			print_list(*list);
		}
		current = temp;
	}
}

