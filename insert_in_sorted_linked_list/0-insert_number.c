#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node -  inserts a number into a sorted singly linked list
 * @head: pointer to pointer of first node of listint_t list
 * @n: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */

listint_t *insert_node(listint_t **head, int number)
{
  listint_t *new;
  listint_t *current;
  current = *head;
  new = malloc(sizeof(listint_t));
  if (new == NULL)
    return (NULL);

  new->n = number;
  if (*head == NULL)
    *head = new;
  else
    {
      if (current->next == NULL)
	{
	  current->next = new;
	  new->next = NULL;
	  return new;
	}
      if (number <= current->n)
	{
	  new->next = current;
	  *head = new;
	}
      while (number >= current->n)
	{
	  if (current->next == NULL)
	    {
	      current->next = new;
	      new->next = NULL;
	      return new;
	    }
	  if (number <= current->next->n)
	    {
	      new->next = current->next;
	      current->next = new;
	      return new;
	    }
	  current = current->next;
	}
    }
  return NULL;
}
