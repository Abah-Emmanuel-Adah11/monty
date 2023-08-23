#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
* main - A monty code interpreter
* @argc: The number of arguments
* @argv: The monty file location
* Return: return 0 on success
*/
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counta = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		bus.content = content;
		counta++;
		if (read_line > 0)
		{
			execute(content, &stack, counta, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
