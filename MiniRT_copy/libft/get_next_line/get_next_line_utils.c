/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:09:02 by fabien            #+#    #+#             */
/*   Updated: 2022/12/10 18:43:01 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* reads BUFFER_SIZE elements and adds them to a buffer
returns the value of read() or -1 if issue */
int	list_add(t_Node **head, int fd)
{
	t_Node	*new_node;
	t_Node	*current;
	int		reading;

	new_node = malloc(sizeof(t_Node));
	new_node->buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!new_node || !new_node->buffer)
		return (-1);
	current = *head;
	new_node->next = NULL;
	reading = read(fd, new_node->buffer, BUFFER_SIZE);
	if ((*head == NULL && reading == 0) || reading == -1)
	{
		free(new_node->buffer);
		free(new_node);
		return (-1);
	}
	new_node->buffer[reading] = '\0';
	while (current && current->next)
		current = current->next;
	if (*head == NULL)
		*head = new_node;
	else
		current->next = new_node;
	return (reading);
}

/* returns the length of all the buffers in the linked list */
int	list_len(t_Node **head)
{
	t_Node	*current;
	int		len;
	int		i;

	len = 0;
	current = *head;
	while (current)
	{
		i = 0;
		while (current->buffer[i])
		{
			if (current->buffer[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		current = current->next;
	}
	return (len);
}

/* fills res with contents of buffer in the linked lists until the \n */
void	list_get(t_Node **head, char *line)
{
	t_Node	*current;
	int		i;
	int		j;

	if (*head == NULL)
		return ;
	j = 0;
	current = *head;
	while (current != NULL)
	{
		i = 0;
		while (current->buffer[i] != '\0')
		{
			line[j] = current->buffer[i];
			if (current->buffer[i] == '\n')
				return ;
			i++;
			j++;
		}
		current = current->next;
	}
}

/* frees the linked list entirely */
char	*list_free(t_Node **head, int flag)
{
	t_Node	*current;
	t_Node	*stock;

	stock = *head;
	while (stock != NULL)
	{
		current = stock;
		stock = stock->next;
		free(current->buffer);
		free(current);
	}
	*head = NULL;
	if (flag == 1)
		return (NULL);
	return (NULL);
}

/* returns 1 if \n in buffer, 0 otherwise */
int	enter(t_Node **head)
{
	t_Node	*current;
	int		i;

	i = 0;
	current = *head;
	if (current == NULL)
		return (0);
	while (current->next)
		current = current->next;
	while (current->buffer[i])
	{
		if (current->buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
