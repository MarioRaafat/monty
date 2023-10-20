#include "monty.h"

/**
* f_rotl- function that rotates the stack to the top
* @head: head of the stack
* @counter: line count
*
* Return: nothing
*/
void f_rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *ux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	ux = (*head)->next;
	ux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = ux;
}
