#include "monty.h"

/**
* f_pop - printing the top of the stack
* @head: double head pointer to the stack
* @counter: line count
*
* Return: nothing
*/
void f_pop(stack_t **head, unsigned int counter)
{
	stack_t *hee;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	hee = *head;
	*head = hee->next;
	free(hee);
}

/**
* f_pint - printing the top of the stack
* @head: double head pointer to the stack
* @counter: line count
*
* Return: nothing
*/
void f_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
* f_nop - nothing
* @head: double head pointer to the stack
* @counter: line count
*
* Return: nothing
*/
void f_nop(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}
/**
* f_push -  adding node to the stack
* @head: double head pointer to the stack
* @counter: line count
*
* Return: nothing
*/
void f_push(stack_t **head, unsigned int counter)
{
	int i, mk = 0, mmm = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			mk++;
		for (; bus.arg[mk] != '\0'; mk++)
		{
			if (bus.arg[mk] > 57 || bus.arg[mk] < 48)
				mmm = 1; }
		if (mmm == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	i = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, i);
	else
		addqueue(head, i);
}
