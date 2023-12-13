#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *argument;
    int value;

    /* Get the argument from the next token in the line */
    argument = strtok(NULL, " \t\n");

    /* Check if the argument is missing */
    if (argument == NULL)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Convert the argument to an integer using atoi */
    value = atoi(argument);

    /* Create a new node for the stack */
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    /* Set the value of the new node and update pointers */
    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    /* Update the previous pointer of the existing top node */
    if (*stack != NULL)
        (*stack)->prev = new_node;

    /* Update the stack pointer to point to the new top node */
    *stack = new_node;
}

/**
 * pall - prints all the values on the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
    /* Unused parameter */
    (void)line_number;

    stack_t *current = *stack;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
