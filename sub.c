#include "monty.h"

/**
  *f_sub- A function that performs subtration
  *@head: The stack head
  *@counter: The line_number
  *Return: void
 */

void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *auxilary;
	int sus, nodes;

	auxilary = *head;
	for (nodes = 0; auxilary != NULL; nodes++)
		auxilary = auxilary->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	auxilary = *head;
	sus = auxilary->next->n - auxilary->n;
	auxilary->next->n = sus;
	*head = auxilary->next;
	free(auxilary);
}
