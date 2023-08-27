#include "monty.h"

/**
  *f_rotl- A function that rotates the stack to the top
  *@head: The stack head
  *@counter: The line_number
  *Return: void
 */

void f_rotl(stack_t **head, unsigned int counter)
{
	stack_t *tmp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}
