#include "monty.h"
/**
* free_stack - A function that frees a doubly linked list
* @head: The head of the stack
*/
void free_stack(stack_t *head)
{
	stack_t *auxilary;

	auxilary = head;
	while (head)
	{
		auxilary = head->next;
		free(head);
		head = auxilary;
	}
}
