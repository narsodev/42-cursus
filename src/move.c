/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:46:08 by ngonzale          #+#    #+#             */
/*   Updated: 2022/09/29 21:38:59 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_stack	*ft_move_rotate(t_stack *stack)
{
	t_stack	*first;
	t_stack	*new_first;

	first = stack;
	while (stack->next->next)
		stack = stack->next;
	new_first = stack->next;
	stack->next = NULL;
	new_first->next = first;
	return (new_first);
}

t_stack	*ft_move_rotate_reverse(t_stack *stack)
{
	t_stack	*first;
	t_stack	*new_first;

	first = stack;
	new_first = stack->next;
	while (stack->next)
		stack = stack->next;
	stack->next = first;
	first->next = NULL;
	return (new_first);
}
