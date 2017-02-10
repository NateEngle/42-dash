/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nengle- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:43:32 by nengle-           #+#    #+#             */
/*   Updated: 2017/02/09 14:43:36 by nengle-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
typedef struct s_list
{
	int data;
	struct s_list *next;
} t_list;

#include <stdlib.h>
void		clear_duplicate(t_list *begin)
{
	t_list	*current;
	t_list	*last;

	if (begin == NULL)
		return ;
	while (begin->next != NULL)
	{
		current = begin->next;
		last = begin;
		while (current != NULL)
		{
			if (begin->data == current->data)
			{
				last->next = current->next;
				free(current);
				current = last->next;
			}
			else
				current = current->next;
			last = last->next;
		}
		if (begin->next != NULL)
			begin = begin->next;
	}
}



#include <stdio.h>
int main()
{
	t_list *list;
	t_list *test;
	

	list = malloc(sizeof(t_list));
	list->data = 4;
	list->next = (t_list *)malloc(sizeof(t_list));
	list->next->data = 3;
	list->next->next = malloc(sizeof(t_list));
	list->next->next->data = 4;
	list->next->next->next = malloc(sizeof(t_list));
	list->next->next->next->data = 3;
	list->next->next->next->next = malloc(sizeof(t_list));
	list->next->next->next->next->data = 1;
	list->next->next->next->next->next = malloc(sizeof(t_list));
	list->next->next->next->next->next->data = 1;
	list->next->next->next->next->next->next = NULL;
	test = list;

	clear_duplicate(list);
	while(test != NULL)
	{
		printf("%d\n", test->data);
		test = test->next;
	}
	return (0);

}