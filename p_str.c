#include "monty.h"

/**
* f_pstr - printing the string starting at the top of the stack,
* followed by a new
* @head: head of stack
* @counter: line count
*
* Return: nothing
*/
void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *m;
	(void)counter;

	m = *head;
	while (m)
	{
		if (m->n > 127 || m->n <= 0)
		{
			break;
		}
		printf("%c", m->n);
		m = m->next;
	}
	printf("\n");
}
