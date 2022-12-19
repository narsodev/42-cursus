/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:46:08 by ngonzale          #+#    #+#             */
/*   Updated: 2022/10/18 21:56:04 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ft_move_rotate_reverse(t_stack **stack)
{
	t_stack	*first;
	t_stack	*new_first;
	t_stack	*ptr;

	ptr = *stack;
	first = ptr;
	while (ptr->next->next)
	{
		ptr->position++;
		ptr = ptr->next;
	}
	ptr->position++;
	new_first = ptr->next;
	new_first->position = 1;
	ptr->next = NULL;
	new_first->next = first;
	*stack = new_first;
}

void	ft_move_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*new_first;
	t_stack	*ptr;

	ptr = *stack;
	first = ptr;
	new_first = ptr->next;
	while (ptr->next)
	{
		ptr->position--;
		ptr = ptr->next;
	}
	ptr->position--;
	ptr->next = first;
	first->next = NULL;
	first->position = ptr->position + 1;
	*stack = new_first;
}

void	ft_push(t_stack **src, t_stack **dst)
{
	t_stack	*first_src;
	t_stack	*tmp;

	first_src = *src;
	tmp = first_src->next;
	while (tmp)
	{
		tmp->position--;
		tmp = tmp->next;
	}
	*src = (*src)->next;
	first_src->next = *dst;
	*dst = first_src;
	tmp = (*dst)->next;
	while (tmp)
	{
		tmp->position++;
		tmp = tmp->next;
	}
}

void	ft_swap(t_stack **stack)
{
	t_stack	*first;

	first = *stack;
	first->position = 2;
	*stack = (*stack)->next;
	(*stack)->position = 1;
	first->next = (*stack)->next;
	(*stack)->next = first;
}
