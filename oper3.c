#include "monty.h"

/**
* f_pall - function that prints everything in the stack
* @head: double head pointer to the stack
* @counter: unused line count
*
* Return: ...
*/
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *mm;
	(void)counter;

	mm = *head;
	if (mm == NULL)
		return;
	while (mm)
	{
		printf("%d\n", mm->n);
		mm = mm->next;
	}
}

/**
* f_swap - swaping the top two elements of the stack
* @head: head of stack
* @counter: line count
*
* Return: nothing
*/
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, tmp;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	tmp = h->n;
	h->n = h->next->n;
	h->next->n = tmp;
}

